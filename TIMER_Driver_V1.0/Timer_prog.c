/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 31 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : Timer Program File               */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "Timer_config.h"
#include "Timer_interface.h"
#include "Timer_private.h"

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Global variables deceleration        */
u8  TIMER_u8Preload;
u16 TIMER_u16Counter;
u16 TIMER_u16OverFlowCount;

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment :Array of pointers to function that    */
/*          represent the ISR to be executed      */
static void (*PvoidFuncCallBack[3])(void);

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : API's prototypes                     */
/* Init                                           */
/* Description       : Enable or disable timers   */
/*                     according to configurations*/
/*                     and sets pre-scaler value  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void TIMER_voidInit(void)
{
	/* Timer0 */
	TIMER_u8Preload = TIMER_u8_PRELOAD;
	TIMER_u16Counter = 0;
	TIMER_u16OverFlowCount = TIMER_u16_OVERFLOWCOUNT;
	TIMER_u8_TIMER0_TCNT0 -> ByteAccess = TIMER_u8Preload;
	TIMER_u8_TIMER0_TCCR0 -> ByteAccess = TIMER_u8_TIMER0_PRESCALER_8;
	TIMER_u8_TIMER0_TIMSK -> ByteAccess = TIMER_u8_TIMER0_INIT_STATE;

	/* Timer1 */


	/* Timer2 */
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Enable                                         */
/* Description       : Activate a timer           */
/* Input Argument(s) : Number of timer            */
/* Return            : Error Status               */
u8 TIMER_u8Enable(u8 Copy_u8TimerNb)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch (Copy_u8TimerNb)
	{
	case TIMER_u8_TIMER0:
		TIMER_u8_TIMER0_TIMSK -> ByteAccess = TIMER_u8_TIMER0_ENABLE;
		break;

	case TIMER_u8_TIMER1:
		break;

	case TIMER_u8_TIMER2:
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Disable                                        */
/* Description       : Deactivate a timer         */
/* Input Argument(s) : Number of timer            */
/* Return            : Error Status               */
u8 TIMER_u8Disable(u8 Copy_u8TimerNb)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	switch (Copy_u8TimerNb)
	{
	case TIMER_u8_TIMER0:
		TIMER_u8_TIMER0_TIMSK -> ByteAccess = TIMER_u8_TIMER0_DISABLE;
		break;

	case TIMER_u8_TIMER1:
		break;

	case TIMER_u8_TIMER2:
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Set Call Back                                  */
/* Description       : Pass the function to be    */
/*                     executed to the ISR body of*/
/*                     the timer                  */
/* Input Argument(s) : Number of timer            */
/*                     Pointer to the call back fn*/
/* Return            : Error Status               */
u8 Timer_u8SetCallBack(u8 Copy_u8TimerNb, void (*Copy_PvoidCallBack)(void))
{
	u8 Local_u8ErrorStatus=ERROR_OK;

	switch(Copy_u8TimerNb)
	{
	case TIMER_u8_TIMER0:
		PvoidFuncCallBack[TIMER_u8_TIMER0_PTR] = Copy_PvoidCallBack;
		break;

	case TIMER_u8_TIMER1:
		PvoidFuncCallBack[TIMER_u8_TIMER1_PTR] = Copy_PvoidCallBack;
		break;

	case TIMER_u8_TIMER2:
		PvoidFuncCallBack[TIMER_u8_TIMER2_PTR] = Copy_PvoidCallBack;
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}
	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	/* To indicate that the interrupt has been fired */
	DIO_u8SetPinValue(DIO_u8_PIN0, DIO_u8_PIN_HIGH);

	TIMER_u16Counter++;

	if (TIMER_u16Counter == TIMER_u16OverFlowCount)
	{
		TIMER_u16Counter = 0;
		TIMER_u8_TIMER0_TCNT0 -> ByteAccess = TIMER_u8Preload;

		/* Action */
		PvoidFuncCallBack[TIMER_u8_TIMER0_PTR]();
	}
}
