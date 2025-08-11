/*
 * SPI_prg.C
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_prv.h"
#include "../DIO/DIO_int.h"
#include <util/delay.h>
#define F_CPU 8000000UL /*frequancy of mc*/


void MSPI_vInit(void)
{
#if    SPI_TYPE == MASTER
	/*Set SS as output pins for master*/
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);
	/*Set MOSI as output pins for master*/
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);
	/*Set SCK  as output pins for master*/
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to master */
#if    SPI_CLOCK_RATE == PRESCALLER_4 /*fosc/4*/
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_16 /*fosc/16*/
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_64 /*fosc/64*/
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_128 /*fosc/128*/
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_2 /*fosc/2*/
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_8 /*fosc/8*/
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif  SPI_CLOCK_RATE == PRESCALLER_32 /*fosc/32*/
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#else
#error "select correct option of SPI_CLOCK_RATE"
#endif
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*set SS to high*/
	MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
	/*wait until other peripherals be initialized */
	_delay_ms(300);
#elif  SPI_MODE == SPI_SLAVE
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	MDIO_voidSetPinDir(DIO_PORTB , DIO_PIN6 , DIO_OUTPUT);
#else
#error "select correct option of SPI_MODE"
#endif
}

void MSPI_vMasterTransmitChar(u8 A_u8Data)
{

	/*Clear SS to send data to slave*/
	MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
	/*Put data on SPDR*/
	SPDR=A_u8Data;
	/*Wait until data is received in SPI register*/
	while(GET_BIT(SPSR,SPIF)==0);
}

void MSPI_vMasterTransmitString(u8* A_pu8Str)
{
	while(*A_pu8Str != '\0')
	{
		MSPI_vMasterTransmitChar(*A_pu8Str);
		A_pu8Str++ ;
	}
	MSPI_vMasterTransmitChar('\n');
}

u8 MSPI_u8SlaveReceivechar(void)
{
	/*Put dummy data on SPDR*/
	/*Wait until data is received in SPI register*/
	while(GET_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	return SPDR ;
}

void MSPI_vReceiveString(u8 A_u8Str[])
{
	u32 L_u32Index = 0 ;
	while (1)
	{
		A_u8Str[L_u32Index]=MSPI_u8SlaveReceivechar();
		if(A_u8Str[L_u32Index] == '\n' || A_u8Str[L_u32Index]=='\r' )
		{
			A_u8Str[L_u32Index]='\0';
			break;
		}
		L_u32Index ++ ;
	}
}


