/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  WDT.H
 *       Module:  watchdog timer
 *
 *  Description:  header file for macros and interfaces of watchdog timer
 *  
 *********************************************************************************************************************/
#ifndef WDT_H_
#define WDT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
	#include "DIO_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
		/* *** WATCHDOG TIMER *** */
	
	#define WDT0									  (*((volatile u32int *)0x40000000))
	#define WDT1									  (*((volatile u32int *)0x40001000))		


				/* *** WATCHDOG TIMER ADDRESSES OFFSET *** */
				
	#define WDT_LOAD 								0x000
	#define WDT_VALUE					 			0x004
	#define WDT_CTRL								0x008
	#define WDT_INT_CLR								0x00C
	#define WDT_RAW_INT_STATUS						0x010
	#define WDT_MASKED_INT_STATUS					0x014
	#define WDT_TEST								0x418
	#define WDT_LOCK								0xC00
	#define WDT_PERIPHERAL_ID4						0xFD0
	#define WDT_PERIPHERAL_ID5						0xFD4
	#define WDT_PERIPHERAL_ID6						0xFD8
	#define WDT_PERIPHERAL_ID7						0xFDC	
	#define WDT_PERIPHERAL_ID0						0xFE0
	#define WDT_PERIPHERAL_ID1						0xFE4
	#define WDT_PERIPHERAL_ID2						0xFE8
	#define WDT_PERIPHERAL_ID3						0xFEC
	#define WDT_PRIME_ID0							0xFF0
	#define WDT_PRIME_ID1							0xFF4	
	#define WDT_PRIME_ID2							0xFF8
	#define WDT_PRIME_ID3							0xFFC
	
	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
