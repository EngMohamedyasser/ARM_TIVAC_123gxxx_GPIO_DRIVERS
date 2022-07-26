/***************************************************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Types.h
 *    Component:  -
 *       Module:  ARM TIVAC 123GH6pm
 *
 *  Description:  Provision of Standard Types
 *
 ****************************************************************************************************************************************************/
 
 /*********************************File Guard instructions******************************************************************************************/
 
 #ifndef DIO_TYPES_H
 #define DIO_TYPES_H
 
 /*********************************End of File Guard **********************************************************************************************/

 /**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
	typedef unsigned char 		   u8int;
	typedef signed char 		   s8int;
	typedef unsigned short        u16int;         
	typedef signed short          s16int;         
	typedef unsigned long         u32int;         
	typedef signed long           s32int;         
	typedef unsigned long long    uint64;         
	typedef signed long long      s64int;
	typedef bool				   _bool;

	 #define HIGH 1u
	 #define LOW  0u
	 #define ON   1u
	 #define Off  0u
	 #define INPUT  0u
	 #define OUTPUT 1u 
	 
	/* **************DIO Macros ************************************************************************************************* */
		 
	 #define SET_BIT(DDRX,BIT) 				(DDRX|= (1<<BIT))
	 #define CLR_BIT(DDRX,BIT) 				(DDRX&=~(1<<BIT))
	 #define TOGGLE_BIT(DDRX,BIT)			(DDRX^= (1<<BIT))
	 #define CHECK_BIT(DDRX,BIT)			(DDRX & (1<<BIT) )
	 #define ROR(DDRX,num) 	   				(DDRX=  (DDRX>>num) | (DDRX<<(8-num)))
	 #define ROL(DDRX,num)     				(DDRX=  (DDRX<<num) | (DDRX>>(8-num)))
	 #define ACCESS_TO_DDRX(BASE,OFFSET) 		(*((volatile uint32 *)(BASE+OFFSET)) )
	 #define WRITE_ON_DDRX(BASE,OFFSET,VALUE) ((*((volatile uint32 *)(BASE+OFFSET))=(VALUE)))

	
 
  #endif DIO_TYPES_H