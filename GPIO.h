 /******************************************************************************
 * Author : Mohamed Shehab
 * Module: General Purpose Input Output
 *
 * File Name:GPIO.h
 *
 * Description: Header file for GPIO control
 *
 *******************************************************************************/
		
	/* **************** File guard ************************************************************* */
	
	#ifndef GPIO_H_
	#define GPIO_H_
	 
	/* **************** **************************************************** */
	 
	#include "DIO_Types.h"
 	
	/* Ports Base addresses */
	
	#define PORTA	 (*((volatile u32int *) 0x40004000) )
	#define PORTB	 (*((volatile u32int *) 0x40005000) )
	#define PORTC	 (*((volatile u32int *) 0x40006000) )
	#define PORTD	 (*((volatile u32int *) 0x40007000) )
	#define PORTE 	 (*((volatile u32int *) 0x40024000) )
	#define PORTF 	 (*((volatile u32int *) 0x40025000) )
	
	/* ***************************************************************************** */
	
	/* GPIO Register Map addresses offset ************************************************* */
	
	#define GPIO_DATAOFF	 					 0x000
	#define GPIO_DIROFF		 					 0x400
	#define GPIO_AFSELOFF			 	 	 	 0x420
	#define GPIO_DR2ROFF				 	 	 0x500
	#define GPIO_DR4ROFF		 			 	 0x504
	#define GPIO_DR8ROFF		 	 	 		 0x508
	#define GPIO_ODROFF				 	 	 	 0x50C
	#define GPIO_PUROFF			 	 			 0x510
	#define GPIO_PDROFF			 	 			 0x514
	#define GPIO_SLROFF	 	 					 0x518
	#define GPIO_DENOFF	 	 					 0x51C
	#define GPIO_LOCKOFF	 	 				 0x520
	#define GPIO_CROFF		 	 				 0x524
	#define GPIO_AMSELOFF	 	 				 0x528
	#define GPIO_CTLOFF	 		 				 0x52C
	#define GPIO_DATAROFF						 0x3FC
	
	
	/* ****************Interrupt addresses offset **************************************************** -> */
	
	#define GPIO_ISOFF			 	 			 0x404
	#define GPIO_IBEOFF			 	 	     	 0x408
	#define GPIO_IEVOFF	 	 					 0x40C
	#define GPIO_IMOFF	 	 					 0x410
	#define GPIO_RISOFF	 	 				 	 0x414
	#define GPIO_MISOFF			 	 		 	 0x418
	#define GPIO_ICROFF	 	 					 0x41C
	
	/* **************** **************************************************** -> */
	

	/* **************** ADC Addresses offset **************************************************** -> */
	
	#define GPIO_ADCCTLOFF	 	 				 0x530
	#define GPIO_DMACTLOFF	 	 				 0x534
	
	/* **************** **************************************************** */
	
	#define GPIO_PeriphID4OFF	  				 0xFD0
	#define GPIO_PeriphID5OFF	 	 			 0xFD4
	#define GPIO_PeriphID6OFF	 	 			 0xFD8
	#define GPIO_PeriphID7OFF	 	 			 0xFDC
	#define GPIO_PeriphID0OFF	 	 			 0xFE0
	#define GPIO_PeriphID1OFF	 	 			 0xFE4
	#define GPIO_PeriphID2OFF	 	 			 0xFE8
	#define GPIO_PeriphID3OFF	 	 			 0xFEC
	#define GPIO_PCellID0OFF	 	 			 0xFF0
	#define GPIO_PCellID1OFF 	 	 			 0xFF4
	#define GPIO_PCellID2OFF	 	 			 0xFF8
	#define GPIO_PCellID3OFF	 	 			 0xFFC
	
	/* *********************************************************************** */
	
	
	/* *****************GLOBAL DATA TYPES AND STRUCTURES********************** */
	
	
	/*Enum that desscribes the functionality of a pin*/
	typedef enum {GPIO,PERIPHERAL} GPIO_PIN_MODE;


	typedef enum{INPUT,OUTPUT} GPIO_PIN_DDR;
	
	
	/*Enum that describes whether pin is digital or analog */
	typedef enum{ANALOG, DIGITAL} GPIO_PIN_DIGITAL_ENABLE;

	/*Enum that describes the status of the internal resistance of the pin*/
	typedef enum{NO_RES,PULLUP,PULLDOWN} GPIO_PIN_INTERNAL_ATTACH;

	/*Enum that describes the output configuration of the pin*/
	typedef enum{ OPENDRAIN_OFF,OPENDRAIN_ON} GPIO_OUTPUT_CONFIG;


	/*enum that describes the output current drive */
	typedef enum {D_0mA=0,D_2mA=1, D_4mA=2,D_8mA=3} GPIO_PIN_OUTPUT_CURRENT;

	/*Enum that states if a pin is used as dma of adc trigger*/
	typedef enum {NO_TRIGGER,ADC,UDMA} GPIO_PIN_TRIGGER;

	/*Interrupt */
	/*Enum that states if the interrupt of a pin is enabled*/
	typedef enum {DISABLE_INTERRUPT,ENABLE_INTERRUPT} GPIO_INT_ENABLE;

	/*Enum that describes interrupt sense */
	typedef enum{EDGE_TRIGGERED,LEVEL_TRIGGER} GPIO_INT_SENSE;

	/*Enum that describes the trigger of the interrupt pin*/
	typedef enum {BOTH_EDGES,FALLING_EDGE,RISING_EDGE} GPIO_INT_TRIGGER;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Struct describing the configuration of the enum*/
	typedef struct 
	{
		GPIO_INT_SENSE sense;
		GPIO_INT_TRIGGER trigger;

	} GPIO_INT_CONFIG;

	/*Struct that describes the configuration of a GPIO pin */
	typedef struct 
	{
		GPIO_PIN_DDR direction;
		GPIO_PIN_MODE pinMode;
		GPIO_PIN_DIGITAL_ENABLE digitalEnable;
		GPIO_PIN_INTERNAL_ATTACH internalResistance;
		GPIO_OUTPUT_CONFIG outputConfig;
		GPIO_PIN_OUTPUT_CURRENT currentDrive;
		GPIO_PIN_TRIGGER pinTrigger;
		GPIO_INT_ENABLE interruptEnable;
		GPIO_INT_CONFIG interruptConfig;

	}GPIO_PIN_CONFIG;


	/*Struct that describes the configuration of an interrupt pin */
	typedef struct{
		GPIO_INT_SENSE interruptSense;
		GPIO_INT_TRIGGER interruptTrigger;
	} GPIO_INT_PIN_CONFIG;


/* ********************GLOBAL FUNCTION PROTOTYPES************************** */

	void GPIO_enablePortClock(uint32 port);

	/* Function that intializes a GPIO pin
	params:
		-configuration: the configuration of the pin
		-port:	port to be configrued
		-pin: number of pin ro be configured
	*/
	void GPIO_intit(GPIO_pinConfig *configuration,uint32 port,uint8 pin);

	/* Function that clears the interrupt Mask interrupt status and raw interrupt status by setting ICR bit
	params:
		-port: port of the interrupt pin
		-pin: the interrupt pin
	*/
	void GPIO_clearInterrupt(uint32 port,uint8 pin);
	
	
	

	
	#endif
 