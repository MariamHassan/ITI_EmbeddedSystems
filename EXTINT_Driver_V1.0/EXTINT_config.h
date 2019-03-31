/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 20 Mar 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : External Interrupts Configuration*/
/*               File                             */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef EXTINT_CONFIG_H
#define EXTINT_CONFIG_H

/* Comment : Initial state of interrupts          */
/* Options : EXTINT_u8_INT_STATE_ENABLE           */
/*           EXTINT_u8_INT_STATE_DISABLE          */
#define EXTINT_u8_INT0_INIT_STATE	     EXTINT_u8_INT_STATE_ENABLE
#define EXTINT_u8_INT1_INIT_STATE	     EXTINT_u8_INT_STATE_DISABLE
#define EXTINT_u8_INT2_INIT_STATE	     EXTINT_u8_INT_STATE_DISABLE

/* Comment : Initial sense level of interrupts     */
/* Options : External interrupt 0 & 1              */
/*            1- EXTINT_u8_INT_SL_LOW_LEVEL        */
/*            2- EXTINT_u8_INT_SL_ON_CHANGE        */
/*            3- EXTINT_u8_INT_SL_FALLING_EDGE     */
/*            4- EXTINT_u8_INT_SL_RISING_EDGE      */
/*           External interrupt 2                  */
/*            1- EXTINT_u8_INT_SL_FALLING_EDGE     */
/*            2- EXTINT_u8_INT_SL_RISING_EDGE      */
#define EXTINT_u8_INT0_INIT_SENSE_LEVEL  EXTINT_u8_INT_SL_LOW_LEVEL
#define EXTINT_u8_INT1_INIT_SENSE_LEVEL  EXTINT_u8_INT_SL_LOW_LEVEL
#define EXTINT_u8_INT2_INIT_SENSE_LEVEL  EXTINT_u8_INT_SL_FALLING_EDGE

#endif
