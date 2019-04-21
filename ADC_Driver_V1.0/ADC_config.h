/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 21 Apr 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : ADC Configuration File           */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC initial state                    */
/* Options : ADC_u8_ADC_ENABLE                    */
/*           ADC_u8_ADC_DISABLE                   */
#define ADC_u8_ADC_INIT_STATE	ADC_u8_ADC_ENABLE

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Voltage reference selection for ADC  */
/* Options : ADC_u8_AREF                          */
/*			 ADC_u8_AVCC						  */
/*           ADC_u8_INTERNAL					  */
#define ADC_u8_VOLTAGE_REF		ADC_u8_INTERNAL

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC result adjustment                */
/* Options : ADC_u8_LEFT_ADJUSTMENT		          */
/*           ADC_u8_RIGHT_ADJUSTMENT		      */
#define ADC_u8_ADJUSTMENT		ADC_u8_LEFT_ADJUSTMENT

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC pre scaler select                */
/* Options : ADC_u8_PRESCALER_2	                  */
/*           ADC_u8_PRESCALER_4                   */
/*           ADC_u8_PRESCALER_8                   */
/*           ADC_u8_PRESCALER_16                  */
/*           ADC_u8_PRESCALER_32                  */
/*           ADC_u8_PRESCALER_64                  */
/*           ADC_u8_PRESCALER_128                 */
#define ADC_u8_PRESCALER		ADC_u8_PRESCALER_8

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Chain conversion configuration       */
#define ADC_u8_ACTIVE_CHANNELS_NUM		(u8)3
u8 ADC_Au8ActiveChannels[ADC_u8_ACTIVE_CHANNELS_NUM]= {ADC_u8_ADC1,
													   ADC_u8_ADC2,
													   ADC_u8_ADC3
														};
//#define ADC_u8_START_CHANNEL			ADC_u8_ADC1
//#define ADC_u8_END_CHANNEL			ADC_u8_ADC3

#endif
