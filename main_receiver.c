/*
 * main.c
 *
 * Created: 2021-08-23 3:41:20 AM
 *  Author: Abdelaziz Mohammad
 */ 

#include "StandardTypes.h"
#include "Macros.h"
#include "GPIO.h"
#include "LCD.h"
#include "UART_Tx.h"

int main(void)
{
	/*Setting Push Buttons Pins to be input*/
	SetDataDirection(GPIOA,PullUp,PIN0);        //Yes
	SetDataDirection(GPIOA,PullUp,PIN1);        //No
	LCD_Init();
	UART_init(Receiver);
	LCD_WriteSentence((const u8*)"waiting for");
	LCD_MoveCursor(0,1);
	LCD_WriteSentence((const u8*)"question");
	
	u8 Rx = '.';  u8 Tx = 2; u8 Flag_Button_Click =1;
    while(1)
    {
        Rx = UART_ReceiveChar();
		if(Rx != '.' && Rx != 2)
		{
			if(Rx == 0)  //Received Hungry
			{
				LCD_Clear();
				LCD_WriteSentence((const u8*)"Are you Hungry");
				LCD_MoveCursor(0,1);
				LCD_WriteSentence((const u8*)"1.yes 2.no");
				
			}
			else if (Rx ==1) //Received Busy
			{
				LCD_Clear();
				LCD_WriteSentence((const u8*)"Are you Busy");
				LCD_MoveCursor(0,1);
				LCD_WriteSentence((const u8*)"1.yes 2.no");
			}
		}
		if(  (CheckBit(GPIOA->PIN.AllRegister,PIN0) && Flag_Button_Click) )
		{
			LCD_Clear();
			LCD_WriteSentence((const u8*)"waiting for");
			LCD_MoveCursor(0,1);
			LCD_WriteSentence((const u8*)"question");
			Flag_Button_Click=0;
			Tx = 0 ; // Yes
			
		}
		else if (CheckBit(GPIOA->PIN.AllRegister,PIN1)&& Flag_Button_Click)
		{
			LCD_Clear();
			LCD_WriteSentence((const u8*)"waiting for");
			LCD_MoveCursor(0,1);
			LCD_WriteSentence((const u8*)"question");
			Flag_Button_Click=0;
			Tx = 1; //No
		}
		UART_init(Transmitter);
		UART_SendChar(Tx);
		Tx = 2;
		Flag_Button_Click=1;
		
		
    }
}