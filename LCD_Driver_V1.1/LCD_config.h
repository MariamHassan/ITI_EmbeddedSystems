/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Mar 2019                      */
/* Version     : V1.1                             */
/**************************************************/
/**************************************************/
/* Description : LCD Configuration File           */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Comment : Mode of operation                    */
/* Options : LCD_u8_4BIT_MODE                     */
/*           LCD_u8_8BIT_MODE                     */
#define LCD_u8_MODE 	LCD_u8_8BIT_MODE

/* Comment: Pins attached to LCD                  */
/* Pins attached to control pins of LCD           */
#define LCD_u8_RS   DIO_u8_PIN16 //PB0
#define LCD_u8_RW   DIO_u8_PIN17 //PB1
#define LCD_u8_E    DIO_u8_PIN21 //PB5
/* Pins attached to data pins of LCD              */
#define LCD_u8_D0   DIO_u8_PIN22 //PB6
#define LCD_u8_D1   DIO_u8_PIN23 //PB7
#define LCD_u8_D2   DIO_u8_PIN24 //PB8
#define LCD_u8_D3   DIO_u8_PIN25 //PB9
#define LCD_u8_D4   DIO_u8_PIN26 //PB10
#define LCD_u8_D5   DIO_u8_PIN27 //PB11
#define LCD_u8_D6   DIO_u8_PIN28 //PB12
#define LCD_u8_D7   DIO_u8_PIN29 //PB13


#endif
