/*
 * Timer1.h
 *
 * Created: 2021-08-21 6:01:55 AM
 *  Author: sigmaa
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include  "GPIO.h"
#include  "StandardTypes.h"

#define  TCCR1A		((Register*)0x4F)
#define  TCCR1B		((Register*)0x4E)
#define  OCR1AH		((Register*)0x4B)
#define  OCR1AL		(*((volatile unsigned short*)0x4A))
#define  OCR1BH		((Register*)0x49)
#define  OCR1BL	    ((Register*)0x48)
#define	 TIMSK		((Register*)0x59)
#define	 ICUH		((Register*)0x47)
#define	 ICUL		(*((volatile unsigned short*)0x46))
#define  SREG		((Register*)0x5F)
#define  TCNT       (*((volatile unsigned short*)0x4C))


#define WGM10  0
#define WGM11  1
#define WGM12  3
#define WGM13  4
#define COM1A0 6
#define COM1A1 7
#define COM1B0 4
#define COM1B1 5
#define CS10   0
#define CS11   1
#define CS12   2
#define TOIE1 2

void EnableGlobalInterrupt();
void delay_Init();
void delay_3_Seconds();
void EnableInterruptTimer1();
void DisableInterruptTimer1();
void timer_stop();
void timer_start();
#endif /* TIMER1_H_ */