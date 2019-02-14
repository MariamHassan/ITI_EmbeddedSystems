/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : DIO Program File                 */
/*               This files descripes the APIs    */
/*               definitions.                     */
/**************************************************/
/* Include required libraries and header files    */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/* Initialization                                 */
/* Description       : Initialize the pins        */ 
/*                     direction and value        */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void DIO_voidInit(void){
/* Setting PORT0 Direction                        */
  DIO_u8_DDRA -> ByteAccess = CONC_8BIT(DIO_u8_PIN7_INIT_DIR,
		  	  	  	  	  	  	  	  	DIO_u8_PIN6_INIT_DIR,
                                        DIO_u8_PIN5_INIT_DIR,
                                        DIO_u8_PIN4_INIT_DIR,
                                        DIO_u8_PIN3_INIT_DIR,
                                        DIO_u8_PIN2_INIT_DIR,
                                        DIO_u8_PIN1_INIT_DIR,
                                        DIO_u8_PIN0_INIT_DIR);
                                        


/* Setting PORT1 Direction                        */
  DIO_u8_DDRB -> ByteAccess = CONC_8BIT(DIO_u8_PIN15_INIT_DIR,
                                        DIO_u8_PIN14_INIT_DIR,
                                        DIO_u8_PIN13_INIT_DIR,
                                        DIO_u8_PIN12_INIT_DIR,
                                        DIO_u8_PIN11_INIT_DIR,
                                        DIO_u8_PIN10_INIT_DIR,
                                        DIO_u8_PIN9_INIT_DIR,
                                        DIO_u8_PIN8_INIT_DIR); 

/* Setting PORT2 Direction                        */
  DIO_u8_DDRC -> ByteAccess = CONC_8BIT(DIO_u8_PIN23_INIT_DIR,
                                        DIO_u8_PIN22_INIT_DIR,
                                        DIO_u8_PIN21_INIT_DIR,
                                        DIO_u8_PIN20_INIT_DIR,
                                        DIO_u8_PIN19_INIT_DIR,
                                        DIO_u8_PIN18_INIT_DIR,
                                        DIO_u8_PIN17_INIT_DIR,
                                        DIO_u8_PIN16_INIT_DIR);   

/* Setting PORT3 Direction                        */
  DIO_u8_DDRD -> ByteAccess = CONC_8BIT(DIO_u8_PIN31_INIT_DIR,
                                        DIO_u8_PIN30_INIT_DIR,
                                        DIO_u8_PIN29_INIT_DIR,
                                        DIO_u8_PIN28_INIT_DIR,
                                        DIO_u8_PIN27_INIT_DIR,
                                        DIO_u8_PIN26_INIT_DIR,
                                        DIO_u8_PIN25_INIT_DIR,
                                        DIO_u8_PIN24_INIT_DIR);  

/* Warning : Pin's direction might be an input so */
/*           a value mustn't be written on it. A  */ 
/*           redefining of the pin's direction is */
/*           made in case this happens.           */
#if (( DIO_u8_PIN0_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN0_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN0_INIT_VALUE 
  #define    DIO_u8_PIN0_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN1_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN1_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN1_INIT_VALUE 
  #define    DIO_u8_PIN1_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN2_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN2_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN2_INIT_VALUE 
  #define    DIO_u8_PIN2_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN3_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN3_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN3_INIT_VALUE 
  #define    DIO_u8_PIN3_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN4_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN4_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN4_INIT_VALUE 
  #define    DIO_u8_PIN4_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN5_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN5_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN5_INIT_VALUE 
  #define    DIO_u8_PIN5_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN6_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN6_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN6_INIT_VALUE 
  #define    DIO_u8_PIN6_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN7_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN7_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN7_INIT_VALUE 
  #define    DIO_u8_PIN7_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif           
/* Setting PORT0 Values                           */
  DIO_u8_PORTA -> ByteAccess = CONC_8BIT(DIO_u8_PIN7_INIT_VALUE,
                                         DIO_u8_PIN6_INIT_VALUE,
                                         DIO_u8_PIN5_INIT_VALUE,
                                         DIO_u8_PIN4_INIT_VALUE,
                                         DIO_u8_PIN3_INIT_VALUE,
                                         DIO_u8_PIN2_INIT_VALUE,
                                         DIO_u8_PIN1_INIT_VALUE,
                                         DIO_u8_PIN0_INIT_VALUE);
 
#if (( DIO_u8_PIN8_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN8_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN8_INIT_VALUE 
  #define    DIO_u8_PIN8_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN9_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN9_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN9_INIT_VALUE 
  #define    DIO_u8_PIN9_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN10_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN10_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN10_INIT_VALUE 
  #define    DIO_u8_PIN10_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN11_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN11_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN11_INIT_VALUE 
  #define    DIO_u8_PIN11_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN12_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN12_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN12_INIT_VALUE 
  #define    DIO_u8_PIN12_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN13_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN13_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN13_INIT_VALUE 
  #define    DIO_u8_PIN13_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN14_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN14_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN14_INIT_VALUE 
  #define    DIO_u8_PIN14_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN15_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN15_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN15_INIT_VALUE 
  #define    DIO_u8_PIN15_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif 
/* Setting PORT1 Values                           */
  DIO_u8_PORTB -> ByteAccess = CONC_8BIT(DIO_u8_PIN15_INIT_VALUE,
                                         DIO_u8_PIN14_INIT_VALUE,
                                         DIO_u8_PIN13_INIT_VALUE,
                                         DIO_u8_PIN12_INIT_VALUE,
                                         DIO_u8_PIN11_INIT_VALUE,
                                         DIO_u8_PIN10_INIT_VALUE,
                                         DIO_u8_PIN9_INIT_VALUE,
                                         DIO_u8_PIN8_INIT_VALUE); 

#if (( DIO_u8_PIN16_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN16_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN16_INIT_VALUE 
  #define    DIO_u8_PIN16_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN17_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN17_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN17_INIT_VALUE 
  #define    DIO_u8_PIN17_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN18_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN18_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN18_INIT_VALUE 
  #define    DIO_u8_PIN18_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN19_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN19_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN19_INIT_VALUE 
  #define    DIO_u8_PIN19_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN20_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN20_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN20_INIT_VALUE 
  #define    DIO_u8_PIN20_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN21_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN21_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN21_INIT_VALUE 
  #define    DIO_u8_PIN21_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN22_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN22_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN22_INIT_VALUE 
  #define    DIO_u8_PIN22_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN23_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN23_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN23_INIT_VALUE 
  #define    DIO_u8_PIN23_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif

/*Setting PORT2 Values                           */
  DIO_u8_PORTC -> ByteAccess = CONC_8BIT(DIO_u8_PIN23_INIT_VALUE,
                                         DIO_u8_PIN22_INIT_VALUE,
                                         DIO_u8_PIN21_INIT_VALUE,
                                         DIO_u8_PIN20_INIT_VALUE,
                                         DIO_u8_PIN19_INIT_VALUE,
                                         DIO_u8_PIN18_INIT_VALUE,
                                         DIO_u8_PIN17_INIT_VALUE,
                                         DIO_u8_PIN16_INIT_VALUE);

#if (( DIO_u8_PIN24_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN24_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN24_INIT_VALUE 
  #define    DIO_u8_PIN24_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN25_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN25_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN25_INIT_VALUE 
  #define    DIO_u8_PIN25_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN26_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN26_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN26_INIT_VALUE 
  #define    DIO_u8_PIN26_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN27_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN27_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN27_INIT_VALUE 
  #define    DIO_u8_PIN27_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN28_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN28_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN28_INIT_VALUE 
  #define    DIO_u8_PIN28_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN29_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN29_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN29_INIT_VALUE 
  #define    DIO_u8_PIN29_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN30_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN30_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN30_INIT_VALUE 
  #define    DIO_u8_PIN30_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
#if (( DIO_u8_PIN31_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_u8_PIN31_INIT_VALUE != DIO_u8_PIN_INIT_DEF))
  #warning "This pin's direction is input so it will be set to the default value!"
  #undef  DIO_u8_PIN31_INIT_VALUE 
  #define    DIO_u8_PIN31_INIT_VALUE  DIO_u8_PIN_INIT_DEF  
#endif
/* Setting PORT3 Values                           */
  DIO_u8_PORTD -> ByteAccess = CONC_8BIT(DIO_u8_PIN31_INIT_VALUE,
                                         DIO_u8_PIN30_INIT_VALUE,
                                         DIO_u8_PIN29_INIT_VALUE,
                                         DIO_u8_PIN28_INIT_VALUE,
                                         DIO_u8_PIN27_INIT_VALUE,
                                         DIO_u8_PIN26_INIT_VALUE,
                                         DIO_u8_PIN25_INIT_VALUE,
                                         DIO_u8_PIN24_INIT_VALUE);                                                                                  
}

