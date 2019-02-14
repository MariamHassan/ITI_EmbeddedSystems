/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : SSD Private File                 */
/*               This file describes the main     */
/*               parameters of SSDs and how to    */
/*               make look up tables for both SSD */
/*               types to display numbers         */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SSD_PRIVATE_H
#define SSD_PRIVATE_H


/* Comment : Number of parameters of an SSD       */
/*           Parameters are the display segments  */
/*           and  type of SSD                     */
/* Note    : These numbers are the indices of the */
/*           SSDs' array      					  */
#define SSD_u8_NUM_OF_PARAM        (u8)9

#define SSD_u8_A_SEGMENT_PIN       (u8)0
#define SSD_u8_B_SEGMENT_PIN       (u8)1
#define SSD_u8_C_SEGMENT_PIN       (u8)2
#define SSD_u8_D_SEGMENT_PIN       (u8)3
#define SSD_u8_E_SEGMENT_PIN       (u8)4
#define SSD_u8_F_SEGMENT_PIN       (u8)5
#define SSD_u8_G_SEGMENT_PIN       (u8)6
#define SSD_u8_EN_SEGMENT_PIN      (u8)7

#define SSD_u8_TYPE                (u8)8

/* Comment : Values to enable the SSD according   */
/*           to the type of SSD                   */
#define SSD_u8_COMMON_CATHODE_EN   (u8)0
#define SSD_u8_COMMON_CATHODE_DIS  (u8)1
#define SSD_u8_COMMON_ANODE_EN     (u8)1
#define SSD_u8_COMMON_ANODE_DIS    (u8)0

/* Comment : Number of segments and values applied*/
/*           on them to operate properly          */
#define SSD_u8_NUMB_SEGMENTS   (u8)7

#define SSD_u8_COMMON_CATHODE_SEGEMNT_ON   DIO_u8_PIN_HIGH
#define SSD_u8_COMMON_CATHODE_SEGEMNT_OFF  DIO_u8_PIN_LOW
#define SSD_u8_COMMON_ANODE_SEGEMNT_ON     DIO_u8_PIN_LOW
#define SSD_u8_COMMON_ANODE_SEGEMNT_OFF    DIO_u8_PIN_HIGH

/* Comment : Indices of the look up tables        */
#define SSD_u8_A_SEGMENT_VALUE   (u8)0
#define SSD_u8_B_SEGMENT_VALUE   (u8)1
#define SSD_u8_C_SEGMENT_VALUE   (u8)2
#define SSD_u8_D_SEGMENT_VALUE   (u8)3
#define SSD_u8_E_SEGMENT_VALUE   (u8)4
#define SSD_u8_F_SEGMENT_VALUE   (u8)5
#define SSD_u8_G_SEGMENT_VALUE   (u8)6

/* Comment : Look up table for common cathode SSD  */
/* Note    : Sequence of segments in the array     */
/*           starts from a down to g               */
u8 SSD_Au8CommonCathodeNum9[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON};
                                                     
u8 SSD_Au8CommonCathodeNum8[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON}; 

u8 SSD_Au8CommonCathodeNum7[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF};

u8 SSD_Au8CommonCathodeNum6[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON}; 

u8 SSD_Au8CommonCathodeNum5[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON};

u8 SSD_Au8CommonCathodeNum4[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON};

u8 SSD_Au8CommonCathodeNum3[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON};

u8 SSD_Au8CommonCathodeNum2[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON};

u8 SSD_Au8CommonCathodeNum1[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF};

u8 SSD_Au8CommonCathodeNum0[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_ON,
                                                     SSD_u8_COMMON_CATHODE_SEGEMNT_OFF};


/* Comment : Look up table for common anode SSD  */
/* Note    : Sequence of segments in the array   */
/*           starts from a down to g             */
u8 SSD_Au8CommonAnodeNum9[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum8[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum7[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON};

u8 SSD_Au8CommonAnodeNum6[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum5[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum4[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum3[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum2[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF};

u8 SSD_Au8CommonAnodeNum1[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON};

u8 SSD_Au8CommonAnodeNum0[SSD_u8_NUMB_SEGMENTS] = {SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_OFF,
                                                   SSD_u8_COMMON_ANODE_SEGEMNT_ON};

#endif
