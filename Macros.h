/*
 * Macros.h
 *
 * Created: 2021-08-18 10:44:55 AM
 *  Author: sigmaa
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SetBit(Reg,Bit) Reg |= (1<<Bit)
#define ClearBit(Reg,Bit) Reg &= ~(1<<Bit)
#define ToggleBit(Reg,Bit) Reg ^= (1<<Bit)
#define CheckBit(Reg,Bit)  ((Reg>>Bit) & 1)

#endif /* MACROS_H_ */