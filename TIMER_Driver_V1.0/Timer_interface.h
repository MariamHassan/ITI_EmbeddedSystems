/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 31 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : Timer Interface File             */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Numbers of timers                   */
#define TIMER_u8_TIMER0				  (u8)0
#define TIMER_u8_TIMER1				  (u8)1
#define TIMER_u8_TIMER2				  (u8)2

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : API's prototypes                     */
/* Init                                           */
/* Description       : Enable or disable timers   */
/*                     according to configurations*/
/*                     and sets pre-scaler value  */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void TIMER_voidInit(void);

/* Enable                                         */
/* Description       : Activate a timer           */
/* Input Argument(s) : Number of timer            */
/* Return            : Error Status               */
u8 TIMER_u8Enable(u8 Copy_u8TimerNb);

/* Disable                                        */
/* Description       : Deactivate a timer         */
/* Input Argument(s) : Number of timer            */
/* Return            : Error Status               */
u8 TIMER_u8Disable(u8 Copy_u8TimerNb);

/* Set Call Back                                  */
/* Description       : Pass the function to be    */
/*                     executed to the ISR body of*/
/*                     the timer                  */
/* Input Argument(s) : Number of timer            */
/*                     Pointer to the call back fn*/
/* Return            : Error Status               */
u8 Timer_u8SetCallBack(u8 Copy_u8TimerNb, void (*Copy_PvoidCallBack)(void));


#endif
