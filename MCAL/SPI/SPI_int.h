/*
 * SPI_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void MSPI_vInit(void);
void MSPI_vMasterTransmitChar(u8 A_u8Data);
void MSPI_vMasterTransmitString(u8* A_pu8Str);
u8   MSPI_u8SlaveReceivechar(void) ;
void MSPI_vReceiveString(u8 A_u8Str[]);
#endif /* MCAL_SPI_SPI_INT_H_ */
