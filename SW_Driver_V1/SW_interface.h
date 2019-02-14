/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : Switch Interface File            */
/*                1- SWs IDs                      */
/* 				        2- Types of connection macros   */
/*                3- Switches' states macros      */
/*                4- APIs prototypes              */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

/* Comment : SWs' IDs and indices in the array    */
/* Note    : This part may change according to    */
/*           number of LEDs used                  */
/* Note    : Numbers must be from 0 to <number of */
/*           total switches>                      */
#define SW_u8_SW0   (u8)0
#define SW_u8_SW1   (u8)1

/* Comment : Type of connection of SW to the pin  */
#define SW_u8_PULL_UP     (u8)1
#define SW_u8_PULL_DOWN   (u8)0

/* Comment : State of SW                          */
#define SW_u8_PRESSED	    (u8)1
#define SW_u8_RELEASED	  (u8)0

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Initializes the SW         */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void SW_voidInit(void);

/* Get Switch State                               */
/* Description       : get the state of the SW    */
/* Input Argument(s) : SW's ID & Pointer to the   */
/*                     value got from switch      */
/* Return            : Error Status               */
u8 SW_u8GetSwState(u8 Copy_u8SwId, u8* Copy_u8ValuePtr);

#endif
