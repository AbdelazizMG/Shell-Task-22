/*
 * GPIO.h
 *
 * Created: 2021-08-18 10:49:48 AM
 *  Author: Abdelaziz Mohammad
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "StandardTypes.h"

#define GPIOA  ((GPIO*)0x39)
#define GPIOB  ((GPIO*)0x36)
#define GPIOC  ((GPIO*)0x33)
#define GPIOD  ((GPIO*)0x30) 


typedef union
{
	
	vu8 AllRegister;
	struct  
	{
		vu8 Bit0:1 ;
		vu8 Bit1:1 ;
		vu8 Bit2:1 ;
		vu8 Bit3:1 ;
		vu8 Bit4:1 ;
		vu8 Bit5:1 ;
		vu8 Bit6:1 ;
		vu8 Bit7:1 ;
	}Bits;
 
}Register;


typedef struct
{
	Register PIN;
	Register DDR;
	Register Port;
	
}GPIO;

typedef enum
{
	LOW,
	HIGH,
	
}Value;

typedef enum
{
	PullUp,
	Floating,
	output,
	
}Mode;



typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	
}Pin_Number;






void SetDataDirection (GPIO *gpio , Mode mode , Pin_Number pin );
void Output (GPIO *gpio , Value value , Pin_Number pin);
u8 Input ( GPIO *gpio , Pin_Number pin);
void  AllPortOutput(GPIO* gpio);

#endif /* GPIO_H_ */