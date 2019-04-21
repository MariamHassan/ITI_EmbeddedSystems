/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 21 Apr 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : ADC Interface File               */
/**************************************************/
/* Preprocessor Guard                             */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : ADC Channels                         */
#define ADC_u8_ADC0		(u8)0
#define ADC_u8_ADC1     (u8)1
#define ADC_u8_ADC2     (u8)2
#define ADC_u8_ADC3     (u8)3
#define ADC_u8_ADC4     (u8)4
#define ADC_u8_ADC5     (u8)5
#define ADC_u8_ADC6     (u8)6
#define ADC_u8_ADC7     (u8)7

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : API's prototypes                     */
/* Init                                           */
/* Description       : Set prescaler, adjustment  */
/*                     type, reference voltage    */
/*                     and enable ADC             */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidInit(void);

/* Enable                                         */
/* Description       : Enable ADC to be ready for */
/*                     conversion                 */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidEnable(void);

/* Disable                                        */
/* Description       : Disable ADC so it wont make*/
/*                     further conversions        */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidDisable(void);

/* Get ADC blocking                               */
/* Description       : Get value of conversion    */
/*                     with polling               */
/* Input Argument(s) : Number of ADC channel      */
/*                     pointer to the value       */
/* Return            : Error Status               */
u8 ADC_u8GetADC_Blocking(u8 Copy_u8ChannelNb, u8* Copy_u8Value);

/* Refresh ADC                                    */
/* Description       : To start a chain conversion*/
/* Input Argument(s) : Void                       */
/* Return            : Error Status               */
u8 ADC_u8RefreshADC(void);

/* Get ADC non blocking                           */
/* Description       : Get value of conversion    */
/*                     with interrupt use         */
/* Input Argument(s) : Number of ADC channel      */
/* Return            : Error Status               */
u8 ADC_u8GetADC_NonBlocking(u8 Copy_u8ChannelNb, u8* Copy_u8Value);

/* Set Call Back                                  */
/* Description       : Pass the function to be    */
/*                     executed to the ISR body of*/
/*                     the timer                  */
/* Input Argument(s) : Pointer to the call back fn*/
/* Return            : Void                       */
void Timer_u8SetCallBack(void (*Copy_PvoidCallBack)(void));


#endif
