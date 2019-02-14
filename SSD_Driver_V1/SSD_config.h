/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : SSD Configuration File           */
/*               This file has:                   */
/*               	1- Pins attached to the SSD   */
/*                  2- Number of SSDs             */
/*                  3- SSDs array                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H

/* Comment : Possible pins to attach the SSDS to  */
/* Note    : The same SSD doesn't have to be      */
/*           attached to the same port            */
#define SSD_u8_A0    DIO_u8_PIN0
#define SSD_u8_B0    DIO_u8_PIN1
#define SSD_u8_C0    DIO_u8_PIN2
#define SSD_u8_D0    DIO_u8_PIN3
#define SSD_u8_E0    DIO_u8_PIN4
#define SSD_u8_F0    DIO_u8_PIN5
#define SSD_u8_G0    DIO_u8_PIN6
#define SSD_u8_EN0   DIO_u8_PIN7

#define SSD_u8_A1    DIO_u8_PIN8
#define SSD_u8_B1    DIO_u8_PIN9
#define SSD_u8_C1    DIO_u8_PIN10
#define SSD_u8_D1    DIO_u8_PIN11
#define SSD_u8_E1    DIO_u8_PIN12
#define SSD_u8_F1    DIO_u8_PIN13
#define SSD_u8_G1    DIO_u8_PIN14
#define SSD_u8_EN1   DIO_u8_PIN15

#define SSD_u8_A2    DIO_u8_PIN16
#define SSD_u8_B2    DIO_u8_PIN17
#define SSD_u8_C2    DIO_u8_PIN18
#define SSD_u8_D2    DIO_u8_PIN19
#define SSD_u8_E2    DIO_u8_PIN20
#define SSD_u8_F2    DIO_u8_PIN21
#define SSD_u8_G2    DIO_u8_PIN22
#define SSD_u8_EN2   DIO_u8_PIN23

#define SSD_u8_A3    DIO_u8_PIN24
#define SSD_u8_B3    DIO_u8_PIN25
#define SSD_u8_C3    DIO_u8_PIN26
#define SSD_u8_D3    DIO_u8_PIN27
#define SSD_u8_E3    DIO_u8_PIN28
#define SSD_u8_F3    DIO_u8_PIN29
#define SSD_u8_G3    DIO_u8_PIN30
#define SSD_u8_EN3   DIO_u8_PIN31


/* Comment : Enable multi configuration           */
/* Note    : This part is configurable according  */
/*           to application                       */
#define SSD_u8_NUMB_OF_SSDS   (u8)2

/*Comment : Array of the attached SSDs            */
/* Note    : This part is configurable according  */
/*           to application                       */
u8 SSD_Au8SsdArray[SSD_u8_NUMB_OF_SSDS][SSD_u8_NUM_OF_PARAM]={
  {SSD_u8_A0,SSD_u8_B0,SSD_u8_C0,SSD_u8_D0,SSD_u8_E0,SSD_u8_F0,SSD_u8_G0,SSD_u8_EN0,SSD_u8_COMMON_CATHODE},
  {SSD_u8_A1,SSD_u8_B1,SSD_u8_C1,SSD_u8_D1,SSD_u8_E1,SSD_u8_F1,SSD_u8_G1,SSD_u8_EN1,SSD_u8_COMMON_ANODE}
};

#endif
