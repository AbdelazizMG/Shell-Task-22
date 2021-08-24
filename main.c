/*
 * main.c
 *
 * Created: 2021-08-22 11:49:33 AM
 *  Author: Abdelaziz Mohammed
 */ 



#include "StandardTypes.h"
#include "Macros.h"
#include "GPIO.h"
#include "LCD.h"
#include "UART_Tx.h"
#include "Timer1.h"
#include <avr/interrupt.h>




u8 delay_Flag = 1;         /// Delay Flag for 3 seconds delay
u8 Flag_Tx = 2;            /* Flag to be sent by UART to the other MCU, if Flag_Tx = 1 : Busy  , Flag_Tx = 0 : hungry */
u8 Flag_Rx = '.';          /* Flag to save data received from other MCU */
u8 Flag_Button_Click =1;   /* Flag to disable Buttons when unwanted */

///Program Entry point
int main(void)
{
	///Setting Push Buttons Pins to be input
	SetDataDirection(GPIOA,PullUp,PIN0);  //Hungry Button
	SetDataDirection(GPIOA,PullUp,PIN1);  //Busy   Button

	
	/* LCD ,UART and delay function initialization*/
	UART_init(Transmitter);
	LCD_Init();
	delay_Init();
	EnableGlobalInterrupt();
	EnableInterruptTimer1();
	delay_3_Seconds();
	
	
	/*Ideal State*/
	LCD_WriteSentence((const u8*)"Choose Question:");
	LCD_MoveCursor(0,1);
	LCD_WriteSentence((const u8*)"1.Busy, 2.Hungry");
	
    while(1)
    {
		
       if(delay_Flag==1)
	   {
				
					timer_stop();
			if(CheckBit(GPIOA->PIN.AllRegister,PIN0) && Flag_Button_Click)      //if Push Button 1 pressed
			{
				LCD_Clear();
				LCD_WriteSentence((const u8*)"Asked if Hungry");
				LCD_MoveCursor(0,1);
				LCD_WriteSentence((const u8*)"waiting answer");
				Flag_Tx=0;
				Flag_Button_Click=0;
			}
			if(CheckBit(GPIOA->PIN.AllRegister,PIN1)&& Flag_Button_Click)       //if Push Button 2 pressed
			{
				LCD_Clear();
				LCD_WriteSentence((const u8*)"Asked if Busy");
				LCD_MoveCursor(0,1);
				LCD_WriteSentence((const u8*)"waiting answer");
				Flag_Tx=1;
				Flag_Button_Click=0;
				
			}
			UART_SendChar(Flag_Tx);      // Sending the chosen question to other MCU
			Flag_Tx=2;                   // Resetting Transmitted value Flag
			
			
			
			UART_init(Receiver);         // Reinitialize UART to be receiver
			Flag_Rx= UART_ReceiveChar(); // Receiving the answer from other MCU
			
			if(Flag_Rx != '.' && Flag_Rx != 2)
			{
				if(Flag_Rx == 0)         //Displaying First answer option
				{
					LCD_Clear();
					LCD_WriteSentence((const u8*)"Yes, i am");	
				}
				else if (Flag_Rx == 1)  //Displaying Second answer option
				{
					LCD_Clear();
					LCD_WriteSentence((const u8*)"No, i am not");
				}
				//_delay_ms(5000);       //Delay 5 seconds
				
				
				
				delay_Flag=0;
				delay_Init();
				
				/*Return to Ideal State with Setting Flags*/
				
				
			}
	   }
    }
}

ISR(TIMER1_COMPA_vect)
{
	LCD_Clear();
	LCD_WriteSentence((const u8*)"Choose Question:");
	LCD_MoveCursor(0,1);
	LCD_WriteSentence((const u8*)"1.Busy, 2.Hungry");
	Flag_Button_Click =1;	Flag_Rx = '.';  Flag_Tx = 2;
	delay_Flag=1;
	
	TCNT=0;
}