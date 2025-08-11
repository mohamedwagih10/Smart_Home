/*
 * I2C_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#define WRITE 0
#define READ 1
#define ACK 1
#define NACK 0

void MI2C_Init();
u8 MI2C_u8Start();
u8 MI2C_u8Stop();
void MI2C_VSendAddersse(u8 A_u8Addersse);
u8 MI2C_u8SendData(A_u8Data);
u8 MI2C_u8ReciveData(u8 *A_puRecive,u8 A_u8Ack);
u8 MI2C_u8GetStatus();

#endif /* MCAL_I2C_I2C_INT_H_ */
