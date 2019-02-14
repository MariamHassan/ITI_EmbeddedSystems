/**************************************************/
/* Author : Mariam Ahmed                          */
/* Date   : 5 Feb 2019                            */
/**************************************************/
/**************************************************/
/* Description : Standard Types File              */
/*               This file descripes the new      */   
/*               standard types to be used and the*/
/*               error status values              */
/**************************************************/
/* Processor Guard                                */
#ifndef STD_TYPES_H                               
#define STD_TYPES_H                               
                                                  
/* Comment : New types definition                 */
/* Unsigned 8 bit type                            */
typedef unsigned char u8;                         
                                                  
/* Unsigned 16 bit type                           */
typedef unsigned short int u16;                   
                                                  
/* Unsigned 32 bit type                           */
typedef unsigned long int u32;                    
                                                  
/* Signed 8 bit type                              */
typedef signed char s8;                           
                                                  
/* Signed 16 bit type                             */
typedef signed short int s16;                     
                                                  
/* Signed 32 bit type                             */
typedef signed long int s32;                      
                                                  
/* Float 32 bit type                              */
typedef float f32;                                
                                                  
/* Double 64 bit type                             */
typedef double f64;

/* Register struct data type for registers        */
typedef union {
	struct{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	}BitAccess;

	u8 ByteAccess;

}Register_8Bit;
                                                  
/* Comment : Error Status Value                   */
#define ERROR_NOK 1
#define ERROR_OK 0

#endif