/* Set Pin Direction                              */
/* Description       : Set the pin direction      */
/* Range             : DIO_u8_PIN_INPUT           */
/*                     DIO_u8_PIN_OUTPUT          */       
/* Input Argument(s) : Pin Number & Direction     */
/* Return            : Error Status               */
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDir){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if((Copy_u8PinNum >= DIO_u8_MAX_PIN_NO) ||
		((Copy_u8PinDir != DIO_u8_PIN_INPUT) && (Copy_u8PinDir != DIO_u8_PIN_OUTPUT))){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
      if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <=DIO_u8_PIN7)){
          ASSIGN_BIT((DIO_u8_DDRA->ByteAccess),Copy_u8PinNum,Copy_u8PinDir);
          Local_u8ErrorStatus = ERROR_OK;
        
        }else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <=DIO_u8_PIN15)){
          ASSIGN_BIT((DIO_u8_DDRB->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN8),Copy_u8PinDir);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <=DIO_u8_PIN23)){
          ASSIGN_BIT((DIO_u8_DDRC->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN16),Copy_u8PinDir);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
          ASSIGN_BIT((DIO_u8_DDRD->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN24),Copy_u8PinDir);
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus; 
}

/* Set Pin Value                                  */
/* Description       : Set the pin value          */
/* Range             : DIO_u8_PIN_HIGH            */
/*                     DIO_u8_PIN_LOW             */       
/* Input Argument(s) : Pin Number & Val           */
/* Return            : Error Status               */
u8 DIO_u8SetPinValue(u8 Copy_u8PinNum , u8 Copy_u8PinValue){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if((Copy_u8PinNum >= DIO_u8_MAX_PIN_NO) ||
		((Copy_u8PinValue != DIO_u8_PIN_HIGH) && (Copy_u8PinValue != DIO_u8_PIN_LOW))){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
      if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <=DIO_u8_PIN7)){        
        ASSIGN_BIT((DIO_u8_PORTA->ByteAccess),Copy_u8PinNum,Copy_u8PinValue);
        Local_u8ErrorStatus = ERROR_OK;
        
        }else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <=DIO_u8_PIN15)){
          ASSIGN_BIT((DIO_u8_PORTB->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN8),Copy_u8PinValue);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <=DIO_u8_PIN23)){
          ASSIGN_BIT((DIO_u8_PORTC->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN16),Copy_u8PinValue);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
          ASSIGN_BIT((DIO_u8_PORTD->ByteAccess),(Copy_u8PinNum - DIO_u8_PIN24),Copy_u8PinValue);
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus; 
}

