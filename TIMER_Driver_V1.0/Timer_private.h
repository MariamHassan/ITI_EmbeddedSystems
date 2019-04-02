/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 31 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : Timer Private File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : The addresses of timer0 registers    */
#define	TIMER_u8_TIMER0_TCNT0   ((Register_8Bit*) 0x52)
#define TIMER_u8_TIMER0_TIMSK   ((Register_8Bit*) 0x59)
#define TIMER_u8_TIMER0_TCCR0   ((Register_8Bit*) 0x53)

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Pre-scaler options for timer0        */
#define TIMER_u8_TIMER0_NO_CLOCK_SOURCE	  (u8)0x00
#define TIMER_u8_TIMER0_PRESCALER_8       (u8)0x02
#define TIMER_u8_TIMER0_PRESCALER_64      (u8)0x03
#define TIMER_u8_TIMER0_NO_PRESCALING	  (u8)0x01
#define TIMER_u8_TIMER0_PRESCALER_256     (u8)0x04
#define TIMER_u8_TIMER0_PRESCALER_1024    (u8)0x05
#define TIMER_u8_TIMER0_EXTCLK_FALLING    (u8)0x06
#define TIMER_u8_TIMER0_EXTCLK_RISING     (u8)0x07

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Mode of operation of timer0          */
#define TIMER_u8_TIMER0_MODE_NORMAL	    (u8)1
#define TIMER_u8_TIMER0_MODE_PWM		(u8)2
#define TIMER_u8_TIMER0_MODE_CTC		(u8)3
#define TIMER_u8_TIMER0_MODE_FASTPWM	(u8)4

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : State of timer0                      */
#define TIMER_u8_TIMER0_ENABLE		    (u8)1
#define TIMER_u8_TIMER0_DISABLE		    (u8)0

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Indexes of the pointers to function  */
/*           array                                */
#define TIMER_u8_TIMER0_PTR				(u8)0
#define TIMER_u8_TIMER1_PTR				(u8)1
#define TIMER_u8_TIMER2_PTR				(u8)2

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : System frequency values              */
#define TIMER_u8_SYS_FREQ_1MB	(u8)1
#define TIMER_u8_SYS_FREQ_8MB	(u8)8
#define TIMER_u8_SYS_FREQ_16MB	(u8)16

/* Comment: Timer resolution                      */
#define TIMER_u8_RESOLUTION_16		(u8)16
#define TIMER_u8_RESOLUTION_256		(u8)256
#define TIMER_u16_RESOLUTION_1024	(u16)1024
#endif
