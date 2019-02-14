/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 12 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : LMD Interface File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LMD_INTERFACE_H
#define LMD_INTERFACE_H

/*Comment : Display color                        */
#define LMD_u8_GREEN   (u8)1
#define LMD_u8_RED     (u8)0

/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Initializes the LMD        */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void LMD_voidInit(void);

/* Display Image                                  */
/* Description       : Display an image on the LMD*/
/* Input Argument(s) : pointer to image array and */
/*                     color of image             */
/* Return            : Error Status               */
u8 LMD_u8LmdDisplay(u8 *Copy_u8LmdImage, u8 Copy_u8LmdColor);

#endif