/* Get Pin Value                                  */
/* Description       : Get the pin value          */
/* Range             : DIO_u8_PIN_HIGH            */
/*                     DIO_u8_PIN_LOW             */       
/* Input Argument(s) : Pin Number &               */
/*                     Pointer to Value           */
/* Return            : Error Status               */
u8 DIO_u8GetPinValue(u8 Copy_u8PinNum , u8* Copy_u8ValuePtr){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if(Copy_u8PinNum >= DIO_u8_MAX_PIN_NO){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
      if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <=DIO_u8_PIN7)){        
        *(Copy_u8ValuePtr) = GET_BIT((DIO_u8_PINA->ByteAccess),Copy_u8PinNum);
        Local_u8ErrorStatus = ERROR_OK;
        
        }else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <=DIO_u8_PIN15)){
          *(Copy_u8ValuePtr) = GET_BIT((DIO_u8_PINB->ByteAccess),Copy_u8PinNum);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <=DIO_u8_PIN23)){
          *(Copy_u8ValuePtr) = GET_BIT((DIO_u8_PINC->ByteAccess),Copy_u8PinNum);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
          *(Copy_u8ValuePtr) = GET_BIT((DIO_u8_PIND->ByteAccess),Copy_u8PinNum);
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus;
}

/* Set Port Direction                             */
/* Description       : Set the port direction     */
/* Range             : DIO_u8_PORT_INPUT          */
/*                     DIO_u8_PORT_OUTPUT         */       
/* Input Argument(s) : Port Number & Direction    */
/* Return            : Error Status               */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNum , u8 Copy_u8PortDir){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if((Copy_u8PortNum >= DIO_u8_MAX_PORT_NO) ||
		((Copy_u8PortDir != DIO_u8_PORT_INPUT) && (Copy_u8PortDir != DIO_u8_PORT_OUTPUT))){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
    	if (Copy_u8PortNum == DIO_u8_PORT0){
        DIO_u8_DDRA -> ByteAccess = Copy_u8PortDir;
        Local_u8ErrorStatus = ERROR_OK;
        
        }else if(Copy_u8PortNum == DIO_u8_PORT1){
          DIO_u8_DDRB -> ByteAccess = Copy_u8PortDir;
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if(Copy_u8PortNum >= DIO_u8_PORT2){
          DIO_u8_DDRC -> ByteAccess = Copy_u8PortDir;
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
           DIO_u8_DDRD -> ByteAccess = Copy_u8PortDir;
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus;  
}

/* Set Port Value                                 */
/* Description       : Set the port value         */
/* Range             : DIO_u8_PORT_HIGH           */
/*                     DIO_u8_PORT_LOW            */       
/* Input Argument(s) : Port Number & Value        */
/* Return            : Error Status               */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNum , u8 Copy_u8PortValue){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if((Copy_u8PortNum >= DIO_u8_MAX_PORT_NO) ||
		((Copy_u8PortValue > DIO_u8_PORT_HIGH) && (Copy_u8PortValue < DIO_u8_PORT_LOW))){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
      if (Copy_u8PortNum == DIO_u8_PORT0){        
        DIO_u8_PORTA -> ByteAccess = Copy_u8PortValue;
        Local_u8ErrorStatus = ERROR_OK;
        }else if(Copy_u8PortNum == DIO_u8_PORT1){
          DIO_u8_PORTB -> ByteAccess = Copy_u8PortValue;
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if(Copy_u8PortNum >= DIO_u8_PORT2){
          DIO_u8_PORTC -> ByteAccess = Copy_u8PortValue;
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
           DIO_u8_PORTD -> ByteAccess = Copy_u8PortValue;
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus;     
}

/* Get Port Value                                 */
/* Description       : Get the port value         */
/* Range             : DIO_u8_PORT_HIGH           */
/*                     DIO_u8_PORT_LOW            */       
/* Input Argument(s) : Port Number &              */
/*                     Pointer to Value           */
/* Return            : Error Status               */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNum, u8* Copy_u8ValuePtr){
/* Local variables declaration                    */    
  u8 Local_u8ErrorStatus;

  if(Copy_u8PortNum >= DIO_u8_MAX_PORT_NO){
      Local_u8ErrorStatus = ERROR_NOK;
    }else{
      if (Copy_u8PortNum == DIO_u8_PORT0){        
        *(Copy_u8ValuePtr) = (DIO_u8_PINA->ByteAccess);
        Local_u8ErrorStatus = ERROR_OK;
        }else if(Copy_u8PortNum == DIO_u8_PORT1){
          *(Copy_u8ValuePtr) = (DIO_u8_PINB->ByteAccess);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else if(Copy_u8PortNum == DIO_u8_PORT2){
          *(Copy_u8ValuePtr) = (DIO_u8_PINC->ByteAccess);
          Local_u8ErrorStatus = ERROR_OK;
          
        }else{
          *(Copy_u8ValuePtr) = (DIO_u8_PIND->ByteAccess);
          Local_u8ErrorStatus = ERROR_OK;  
        }
    }
 return Local_u8ErrorStatus;   
}
