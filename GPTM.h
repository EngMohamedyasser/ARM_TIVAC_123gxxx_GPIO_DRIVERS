 /******************************************************************************
 *
 * Module: MicroController
 *
 * File Name: GPTM.h
 *
 * Description: Contains Timers register addresses for Tm4c123GH6PM
 *
 *******************************************************************************/


	/*File Guard instructions*******************************************************************************************/
 
	#ifndef GPTM_H_
	#define GPTM_H_
 
	/*End of File Guard **********************************************************************************************/
	/**********************************************************************************************************************
	* INCLUDES
	*********************************************************************************************************************/

		#include "DIO_Types.h"
 
 	
	/**********************************************************************************************************************
	*  GLOBAL CONSTANT MACROS	
	*********************************************************************************************************************/

	/* **************** TIMER Addresses **************************************************** -> */	
	
	/*	16/32-bit 	*/
	#define b16_TIMER0	 							 (*((volatile u32int *)0x40030000))
	#define b16_TIMER1 								 (*((volatile u32int *)0x40031000))
	#define b16_TIMER2 								 (*((volatile u32int *)0x40032000))
	#define b16_TIMER3 								 (*((volatile u32int *)0x40033000))
	#define b16_TIMER4 								 (*((volatile u32int *)0x40034000))
	#define b16_TIMER5 								 (*((volatile u32int *)0x40035000))
	
	/*	32/64-bit  */
	#define b64_TIMER0 								 (*((volatile u32int *)0x40036000))
	#define b64_TIMER1 								 (*((volatile u32int *)0x40037000))
	#define b64_TIMER2 								 (*((volatile u32int *)0x4004C000))
	#define b64_TIMER3 								 (*((volatile u32int *)0x4004D000))
	#define b64_TIMER4 								 (*((volatile u32int *)0x4004E000))
	#define b64_TIMER5 								 (*((volatile u32int *)0x4004F000))
	
	
	/* *************************************************************************************** */
	

	/* ****************** TIMER Addresses Offsets ******************************************** */
	
	#define GPTM_Control							0x00C  /*RW/GPTM Control	    */
	#define GPTM_SYNC								0x010  /*RW/GPTM Synchronize   */
	#define GPTM_INT_MASk							0x018  /*RW/GPTM nterrupt Mask */	
	#define GPTM_Config								0x000  /*RW/GPTM Configuration */
	#define GPTM_TimerAMode							0x004  /*RW/GPTM  Timer A Mode */
	#define GPTM_TimerBMode							0x008  /*RW/GPTM  Timer B Mode */
	#define GPTM_TIMERA_VALUE						0x050  /*RW/GPTM  Timer A Value */
	#define GPTM_TIMERB_VALUE						0x054  /*RW/GPTM  Timer B Value */
	#define GPTM_TIMERA_INTERVAL_LOAD				0x028  /*RW/GPTM  Timer A Interval Load  */
	#define GPTM_TIMERB_INTERVAL_LOAD				0x02C  /*RW/GPTM  Timer B Interval Load  */
	#define GPTM_TIMERA_MATCH						0x030  /*RW/GPTM  Timer A Match */
	#define GPTM_TIMERB_MATCH						0x034  /*RW/GPTM  Timer B Match */
	#define GPTM_TIMERA_PRESCALE					0x038  /*RW/GPTM  Timer A Prescale */
	#define GPTM_TIMERB_PRESCALE					0x03C  /*RW/GPTM  Timer B Prescale */
	#define GPTM_TIMERA_PRESCALE_MTCH				0x040  /*RW/GPTM  TimerA Prescale Match */
	#define GPTM_TIMERB_PRESCALE_MTCH				0x044  /*RW/GPTM  TimerB Prescale Match */
	#define GPTM_INT_CLEAR							0x024  /*W1C/GPTM Interrupt Clear */
	#define GPTM_RAW_INT_STATUS						0x01C  /*RO/GPTM Raw Interrupt Status  */
	#define GPTM_MASKED_INT_STATUS					0x020  /*RO/GPTM Masked Interrupt Status */
	#define GPTM_TIMERA								0x048  /*RO/GPTM  Timer A */
	#define GPTM_TIMERB								0x04C  /*RO/GPTM  Timer B */
	#define GPTM_RTC_PREDIVIDE 						0x058  /*RO/GPTM RTC Predivide */
	#define GPTM_TIMERA_PRESCALE_SNAPSHOT			0x05C  /*RO/GPTM  Timer A Prescale Snapshot */
	#define GPTM_TIMERB_PRESCALE_SNAPSHOT			0x060  /*RO/GPTM  Timer B Prescale Snapshot */
	#define GPTM_TIMERA_PRESCALE_VALUE				0x064  /*RO/GPTM  Timer A Prescale Value */
	#define GPTM_TIMERB_PRESCALE_VALUE 				0x068  /*RO/GPTM  Timer B Prescale Value */
	#define GPTM_PREPHERAL_PROP						0xFC0  /*RO/GPTM  Peripheral Properties */

	/* ************************************************************************************** */
	
	/**********************************************************************************************************************
	*  GLOBAL DATA TYPES AND STRUCTURES
	*********************************************************************************************************************/
	/*Enum that states the mode of the timer*/
	typedef enum{ONE_SHOT_MODE=1,PERIODIC_MODE=2,CAPTURE_MODE=3} GPTM_MODE;

	/*Enum that states the count direction of the timer*/
	typedef enum{DOWN_COUNTER,UP_COUNTER} GPTM_DIRECTION;

	/*Enum that stateswhether the timer waits for a trigger to operate or not*/
	typedef enum{TRIGGER_DISABLED,WAIT_TRIGGER} GPTM_TRIGGER;

	/*Enum that states whether the timer match is enabled or not*/
	typedef enum{TIMER_MATCH_DISABLED,TIMER_MATCH_ENABLED} GPTM_MatchEnable;

	/*Enum that states the possible interrupts for the timer*/
	typedef enum{NO_INTERRUPT=-1,TIMERA_TIMEOUT=0,TIMERA_CAPTURE_MODE_MATCH=1,TIMERA_CAPTURE_MODE_EVENT=2,
				RTC_RAW=3,TIMERA_MATCH_RAW=4,TIMERB_TIMEOUT=8,TIMERB_CAPTURE_MODE_MATCH=9,
				TIMERB_CAPTURE_MODE_EVENT=10,TIMERB_MATCH=11} GPTM_INT_TYPE;

	/*Enum that states necessary configurations for periodic mode*/
	typedef struct {
		GPTM_countDirection countDirection;
		GPTM_TRIGGER trigger;
		GPTM_MatchEnable timerMatchEnable;
		GPTM_INT_TYPE interruptType;
		u32int intervalLoad;
	} GPTM_CONFIG;

	
	#endif