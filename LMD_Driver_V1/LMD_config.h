/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 12 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LMD Configuration File           */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LMD_CONFIG_H
#define LMD_CONFIG_H

/* Comment : Possible pins to attach the LMD to  */
/* Note    : You need three ports. Here, port A,B*/
/* 			 and D are used.                     */
#define LMD_u8_ACTIVE0         DIO_u8_PIN0
#define LMD_u8_ACTIVE1         DIO_u8_PIN1
#define LMD_u8_ACTIVE2         DIO_u8_PIN2
#define LMD_u8_ACTIVE3         DIO_u8_PIN3
#define LMD_u8_ACTIVE4         DIO_u8_PIN4
#define LMD_u8_ACTIVE5         DIO_u8_PIN5
#define LMD_u8_ACTIVE6         DIO_u8_PIN6
#define LMD_u8_ACTIVE7         DIO_u8_PIN7

#define LMD_u8_GREEN0   DIO_u8_PIN8
#define LMD_u8_GREEN1   DIO_u8_PIN9
#define LMD_u8_GREEN2   DIO_u8_PIN10
#define LMD_u8_GREEN3   DIO_u8_PIN11
#define LMD_u8_GREEN4   DIO_u8_PIN12
#define LMD_u8_GREEN5   DIO_u8_PIN13
#define LMD_u8_GREEN6   DIO_u8_PIN14
#define LMD_u8_GREEN7   DIO_u8_PIN15

#define LMD_u8_RED0     DIO_u8_PIN24
#define LMD_u8_RED1     DIO_u8_PIN25
#define LMD_u8_RED2     DIO_u8_PIN26
#define LMD_u8_RED3     DIO_u8_PIN27
#define LMD_u8_RED4     DIO_u8_PIN28
#define LMD_u8_RED5     DIO_u8_PIN29
#define LMD_u8_RED6     DIO_u8_PIN30
#define LMD_u8_RED7     DIO_u8_PIN31

#define LMD_u8_ACTIVE_PORT   DIO_u8_PORT0
#define LMD_u8_GREEN_PORT    DIO_u8_PORT1
#define LMD_u8_RED_PORT      DIO_u8_PORT3


/* Comment : Activation type of LMD              */
/* Range   : LMD_u8_ACTIVE_ROW                   */
/* 		     LMD_u8_ACTIVE_COL				     */
#define LMD_u8_ACTIVE_TYPE   LMD_u8_ACTIVE_ROW
//#define LMD_u8_ACTIVE_TYPE   LMD_u8_ACTIVE_COL

/* Comment : Activation level                    */
/* Range   : LMD_u8_ACTIVE_LOW                   */
/* 		     LMD_u8_ACTIVE_HIGH				     */
#define LMD_u8_ACTIVE_LEVEL  LMD_u8_ACTIVE_LOW
//#define LMD_u8_ACTIVE_LEVEL  LMD_u8_ACTIVE_HIGH

#endif
