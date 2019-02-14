/**************************************************/
/* Author      : Mariam Ahmed                     */
/* Date        : 5 Feb 2019                       */   
/* Version     : V01                              */
/**************************************************/
/**************************************************/
/* Description : DIO Interface File               */
/*               This file has:                   */   
/*                1- Pins numbers macros          */
/*                2- Ports numbers macros         */
/*                3- Pins values macros           */
/*                4- Pins direction macros        */
/*                5- Ports values macros          */
/*                6- Ports direction macros       */
/*                7- Number of pins               */         
/*                8- APIs prototypes              */
/**************************************************/
/* Preprocessor Guard                                */
#ifndef DIO_INTERFACE_H                           
#define DIO_INTERFACE_H                           
                                                  
/* Comment : Pins Numbers                         */
#define DIO_u8_PIN0  (u8)0                         
#define DIO_u8_PIN1  (u8)1                         
#define DIO_u8_PIN2  (u8)2                         
#define DIO_u8_PIN3  (u8)3                         
#define DIO_u8_PIN4  (u8)4                         
#define DIO_u8_PIN5  (u8)5                         
#define DIO_u8_PIN6  (u8)6                         
#define DIO_u8_PIN7  (u8)7                         
                       
#define DIO_u8_PIN8  (u8)8                         
#define DIO_u8_PIN9  (u8)9                         
#define DIO_u8_PIN10 (u8)10                       
#define DIO_u8_PIN11 (u8)11                       
#define DIO_u8_PIN12 (u8)12                       
#define DIO_u8_PIN13 (u8)13                       
#define DIO_u8_PIN14 (u8)14                       
#define DIO_u8_PIN15 (u8)15                       
                         
#define DIO_u8_PIN16 (u8)16                       
#define DIO_u8_PIN17 (u8)17                       
#define DIO_u8_PIN18 (u8)18                       
#define DIO_u8_PIN19 (u8)19                       
#define DIO_u8_PIN20 (u8)20                       
#define DIO_u8_PIN21 (u8)21                       
#define DIO_u8_PIN22 (u8)22                       
#define DIO_u8_PIN23 (u8)23                       
                         
#define DIO_u8_PIN24 (u8)24                       
#define DIO_u8_PIN25 (u8)25                       
#define DIO_u8_PIN26 (u8)26                       
#define DIO_u8_PIN27 (u8)27                       
#define DIO_u8_PIN28 (u8)28                       
#define DIO_u8_PIN29 (u8)29                       
#define DIO_u8_PIN30 (u8)30                       
#define DIO_u8_PIN31 (u8)31                       
                                                  
/* Comment : Ports Numbers                        */
#define DIO_u8_PORT0 (u8)0                        
#define DIO_u8_PORT1 (u8)1                        
#define DIO_u8_PORT2 (u8)2                        
#define DIO_u8_PORT3 (u8)3                        
                                                  
/* Comment : HIGH & LOW values of Pins            */
#define DIO_u8_PIN_HIGH (u8)1                     
#define DIO_u8_PIN_LOW  (u8)0                     
                                                  
/* Comment : INPUT & OUTPUT values of Pins        */
#define DIO_u8_PIN_INPUT  (u8)0                   
#define DIO_u8_PIN_OUTPUT (u8)1                   
                                                  
/* Comment : HIGH & LOW values of Ports           */
#define DIO_u8_PORT_HIGH (u8)255                    
#define DIO_u8_PORT_LOW  (u8)0                    
                                                  
/* Comment : INPUT & OUTPUT values of Ports       */
#define DIO_u8_PORT_INPUT  (u8)0                 
#define DIO_u8_PORT_OUTPUT (u8)255   

/* Comment : Number of pins and ports */
#define DIO_u8_MAX_PIN_NO      (u8)32  
#define DIO_u8_MAX_PIN_IN_PORT (u8)8 
#define DIO_u8_MAX_PORT_NO     (u8)4           
                                                 
/* Comment : API's prototypes                     */
/* Initialization                                 */
/* Description       : Initialize the pins        */ 
/*                     direction and value        */
/* Input Argument(s) : void                       */
/* Return            : void                       */
void DIO_voidInit(void);

/* Set Pin Direction                              */
/* Description       : Set the pin direction      */
/* Range             : DIO_u8_PIN_INPUT           */
/*                     DIO_u8_PIN_OUTPUT          */       
/* Input Argument(s) : Pin Number & Direction     */
/* Return            : Error Status               */
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDir);

/* Set Pin Value                                  */
/* Description       : Set the pin value          */
/* Range             : DIO_u8_PIN_HIGH            */
/*                     DIO_u8_PIN_LOW             */       
/* Input Argument(s) : Pin Number & Value         */
/* Return            : Error Status               */
u8 DIO_u8SetPinValue(u8 Copy_u8PinNum , u8 Copy_u8PinValue);
     
/* Get Pin Value                                  */
/* Description       : Get the pin value          */
/* Range             : DIO_u8_PIN_HIGH            */
/*                     DIO_u8_PIN_LOW             */       
/* Input Argument(s) : Pin Number &               */
/*                     Pointer to Value           */
/* Return            : Error Status               */
u8 DIO_u8GetPinValue(u8 Copy_u8PinNum , u8* Copy_u8ValuePtr);

/* Set Port Direction                             */
/* Description       : Set the port direction     */
/* Range             : DIO_u8_PORT_INPUT          */
/*                     DIO_u8_PORT_OUTPUT         */       
/* Input Argument(s) : Port Number & Direction    */
/* Return            : Error Status               */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNum , u8 Copy_u8PortDir);

/* Set Port Value                                 */
/* Description       : Set the port value         */
/* Range             : DIO_u8_PORT_HIGH           */
/*                     DIO_u8_PORT_LOW            */       
/* Input Argument(s) : Port Number & Value        */
/* Return            : Error Status               */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNum , u8 Copy_u8PortValue);
     
/* Get Port Value                                 */
/* Description       : Get the port value         */
/* Range             : DIO_u8_PORT_HIGH           */
/*                     DIO_u8_PORT_LOW            */       
/* Input Argument(s) : Port Number &              */
/*                     Pointer to Value           */
/* Return            : Error Status               */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNum, u8* Copy_u8ValuePtr);
                                          
#endif                                           
