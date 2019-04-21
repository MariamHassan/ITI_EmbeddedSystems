/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 21 Apr 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : ADC Private File                 */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Addresses of ADC registers           */
#define ADC_u8_ADMUX		((volatile Register_8Bit*) 0x27)
#define ADC_u8_ADCSRA	    ((volatile Register_8Bit*) 0x26)
#define ADC_u8_ADCH			((volatile Register_8Bit*) 0x25)
#define ADC_u8_ADCL			((volatile Register_8Bit*) 0x24)
#define ADC_u8_SFIOR		((volatile Register_8Bit*) 0x50)

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Voltage reference selection for ADC  */
#define ADC_u8_AREF					(u8)0x00
#define ADC_u8_AVCC					(u8)0x40
#define ADC_u8_INTERNAL				(u8)0xC0

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC result adjustment                */
#define ADC_u8_LEFT_ADJUSTMENT		(u8)0x20
#define ADC_u8_RIGHT_ADJUSTMENT		(u8)0x00

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Analog channel and gain selection    */
#define ADC_u8_CHANNEL_ADC0			(u8)0
#define ADC_u8_CHANNEL_ADC1     	(u8)1
#define ADC_u8_CHANNEL_ADC2     	(u8)2
#define ADC_u8_CHANNEL_ADC3     	(u8)3
#define ADC_u8_CHANNEL_ADC4     	(u8)4
#define ADC_u8_CHANNEL_ADC5     	(u8)5
#define ADC_u8_CHANNEL_ADC6     	(u8)6
#define ADC_u8_CHANNEL_ADC7     	(u8)7

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC pre scaler select                */
#define ADC_u8_PRESCALER_2			(u8)0
//#define ADC_u8_PRESCALER_2        (u8)1
#define ADC_u8_PRESCALER_4          (u8)2
#define ADC_u8_PRESCALER_8          (u8)3
#define ADC_u8_PRESCALER_16         (u8)4
#define ADC_u8_PRESCALER_32         (u8)5
#define ADC_u8_PRESCALER_64         (u8)6
#define ADC_u8_PRESCALER_128        (u8)7

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Enable and disable ADC               */
#define ADC_u8_ADC_ENABLE			(u8)0x80
#define ADC_u8_ADC_DISABLE			(u8)0x00

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment: ADC mode of operation                 */
#define ADC_u8_START_CONV				(u8)0x40

#define ADC_u8_AUTO_TRIGGER_ENABLE		(u8)0x20
#define ADC_u8_AUTO_TRIGGER_DISABLE		(u8)0x00

#define ADC_u8_INTERRUPT_ENABLE			(u8)0x08
#define ADC_u8_INTERRUPT_DISABLE		(u8)0x00

#define ADC_u8_INTP_FLAG_BIT			(u8)4

#endif
