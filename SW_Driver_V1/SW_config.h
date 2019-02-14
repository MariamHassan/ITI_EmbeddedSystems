/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : Switch Configuration File        */
/*               This file describes the number of*/
/*               switches in the system and the   */
/*               possible DIO pins they can be    */
/*               attached to.                     */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_

/* Comment : Possible pins to attach the SWs to   */
#define SW_u8_CH0    DIO_u8_PIN0
#define SW_u8_CH1    DIO_u8_PIN1
#define SW_u8_CH2    DIO_u8_PIN2
#define SW_u8_CH3    DIO_u8_PIN3
#define SW_u8_CH4    DIO_u8_PIN4
#define SW_u8_CH5    DIO_u8_PIN5
#define SW_u8_CH6    DIO_u8_PIN6
#define SW_u8_CH7    DIO_u8_PIN7

#define SW_u8_CH8    DIO_u8_PIN8
#define SW_u8_CH9    DIO_u8_PIN9
#define SW_u8_CH10   DIO_u8_PIN10
#define SW_u8_CH11   DIO_u8_PIN11
#define SW_u8_CH12   DIO_u8_PIN12
#define SW_u8_CH13   DIO_u8_PIN13
#define SW_u8_CH14   DIO_u8_PIN14
#define SW_u8_CH15   DIO_u8_PIN15

#define SW_u8_CH16   DIO_u8_PIN16
#define SW_u8_CH17   DIO_u8_PIN17
#define SW_u8_CH18   DIO_u8_PIN18
#define SW_u8_CH19   DIO_u8_PIN19
#define SW_u8_CH20   DIO_u8_PIN20
#define SW_u8_CH21   DIO_u8_PIN21
#define SW_u8_CH22   DIO_u8_PIN22
#define SW_u8_CH23   DIO_u8_PIN23

#define SW_u8_CH24   DIO_u8_PIN24
#define SW_u8_CH25   DIO_u8_PIN25
#define SW_u8_CH26   DIO_u8_PIN26
#define SW_u8_CH27   DIO_u8_PIN27
#define SW_u8_CH28   DIO_u8_PIN28
#define SW_u8_CH29   DIO_u8_PIN29
#define SW_u8_CH30   DIO_u8_PIN30
#define SW_u8_CH31   DIO_u8_PIN31

/* Comment : Enable multi configuration           */
/* Note    : This part is configurable according  */
/*           to application                       */
#define SW_u8_NUMB_OF_SWS      (u8)2

/* Comment : Array of the attached switches       */
/* Note    : This part is configurable according  */
/*           to application                       */
/* Note    : Rows represent the parameters of one */
/*           switch, and columns represent these  */
/*           parameters which are the pin number  */
/*           and type of connection               */
u8 SW_Au8SwArray[SW_u8_NUMB_OF_SWS][SW_u8_NUM_OF_PARAM]={
    {SW_u8_CH0, SW_u8_PULL_UP},
    {SW_u8_CH1, SW_u8_PULL_DOWN}
    };

#endif
