/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 20 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : External Interrupts Program File */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "EXTINT_interface.h"
#include "EXTINT_private.h"
#include "EXTINT_config.h"

/* Array of pointers to function that represent   */
/* the ISR to be executed                         */
static void (*PvoidFuncCallBack[3])(void);

/* Init                                           */
/* Description       : Initialize the state and   */
/*                     sense level of each        */
/*                     interrupt                  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void EXTINT_voidInit(void)
{
/* Initialize sense level of external interrupts */
	/*INT0*/
	EXTINT_u8SetSenseLevel(EXTINT_u8_INT0, EXTINT_u8_INT0_INIT_SENSE_LEVEL);

	/*INT1*/
	EXTINT_u8SetSenseLevel(EXTINT_u8_INT1, EXTINT_u8_INT1_INIT_SENSE_LEVEL);

	/*INT2*/
	EXTINT_u8SetSenseLevel(EXTINT_u8_INT2, EXTINT_u8_INT2_INIT_SENSE_LEVEL);

 /* Initialize state of external interrupts */
	/*INT0*/
	if (EXTINT_u8_INT0_INIT_STATE == EXTINT_u8_INT_STATE_ENABLE)
	{
		EXTINT_u8Enable(EXTINT_u8_INT0);
	}
	else if (EXTINT_u8_INT0_INIT_STATE == EXTINT_u8_INT_STATE_DISABLE)
	{
		EXTINT_u8Disable(EXTINT_u8_INT0);
	}

	/*INT1*/
	if (EXTINT_u8_INT1_INIT_STATE == EXTINT_u8_INT_STATE_ENABLE)
	{
		EXTINT_u8Enable(EXTINT_u8_INT1);
	}
	else if (EXTINT_u8_INT1_INIT_STATE == EXTINT_u8_INT_STATE_DISABLE)
	{
		EXTINT_u8Disable(EXTINT_u8_INT1);
	}

	/*INT2*/
	if (EXTINT_u8_INT2_INIT_STATE == EXTINT_u8_INT_STATE_ENABLE)
	{
		EXTINT_u8Enable(EXTINT_u8_INT2);
	}
	else if (EXTINT_u8_INT2_INIT_STATE == EXTINT_u8_INT_STATE_DISABLE)
	{
		EXTINT_u8Disable(EXTINT_u8_INT2);
	}
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Enable                                         */
/* Description       : Activate interrupt         */
/* Input Argument(s) : Number of interrupt        */
/* Return            : Error Status               */
u8 EXTINT_u8Enable(u8 Copy_u8IntNb)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch(Copy_u8IntNb)
	{
	case EXTINT_u8_INT0:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT0_STATE_BIT, EXTINT_ONE);
		break;
	case EXTINT_u8_INT1:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT1_STATE_BIT, EXTINT_ONE);
		break;
	case EXTINT_u8_INT2:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT2_STATE_BIT, EXTINT_ONE);
		break;
	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Disable                                        */
/* Description       : Deactivate interrupt       */
/* Input Argument(s) : Number of interrupt        */
/* Return            : Error Status               */
u8 EXTINT_u8Disable(u8 Copy_u8IntNb)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch(Copy_u8IntNb)
	{
	case EXTINT_u8_INT0:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT0_STATE_BIT, EXTINT_ZERO);
		break;
	case EXTINT_u8_INT1:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT1_STATE_BIT, EXTINT_ZERO);
		break;
	case EXTINT_u8_INT2:
		ASSIGN_BIT(EXTINT_u8_GICR->ByteAccess, EXTINT_INT2_STATE_BIT, EXTINT_ZERO);
		break;
	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Set Sense Level                                */
/* Description       : Set the type of activation */
/*                     control signal of interrupt*/
/* Input Argument(s) : Number of interrupt        */
/*                     Sense level                */
/* Return            : Error Status               */
u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntNb, u8 Copy_u8SenseLevel)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch(Copy_u8IntNb)
	{
	case EXTINT_u8_INT0:
		switch(Copy_u8SenseLevel)
		{
		case EXTINT_u8_INT_SL_LOW_LEVEL:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC01, EXTINT_ZERO);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC00, EXTINT_ZERO);
			break;
		case EXTINT_u8_INT_SL_ON_CHANGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC01, EXTINT_ZERO);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC00, EXTINT_ONE);
			break;
		case EXTINT_u8_INT_SL_FALLING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC01, EXTINT_ONE);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC00, EXTINT_ZERO);
			break;
		case EXTINT_u8_INT_SL_RISING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC01, EXTINT_ONE);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC00, EXTINT_ONE);
			break;
		default:
			Local_u8ErrorStatus = ERROR_NOK;
		}
		break;

	case EXTINT_u8_INT1:
		switch(Copy_u8SenseLevel)
		{
		case EXTINT_u8_INT_SL_LOW_LEVEL:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC11, EXTINT_ZERO);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC10, EXTINT_ZERO);
			break;
		case EXTINT_u8_INT_SL_ON_CHANGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC11, EXTINT_ZERO);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC10, EXTINT_ONE);
			break;
		case EXTINT_u8_INT_SL_FALLING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC11, EXTINT_ONE);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC10, EXTINT_ZERO);
			break;
		case EXTINT_u8_INT_SL_RISING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC11, EXTINT_ONE);
			ASSIGN_BIT(EXTINT_u8_MCUCR->ByteAccess, EXTINT_MCUCR_ISC10, EXTINT_ONE);
			break;
		default:
			Local_u8ErrorStatus = ERROR_NOK;
		}
		break;

	case EXTINT_u8_INT2:
		switch(Copy_u8SenseLevel)
		{
		case EXTINT_u8_INT_SL_FALLING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCSR->ByteAccess, EXTINT_MCUCSR_ISC2, EXTINT_ZERO);
			break;
		case EXTINT_u8_INT_SL_RISING_EDGE:
			ASSIGN_BIT(EXTINT_u8_MCUCSR->ByteAccess, EXTINT_MCUCSR_ISC2, EXTINT_ONE);
			break;
		default:
			Local_u8ErrorStatus = ERROR_NOK;
		}
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Set Call Back                                  */
/* Description       : Set the type of activation */
/*                     control signal of interrupt*/
/* Input Argument(s) : Number of interrupt        */
/*                     Pointer to the call back fn*/
/* Return            : Error Status               */
u8 EXTINT_u8SetCallBack(u8 Copy_u8IntNb, void (*Copy_PvoidCallBack)(void))
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch(Copy_u8IntNb)
	{
	case EXTINT_u8_INT0:
		PvoidFuncCallBack[EXTINT_u8_INT0_PTR] = Copy_PvoidCallBack;
		break;

	case EXTINT_u8_INT1:
		PvoidFuncCallBack[EXTINT_u8_INT1_PTR] = Copy_PvoidCallBack;
		break;

	case EXTINT_u8_INT2:
		PvoidFuncCallBack[EXTINT_u8_INT2_PTR] = Copy_PvoidCallBack;
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* ISR for external interrupt 0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	PvoidFuncCallBack[EXTINT_u8_INT0_PTR]();
}

/* ISR for external interrupt 1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	PvoidFuncCallBack[EXTINT_u8_INT1_PTR]();
}

/* ISR for external interrupt 2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	PvoidFuncCallBack[EXTINT_u8_INT2_PTR]();
}
