/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LED Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

/* Comment : Number of parameters of an LED       */
/*           Parameters are pin number & type     */
/* Note    : These numbers are the indices of the */
/*           switches' array                      */
#define LED_u8_NUM_OF_PARAM    (u8)2
#define LED_u8_PIN_NUMBER      (u8)0
#define LED_u8_CONNECTION_TYPE (u8)1

/* Comment : Values to turn the LED on or off     */
/*           according to the type of connection  */
#define LED_u8_FORWARD_ON           (u8)1
#define LED_u8_FORWARD_OFF          (u8)0
#define LED_u8_REVERSE_ON           (u8)0
#define LED_u8_REVERSE_OFF          (u8)1

#endif
