/*
 * UART_Rx.c
 *
 * Created: 2021-08-20 4:22:00 AM
 *  Author: Abdelaziz Mohammad
 */ 

#include "UART_Tx.h"
#include "Macros.h"
void UART_init(UART_Mode mode)
{
	SetDataDirection(GPIOD,Floating,PIN0);  //Input  pin for Rx
	SetDataDirection(GPIOD,output,PIN1);    //Output pin for Tx
	
     if(mode == Transmitter)
	  SetBit(UCSRB->AllRegister,TXEN);        //Trasmitter Mode
     else if (mode == Receiver)
	  SetBit(UCSRB->AllRegister,RXEN);        //Receiver Mode
	  
	  /* No Parity */
	  ClearBit(UCSRC->AllRegister,UMP0);
      ClearBit(UCSRC->AllRegister,UMP1);
	
      /* 1 StopBit*/
	  ClearBit(UCSRC->AllRegister,USBS);
	  
	  /* 8_Bits */	
	  SetBit(UCSRC->AllRegister,UCSZ0);
	  SetBit(UCSRC->AllRegister,UCSZ1);
	  ClearBit(UCSRB->AllRegister,UCSZ2);
	  
	  /*For 9600 Baud Rate and 8MHz Freq*/
	  UBRRH->AllRegister=0;
	  UBRRL->AllRegister =51;
	  
}
void UART_SendChar(u8 Data)
{
	while(CheckBit(UCSRA->AllRegister,UDRE)==0); //when UDRE = 1 that means the register is empty and data is in shift register ready to be sent.
	UDR->AllRegister=Data;
}
u8 UART_ReceiveChar(void)
{
	while(CheckBit(UCSRA->AllRegister,RXC)==0);  //when RXC =1 that means there is data in UDR
	return UDR->AllRegister;
}