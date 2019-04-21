/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 21 Apr 2019                      */
/* Version     : V1.0                             */
/**************************************************/
/**************************************************/
/* Description : ADC Program File                 */
/**************************************************/

/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Comment : Array to store the converted values  */
u8 ADC_Au8ConvValues[ADC_u8_ACTIVE_CHANNELS_NUM];

/* Comment : A flag to indicate which channel to  */
/*           start conversion                     */
u8 ADC_u8ChannelFlag = 0 ;

/* Comment : A pointer to function to store the   */
/*           call back function and call it in ISR*/
static void (*PvoidFuncCallBack)(void);

/* Comment : A flag to indicate that chain of     */
/*           conversion is done before executing  */
/*           another one                          */
u8 ADC_u8ConvDone = 0;
u8 ADC_u8Counter = 0;

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Init                                           */
/* Description       : Set prescaler, adjustment  */
/*                     type, reference voltage    */
/*                     and enable ADC             */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidInit(void)
{
	//select pre scaler to be 8
	ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_PRESCALER;

	//select adjustment to be left adjustment
	ADC_u8_ADMUX -> ByteAccess |= ADC_u8_ADJUSTMENT;

	//select reference voltage to internal 2.56V
	ADC_u8_ADMUX -> ByteAccess |= ADC_u8_VOLTAGE_REF;

	//enable ADC
	ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_ADC_INIT_STATE;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Enable                                         */
/* Description       : Enable ADC to be ready for */
/*                     conversion                 */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidEnable(void)
{
	ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_ADC_ENABLE;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Disable                                        */
/* Description       : Disable ADC so it wont make*/
/*                     further conversions        */
/* Input Argument(s) : Void                       */
/* Return            : Void                       */
void ADC_voidDisable(void)
{
	ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_ADC_DISABLE;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Get ADC blocking                               */
/* Description       : Get value of conversion    */
/*                     with polling               */
/* Input Argument(s) : Number of ADC channel      */
/*                     pointer to the value       */
/* Return            : Error Status               */
u8 ADC_u8GetADC_Blocking(u8 Copy_u8ChannelNb, u8* Copy_u8Value)
{
	u8 Local_u8ErrorStatus = ERROR_OK;
	u8 Local_u8ConvResult = 0;

	//select channel
	switch(Copy_u8ChannelNb)
	{
	case ADC_u8_ADC0:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC0;
		break;

	case ADC_u8_ADC1:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC1;
		break;

	case ADC_u8_ADC2:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC2;
		break;

	case ADC_u8_ADC3:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC3;
		break;

	case ADC_u8_ADC4:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC4;
		break;

	case ADC_u8_ADC5:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC5;
		break;

	case ADC_u8_ADC6:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC6;
		break;

	case ADC_u8_ADC7:
		ADC_u8_ADMUX -> ByteAccess |= ADC_u8_CHANNEL_ADC7;
		break;

	default:
		Local_u8ErrorStatus = ERROR_NOK;
	}

	//start conversion
	ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_START_CONV;

	//wait till conversion is done
	while((GET_BIT(ADC_u8_ADCSRA -> ByteAccess, ADC_u8_INTP_FLAG_BIT)) == 0);

	//store value of conversion
	Local_u8ConvResult = ADC_u8_ADCH -> ByteAccess;
	*Copy_u8Value = Local_u8ConvResult;

	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Refresh ADC                                    */
/* Description       : To start a chain conversion*/
/* Input Argument(s) : Void                       */
/* Return            : Error Status               */
u8 ADC_u8RefreshADC(void)
{
	u8 Local_u8ErrorStatus = ERROR_OK;

	if ((ADC_u8Counter == 0) || (ADC_u8ConvDone == 1))
	{
		ADC_u8Counter = 1;
		ADC_u8ConvDone = 0;

		// enable interrupt
		ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_INTERRUPT_ENABLE;

		//select the start channel from array of active channel in config file
		ADC_u8_ADMUX -> ByteAccess |= ADC_Au8ActiveChannels[ADC_u8ChannelFlag];

		//start conversion
		ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_START_CONV;
	}

	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Get ADC non blocking                           */
/* Description       : Get value of conversion    */
/*                     with interrupt use         */
/* Input Argument(s) : Number of ADC channel      */
/* Return            : Error Status               */

u8 ADC_u8GetADC_NonBlocking(u8 Copy_u8ChannelNb, u8* Copy_u8Value)
{
	u8 Local_u8ErrorStatus;
	u8 Local_u8Loop;

	for (Local_u8Loop=0 ; Local_u8Loop < ADC_u8_ACTIVE_CHANNELS_NUM ; Local_u8Loop++)
	{
		if (Copy_u8ChannelNb == ADC_Au8ActiveChannels[Local_u8Loop])
		{
			*Copy_u8Value = ADC_Au8ConvValues[Local_u8Loop];
			u8 Local_u8ErrorStatus = ERROR_OK;
			break;
		}
		else
		{
			u8 Local_u8ErrorStatus = ERROR_NOK;
		}
	}

	return Local_u8ErrorStatus;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
/* Set Call Back                                  */
/* Description       : Pass the function to be    */
/*                     executed to the ISR body of*/
/*                     the timer                  */
/* Input Argument(s) : Pointer to the call back fn*/
/* Return            : Void                       */
void Timer_u8SetCallBack(void (*Copy_PvoidCallBack)(void))
{
	PvoidFuncCallBack = Copy_PvoidCallBack;
}

/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8ChannelFlag < ADC_u8_ACTIVE_CHANNELS_NUM)
	{
		//store value of conversion
		ADC_Au8ConvValues[ADC_u8ChannelFlag] = ADC_u8_ADCH -> ByteAccess;

		//increment flag to go to the next channel
		ADC_u8ChannelFlag++;

		//set ADC channel to the next
		ADC_u8_ADMUX -> ByteAccess |= ADC_Au8ActiveChannels[ADC_u8ChannelFlag];

		//start conversion of the next channel
		ADC_u8_ADCSRA -> ByteAccess |= ADC_u8_START_CONV;
	}
	else
	{
		//call back function
		PvoidFuncCallBack();

		ADC_u8ChannelFlag = 0;
		ADC_u8ConvDone = 1;
	}
}
