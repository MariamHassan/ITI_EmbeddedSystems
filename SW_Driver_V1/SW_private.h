/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : Switch Private File              */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SW_PRIVATE_H
#define SW_PRIVATE_H

/* Comment : Number of parameters of a switch.    */
/*           Parameters are pin number & type     */
/* Note    : These numbers are the indices of the */
/*           switches' array                      */
#define SW_u8_NUM_OF_PARAM    (u8)2
#define SW_u8_PIN_NUMBER      (u8)0
#define SW_u8_CONNECTION_TYPE (u8)1

/* Comment : State of SW by type                  */
#define SW_u8_PULL_UP_PRESSED	    (u8)0
#define SW_u8_PULL_UP_RELEASED	  (u8)1
#define SW_u8_PULL_DOWN_PRESSED	  (u8)1
#define SW_u8_PULL_DOWN_RELEASED	(u8)0

#endif
