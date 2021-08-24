/*
 * LCD.c
 *
 * Created: 1/15/2020 11:04:52 AM
 *  Author: hp
 */ 
#define F_CPU	8000000
#include "LCD.h"
#include <util/delay.h>
static void LCD_WriteCommand(u8 command)
{
	
		/* First For instruction Register RS=0 */
		Output(LCD_Control_Port,LOW,RS);
		/* Second For write RW=0 */
		Output(LCD_Control_Port,LOW,RW);
		_delay_ms(1);
		/*Third Set E to high*/
		Output(LCD_Control_Port,HIGH,E);
		_delay_ms(1);
				/* Forth PUT command in LCD_Data_Port */
		LCD_Data_Port->Port.AllRegister=command;
		/* Fifth Clear E */
		Output(LCD_Control_Port,LOW,E);
		_delay_ms(1);
			
		
}


void LCD_Init()
{
	
	/* Delay said in DataSheet */
		_delay_ms(50);
	/* Initialization of RS,RW,E */
		SetDataDirection(LCD_Control_Port,output,RS);
		SetDataDirection(LCD_Control_Port,output,RW);
		SetDataDirection(LCD_Control_Port,output,E);	

		/* Initialization of DataPort as Output*/
			AllPortOutput(LCD_Data_Port);
		/*	Send Command to clear Display*/
			LCD_WriteCommand(Clear_Display);
			_delay_ms(20);
		/* Function Set part */
			LCD_WriteCommand(_8bit_2Lines_5x8Font);
			_delay_ms(1);
		/*Display Part*/
			LCD_WriteCommand(DisplayOn_CursorOff_BlinkCursorOff);
			_delay_ms(1);
		/*Entry Part*/
			LCD_WriteCommand(CursorMovesRight);
			_delay_ms(1);	
		

	
}






void LCD_WriteChar(u8 Char)
{
	
	/* First For Data Register RS=1 */
		Output(LCD_Control_Port,HIGH,RS);
	/* Second For write RW=0 */
		Output(LCD_Control_Port,LOW,RW);
		_delay_ms(1);
	/*Third Set E to high*/
		Output(LCD_Control_Port,HIGH,E);
		_delay_ms(1);

	/* Forth PUT command in LCD_Data_Port */
		LCD_Data_Port->Port.AllRegister =Char;
	/* Fifth Clear E */
		Output(LCD_Control_Port,LOW,E);
		_delay_ms(1);	
		
	
	
	
}




void LCD_WriteSentence(const u8 *Sentence)
{
	
	for(u8 i=0;Sentence[i];i++)
	{
		
		LCD_WriteChar(Sentence[i]);
		
	}
	
}

void LCD_Clear()
{

	/*	Send Command to clear Display*/
	LCD_WriteCommand(Clear_Display);
	_delay_ms(20);	
	
}


void LCD_WriteNumber(u64 Number)
{
	u8 i=0;
	u8 arr[64];
	while(Number)
	{
		arr[i]=( Number%10 )+'0';
		Number/=10;
		i++;
	}
	for(u8 j=0;j<i;j++)
	{
		LCD_WriteChar(arr[i-j-1]);
	}
	
}






void LCD_MoveCursor(u8 x,u8 y)
{
	
	if(y==0)
	{
		if (x>=0 && x<16)
		{
				
			LCD_WriteCommand(0x80+x);
			
		}
		
	}
	else if(y==1)
	{
		
		if (x>=0 && x<16)
		{
					
			LCD_WriteCommand(0xC0+x);
					
		}
		
	}

}







