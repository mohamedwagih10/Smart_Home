/*

 * SSD_prg.c
 *
 *  Created : byWAGIH
 *      Author: Dell
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_int.h"
#include "SSD_cfg.h"
#include "SSD_prv.h"

const u8 CGR_u8SsdNum[10] ={
		0x3F,     // 0
		0x06,
		0x5B,
		0x4f,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F       //9
};
void HSSD_vInit(void)
{
	MDIO_voidSetPortDir(SSD_PORT,0xFF);

}

// Display
void HSSD_vDisplayNum(u8 A_u8Num)
{
#if SSD_TYPE == COM_ANODE
	// Common Anode
	MDIO_voidSetPortVal(SSD_PORT,~CGR_u8SsdNum[A_u8Num]);
#elif SSD_TYPE == COM_CATHODE
	// Common cathode
	MDIO_voidSetPortVal(SSD_PORT,CGR_u8SsdNum[A_u8Num]);
#endif
}

void HSSD_vTurnOff(void)
{
#if SSD_TYPE == COM_ANODE
	// Common Anode
	MDIO_voidSetPortVal(SSD_PORT,0xFF);
#elif SSD_TYPE == COM_CATHODE
	// Common cathode
	MDIO_voidSetPortVal(SSD_PORT,0x00);
#endif
}
