/*
 * UART_prg.c
 *
 *  Created on: ??ώ/??ώ/????
 *      Author: Dell
 */

#include "../DIO/DIO_int.h"
#include "UART_int.h"
#include "UART_prv.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void UART_vInit(){
UCSRB = 0b00011000;
UCSRC = 0b10000110;
		//UBRRH = 0b0
UBRRL = 51; // low51 <255 9600

}

void UART_vSend(u16 A_u8Data){
	{
	/* Wait for empty transmit buffer */
	while ( GET_BIT(UCSRA,UDRE) !=1); // CHECK GIBT ES DATA
	/* Put data into buffer, sends the data */
	UDR = A_u8Data;
}
}
u16 UART_vRecive(){

	/* Wait for data to be received */
	while ( GET_BIT(UCSRA,RXC) !=1 ) ; // GET_BIT(UCSRA,RXC0!=1)
	/* Get and return received data from buffer */
	return UDR;
}
u8 UART_u8IsDataAvailable(void) {
    return (UCSRA & (1 << RXC)); // αζ RXC=1
}
u8 UART_u8ReadNonBlocking(void) {
    if (UART_u8IsDataAvailable()) {
        return (u8)UART_vRecive();
    }
    return 0;
}
