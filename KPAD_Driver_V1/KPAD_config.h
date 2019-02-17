/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 16 Feb 2019                      */
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : KPAD Configuration File          */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H


/* Comment : Possible pins to attach the KPAD to */
#define KPAD_u8_ID0_ROW1   DIO_u8_PIN0
#define KPAD_u8_ID0_ROW2   DIO_u8_PIN1
#define KPAD_u8_ID0_ROW3   DIO_u8_PIN2
#define KPAD_u8_ID0_ROW4   DIO_u8_PIN3
#define KPAD_u8_ID0_COL1   DIO_u8_PIN4
#define KPAD_u8_ID0_COL2   DIO_u8_PIN5
#define KPAD_u8_ID0_COL3   DIO_u8_PIN6
#define KPAD_u8_ID0_COL4   DIO_u8_PIN7

#define KPAD_u8_ID1_ROW1   DIO_u8_PIN8
#define KPAD_u8_ID1_ROW2   DIO_u8_PIN9
#define KPAD_u8_ID1_ROW3   DIO_u8_PIN10
#define KPAD_u8_ID1_ROW4   DIO_u8_PIN11
#define KPAD_u8_ID1_COL1   DIO_u8_PIN12
#define KPAD_u8_ID1_COL2   DIO_u8_PIN13
#define KPAD_u8_ID1_COL3   DIO_u8_PIN14
#define KPAD_u8_ID1_COL4   DIO_u8_PIN15

#define KPAD_u8_ID2_ROW1   DIO_u8_PIN16
#define KPAD_u8_ID2_ROW2   DIO_u8_PIN17
#define KPAD_u8_ID2_ROW3   DIO_u8_PIN18
#define KPAD_u8_ID2_ROW4   DIO_u8_PIN19
#define KPAD_u8_ID2_COL1   DIO_u8_PIN20
#define KPAD_u8_ID2_COL2   DIO_u8_PIN21
#define KPAD_u8_ID2_COL3   DIO_u8_PIN22
#define KPAD_u8_ID2_COL4   DIO_u8_PIN23

#define KPAD_u8_ID3_ROW1   DIO_u8_PIN24
#define KPAD_u8_ID3_ROW2   DIO_u8_PIN25
#define KPAD_u8_ID3_ROW3   DIO_u8_PIN26
#define KPAD_u8_ID3_ROW4   DIO_u8_PIN27
#define KPAD_u8_ID3_COL1   DIO_u8_PIN28
#define KPAD_u8_ID3_COL2   DIO_u8_PIN29
#define KPAD_u8_ID3_COL3   DIO_u8_PIN30
#define KPAD_u8_ID3_COL4   DIO_u8_PIN31

/* Comment : Input Connection                    */
/* Range   : KPAD_u8_PULL_UP                     */
/* 		     KPAD_u8_PULL_DOWN      			 */
#define KPAD_u8_Input_Connection  KPAD_u8_PULL_UP
//#define KPAD_u8_Input_Connection  KPAD_u8_PULL_DOWN

/* Comment : Number of rows and columns         */
#define KPAD_u8_NUM_ROWS    (u8)3
#define KPAD_u8_NUM_COLS    (u8)3

/* Comment : Arrays to hold pins of the rows and*/
/*           columns                            */
u8 KPAD_Au8Rows[KPAD_u8_NUM_ROWS]= {KPAD_u8_ID0_ROW1,
                                    KPAD_u8_ID0_ROW2,
                                    KPAD_u8_ID0_ROW3};
                                    
u8 KPAD_Au8Cols[KPAD_u8_NUM_COLS]= {KPAD_u8_ID0_COL1,
                                    KPAD_u8_ID0_COL2,
                                    KPAD_u8_ID0_COL3};                                  
                                    
#endif
