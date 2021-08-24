/*
 * GPIO.c
 *
 * Created: 2021-08-18 10:59:13 AM
 *  Author: sigmaa
 */ 
#include "GPIO.h"
#include "Macros.h"

void SetDataDirection (GPIO *gpio , Mode mode , Pin_Number pin )
{
	switch(mode)
	{
		case Floating: ClearBit(gpio->DDR.AllRegister,pin);
		               ClearBit(gpio->Port.AllRegister,pin);
					   break;
		case PullUp:   break;
		case output:   SetBit(gpio->DDR.AllRegister,pin);
		               break;
		               
	}
}


void Output (GPIO *gpio , Value value , Pin_Number pin)
{
	
	if(value)
	{
		SetBit(gpio->Port.AllRegister,pin);
		
	}
	else if(value == LOW)
	{
		ClearBit(gpio->Port.AllRegister,pin);
	}
	
}


u8 Input ( GPIO *gpio , Pin_Number pin)
{
	return CheckBit(gpio->PIN.AllRegister,pin);
	
}


void  AllPortOutput(GPIO* gpio)
{
	
	for(u8 i=0;i<8;i++)
	{
		
		SetDataDirection(gpio,output,PIN0+i);
		
	}
	
	
	
	
}