/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 20 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : External Interrupts Interface    */
/*               File                             */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef EXTINT_INTERFACE_H
#define EXTINT_INTERFACE_H

/* Comment : Numbers of interrupts                */
#define EXTINT_u8_INT0				  (u8)0
#define EXTINT_u8_INT1				  (u8)1
#define EXTINT_u8_INT2				  (u8)2
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : State of interrupts                  */
#define EXTINT_u8_INT_STATE_ENABLE	  (u8)1
#define EXTINT_u8_INT_STATE_DISABLE	  (u8)0
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Sense level of interrupts            */
#define EXTINT_u8_INT_SL_LOW_LEVEL		(u8)0
#define EXTINT_u8_INT_SL_ON_CHANGE		(u8)1
#define EXTINT_u8_INT_SL_FALLING_EDGE   (u8)2
#define EXTINT_u8_INT_SL_RISING_EDGE    (u8)3
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : API's prototypes                     */
/* Init                                           */
/* Description       : Initialize the state and   */
/*                     sense level of each        */
/*                     interrupt                  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void EXTINT_voidInit(void);

/* Enable                                         */
/* Description       : Activate interrupt         */
/* Input Argument(s) : Number of interrupt        */
/* Return            : Error Status               */
u8 EXTINT_u8Enable(u8 Copy_u8IntNb);

/* Disable                                        */
/* Description       : Deactivate interrupt       */
/* Input Argument(s) : Number of interrupt        */
/* Return            : Error Status               */
u8 EXTINT_u8Disable(u8 Copy_u8IntNb);

/* Set Sense Level                                */
/* Description       : Set the type of activation */
/*                     control signal of interrupt*/
/* Input Argument(s) : Number of interrupt        */
/*                     Sense level                */
/* Return            : Error Status               */
u8 EXTINT_u8SetSenseLevel(u8 Copy_u8IntNb, u8 Copy_u8SenseLevel);

/* Set Call Back                                  */
/* Description       : Set the type of activation */
/*                     control signal of interrupt*/
/* Input Argument(s) : Number of interrupt        */
/*                     Pointer to the call back fn*/
/* Return            : Error Status               */
u8 EXTINT_u8SetCallBack(u8 Copy_u8IntNb, void (*Copy_PvoidCallBack)(void));

#endif
