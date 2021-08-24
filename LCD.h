/*
 * LCD.h
 *
 * Created: 1/15/2020 11:05:03 AM
 *  Author: hp
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "GPIO.h"
#include "StandardTypes.h"





/*LCD Control PORT */

#define		LCD_Control_Port	GPIOD
#define		RS			PIN5		
#define		RW			PIN6
#define		E			PIN7
/* LCD DATA PORT */
#define		LCD_Data_Port	    GPIOC
/* LCD Config */
#define		Return_Home							0x02
#define		Clear_Display						0x01
#define		_8bit_2Lines_5x8Font				0x38
#define		DisplayOn_CursorOff_BlinkCursorOff	0x0C
#define		CursorMovesRight					0x06
#define		_4bit_2Lines_5x8Font				0x28		


void LCD_Init(void);
void LCD_WriteChar(u8 Char);
void LCD_MoveCursor(u8 x,u8 y);
void LCD_WriteSentence(const u8* Sentence);
void LCD_Clear(void);
void LCD_WriteNumber(u64 Number);


#endif /* LCD_H_ */