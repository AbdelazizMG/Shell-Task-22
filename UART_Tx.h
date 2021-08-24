/*
 * UART_Tx.h
 *
 * Created: 2021-08-20 4:21:46 AM
 *  Author: sigmaa
 */ 


#ifndef UART_TX_H_
#define UART_TX_H_


#include "GPIO.h"
#include "StandardTypes.h"

#define UDR   ((Register*)0x2C) 
#define UCSRA ((Register*)0x2B)
#define UCSRB ((Register*)0x2A)
#define UCSRC ((Register*)0x40)
#define UBRRL ((Register*)0x29)
#define UBRRH ((Register*)0x40)


/* Special Bits */

#define RXC    7   /*Receive  Complete*/
#define TXC    6   /*Transmit Complete*/
#define UDRE   5   /*Data Register Empty*/
#define RXEN   4   /*Receive Enable*/
#define TXEN   3   /*Transmit Enable*/
#define UMP0		4
#define UMP1		5
#define UCSZ0		1
#define UCSZ1		2
#define UCSZ2		2
#define USBS		3


typedef enum
{
	
	Transmitter,
	Receiver,
}UART_Mode;


void UART_init(UART_Mode mode);
void UART_SendChar(u8 Data);
u8 UART_ReceiveChar(void);




#endif /* UART_TX_H_ */