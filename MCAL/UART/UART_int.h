/*
 * UART_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void UART_vInit();

void UART_vSend(u16 A_u8Data);
u16 UART_vRecive();
u8 UART_u8ReadNonBlocking(void);
u8 UART_u8IsDataAvailable(void);
#endif /* MCAL_UART_UART_INT_H_ */
