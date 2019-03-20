/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 12 Feb 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : LMD Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef LMD_PRIVATE_H
#define LMD_PRIVATE_H

/* Comment : Value of activation level of LMD     */
#define LMD_u8_ACTIVE_LOW   (u8)0
#define LMD_u8_ACTIVE_HIGH  (u8)255

/* Comment : Value of activation type of LMD      */
#define LMD_u8_ACTIVE_ROW   (u8)0
#define LMD_u8_ACTIVE_COL   (u8)1

/* Comment : Arrays to activate the LMD according */
/*           activation level selected            */
u8 LMD_Au8ActiveLowLmd[8]={~1,~24,~8,~16,~32,~64,~128};
u8 LMD_Au8ActiveHighLmd[8]={1,24,8,16,32,64,128};

#endif
