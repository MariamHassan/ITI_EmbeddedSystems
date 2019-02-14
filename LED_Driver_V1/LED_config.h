/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LED Configuration File           */
/*               This file describes the number of*/
/*               LEDs in the system and the       */
/*               possible DIO pins they can be    */
/*               attached to.                     */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/* Comment : Possible pins to attach the LEDS to  */ 
#define LED_u8_CH0    DIO_u8_PIN0
#define LED_u8_CH1    DIO_u8_PIN1
#define LED_u8_CH2    DIO_u8_PIN2
#define LED_u8_CH3    DIO_u8_PIN3
#define LED_u8_CH4    DIO_u8_PIN4
#define LED_u8_CH5    DIO_u8_PIN5
#define LED_u8_CH6    DIO_u8_PIN6
#define LED_u8_CH7    DIO_u8_PIN7

#define LED_u8_CH8    DIO_u8_PIN8
#define LED_u8_CH9    DIO_u8_PIN9
#define LED_u8_CH10   DIO_u8_PIN10
#define LED_u8_CH11   DIO_u8_PIN11
#define LED_u8_CH12   DIO_u8_PIN12
#define LED_u8_CH13   DIO_u8_PIN13
#define LED_u8_CH14   DIO_u8_PIN14
#define LED_u8_CH15   DIO_u8_PIN15

#define LED_u8_CH16   DIO_u8_PIN16
#define LED_u8_CH17   DIO_u8_PIN17
#define LED_u8_CH18   DIO_u8_PIN18
#define LED_u8_CH19   DIO_u8_PIN19
#define LED_u8_CH20   DIO_u8_PIN20
#define LED_u8_CH21   DIO_u8_PIN21
#define LED_u8_CH22   DIO_u8_PIN22
#define LED_u8_CH23   DIO_u8_PIN23

#define LED_u8_CH24   DIO_u8_PIN24
#define LED_u8_CH25   DIO_u8_PIN25
#define LED_u8_CH26   DIO_u8_PIN26
#define LED_u8_CH27   DIO_u8_PIN27
#define LED_u8_CH28   DIO_u8_PIN28
#define LED_u8_CH29   DIO_u8_PIN29
#define LED_u8_CH30   DIO_u8_PIN30
#define LED_u8_CH31   DIO_u8_PIN31

/* Comment : Enable multi configuration           */
/* Note    : This part is configurable according  */
/*           to application                       */
#define LED_u8_NUMB_OF_LEDS    (u8)3

/*Comment : Array of the attached LEDs            */
/* Note    : This part is configurable according  */
/*           to application                       */
u8 LED_Au8LedArray[LED_u8_NUMB_OF_LEDS][LED_u8_NUM_OF_PARAM]={
    {LED_u8_CH0, LED_u8_CONNECTION_FORWARD},
    {LED_u8_CH1, LED_u8_CONNECTION_REVERSE},
    {LED_u8_CH2, LED_u8_CONNECTION_FORWARD}
    };

#endif
