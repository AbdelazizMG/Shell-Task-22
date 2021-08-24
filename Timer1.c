/*
 * Timer1.c
 *
 * Created: 2021-08-21 6:02:07 AM
 *  Author: sigmaa
 */ 
#include "Timer1.h"
#include "GPIO.h"
#include "Macros.h"
#include "StandardTypes.h"



void EnableGlobalInterrupt()
{
	
	SetBit(SREG->AllRegister,7);
	
	
}
void delay_Init()
{
	
	/* CTC with OCRA TOP*/
	ClearBit(TCCR1A->AllRegister,WGM10);
	ClearBit(TCCR1A->AllRegister,WGM11);
	SetBit(TCCR1B->AllRegister,WGM12);
	SetBit(TCCR1B->AllRegister,WGM13);
	
	(ICUL) = 60000;
	
	
	SetDataDirection(GPIOD,output,PIN5); //OC1A
	
	///CTC Set on compare
	SetBit(TCCR1A->AllRegister,COM1A0);
	ClearBit(TCCR1A->AllRegister,COM1A1);
	
	///1024 prescaler
	SetBit(TCCR1B->AllRegister,CS10);
	ClearBit(TCCR1B->AllRegister,CS11);
	SetBit(TCCR1B->AllRegister,CS12);
	
}

void timer_stop()
{
		ClearBit(TCCR1B->AllRegister,CS10);
		ClearBit(TCCR1B->AllRegister,CS11);
		ClearBit(TCCR1B->AllRegister,CS12);
}
void timer_start()
{
	SetBit(TCCR1B->AllRegister,CS10);
	ClearBit(TCCR1B->AllRegister,CS11);
	SetBit(TCCR1B->AllRegister,CS12);
}
void delay_3_Seconds()
{
	
	
	OCR1AL=23438;
	
	
}
void EnableInterruptTimer1()
{
	SetBit(TIMSK->AllRegister,4);
}
void DisableInterruptTimer1()
{
	ClearBit(TIMSK->AllRegister,4);
}