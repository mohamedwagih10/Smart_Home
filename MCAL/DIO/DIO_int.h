/*
 * DIO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../../LIB/STD_TYPES.h"
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_


#define DIO_PORTA 'A' // A
#define DIO_PORTB 'B' //B
#define DIO_PORTC 'C' // C
#define DIO_PORTD 'D' //D

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_HIGH 1
#define DIO_LOW 0

//DDR
void MDIO_voidSetPinDir(u8 A_u8PorNum , u8 A_u8PinNum , u8 A_u8Dir);
void MDIO_voidSetPortDir(u8 A_u8PortNum , u8 A_u8PortDir);
//PORT
void MDIO_voidSetPinVal(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinVal);
void MDIO_voidSetPortVal(u8 A_u8PortNum,u8 A_u8PortVal);
//pin
s8 MDIO_s8GetPinVal(u8 A_u8PortNum , u8 A_u8PinNum);
s8 MDIO_s8GetPortVal(u8 A_u8PortNum);
#endif /* MCAL_DIO_DIO_INT_H_ */
