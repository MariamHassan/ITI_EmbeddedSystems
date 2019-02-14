/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LED Interface File               */
/*                1- LEDs IDs                     */
/*                2- Types of connection macros   */
/*                3- APIs prototypes              */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LED_INTERFACE_H                           
#define LED_INTERFACE_H

/* Comment : LED's ID's and indices in the array  */
/* Note    : This part may change according to    */
/*           number of LEDs used                  */
#define LED_u8_LED0   (u8)0
#define LED_u8_LED1   (u8)1
#define LED_u8_LED2   (u8)2

/* Comment : Type of connection of LED to the pin */
#define LED_u8_CONNECTION_FORWARD   (u8)1
#define LED_u8_CONNECTION_REVERSE   (u8)0

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Initializes the LED        */ 
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LED_voidInit(void);

/* Turn LED On                                    */
/* Description       : Turns the LED on           */ 
/* Input Argument(s) : LED ID                     */
/* Return            : Error Status               */
u8 LED_u8LedOn(u8 Copy_u8LedId);

/* Turn LED Off                                   */
/* Description       : Turns the LED off          */ 
/* Input Argument(s) : LED ID                     */
/* Return            : Error Status               */
u8 LED_u8LedOff(u8 Copy_u8LedId);

#endif                 
