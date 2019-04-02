/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 31 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : Timer Configuration File         */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Initial state of timer0              */
/* Options : TIMER_u8_TIMER0_ENABLE               */
/*           TIMER_u8_TIMER0_DISABLE              */
#define TIMER_u8_TIMER0_INIT_STATE		TIMER_u8_TIMER0_DISABLE

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/

/* Comment : Initial value of pre-load and        */
/*           overflow count                       */
#define TIMER_u8_PRELOAD			(u8)184
#define TIMER_u16_OVERFLOWCOUNT		(u16)489

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : System frequency                     */
/* Options : TIMER_u8_SYS_FREQ_1MB                */
/*           TIMER_u8_SYS_FREQ_8MB                */
/*           TIMER_u8_SYS_FREQ_16MB               */
#define TIMER_u8_SYS_FREQ		TIMER_u8_SYS_FREQ_1MB

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Pre scaler choice                    */
/* Options : TIMER0_u8_NO_CLOCK_SOURCE            */
/*   	     TIMER0_u8_NO_PRESCALING		      */
/*     		 TIMER0_u8_PRESCALER_8                */
/*   		 TIMER0_u8_PRESCALER_64               */
/*  		 TIMER0_u8_PRESCALER_256              */
/*     		 TIMER0_u8_PRESCALER_1024             */
/*     		 TIMER0_u8_EXTCLK_FALLING             */
/*           TIMER0_u8_EXTCLK_RISING              */
#define TIMER0_u8_PRESCALER		TIMER_u8_TIMER0_PRESCALER_8

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Mode of operation                    */
/* Options : TIMER_u8_TIMER0_MODE_NORMAL          */
/*           TIMER_u8_TIMER0_MODE_PWM             */
/*           TIMER_u8_TIMER0_MODE_CTC             */
/*           TIMER_u8_TIMER0_MODE_FASTPWM         */
#define TIMER_u8_TIMER0_MODE		TIMER_u8_TIMER0_MODE_NORMAL

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment: Timer resolution                      */
/* Options : TIMER_u8_RESOLUTION_16               */
/*           TIMER_u8_RESOLUTION_256              */
/*           TIMER_u16_RESOLUTION_1024            */
#define TIMER_u8_TIMER0_RESOLUTION	TIMER_u8_RESOLUTION_256
#endif
