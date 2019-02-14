/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : SSD Interface File               */
/*               This file has:                   */
/*                 1- SSDs' IDs                   */
/*                 2- Types of SSDs macros        */
/*                 3- Numbers macros              */
/*                 4- SSDs states                 */
/*                 5- APIs Prototypes             */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SSD_INTERFACE_H                           
#define SSD_INTERFACE_H

/* Comment : SSDs' IDs and indices in the array  */
/* Note    : This part is configurable according  */
/*           to application                       */
#define SSD_u8_SSD0   (u8)0
#define SSD_u8_SSD1   (u8)1

/* Comment : Type of SSD                          */
#define SSD_u8_COMMON_CATHODE   (u8)1
#define SSD_u8_COMMON_ANODE     (u8)0

/* Possible numbers that can be displayed         */
#define NINE  (u8)9
#define EIGHT (u8)8
#define SEVEN (u8)7
#define SIX   (u8)6
#define FIVE  (u8)5
#define FOUR  (u8)4
#define THREE (u8)3
#define TWO   (u8)2
#define ONE   (u8)1
#define ZERO  (u8)0

/* States of SSD                                  */
#define SDD_u8_STATE_ON   (u8)1
#define SDD_u8_STATE_OFF  (u8)0

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Initializes the SSD        */ 
/* Input Argument(s) : void                       */
/* Return            : void                       */
void SSD_voidInit(void);

/* Set SSD On                                     */
/* Description       : Turns the LED on, on the   */
/*                     previous value             */ 
/* Input Argument(s) : SSD ID                     */
/* Return            : Error Status               */
u8 SSD_u8SetOn(u8 Copy_u8SsdId);

/* Set SSD Off                                    */
/* Description       : Turns the SSD off          */ 
/* Input Argument(s) : SSD ID                     */
/* Return            : Error Status               */
u8 SSD_u8SetOff(u8 Copy_u8SsdId);

/* Set value on SSD                               */
/* Description       : Writes a value on SSD      */ 
/* Input Argument(s) : SSD ID and Value           */
/* Return            : Error Status               */
u8 SSD_u8SetValue(u8 Copy_u8SsdId, u8 Copy_u8Value);

#endif
