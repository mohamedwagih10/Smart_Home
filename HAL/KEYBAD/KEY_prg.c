/*
 * KEY_prg.c
 *
 *  Created by: WAGIH
 *      Author: Dell
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "avr/delay.h"
#include "KEY_int.h"
#include "KEY_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"


const u8 CGR_u8KeyBad[4][4] = {
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
};

void HKEY_vInit(void) {
	MDIO_voidSetPortDir(KEY_BAD_PORT, 0x0F);
	MDIO_voidSetPortVal(KEY_BAD_PORT, 0xFF);
}

u8 HKEY_GetKeyBad(void) {
	u8 ReturnVal = 255;

	for (u8 col = 0; col < 4; col++) {

		MDIO_voidSetPortVal(KEY_BAD_PORT, 0xFF);

		MDIO_voidSetPinVal(KEY_BAD_PORT, col, DIO_LOW);

		for (u8 row = 0; row < 4; row++) {
			if (MDIO_s8GetPinVal(KEY_BAD_PORT, row + 4) == 0) {
				_delay_ms(20); // Debouncing
				if (MDIO_s8GetPinVal(KEY_BAD_PORT, row + 4) == 0) {
					ReturnVal = CGR_u8KeyBad[row][col];
					while (MDIO_s8GetPinVal(KEY_BAD_PORT, row + 4) == 0);
					return ReturnVal;
				}
			}
		}
	}

	return ReturnVal;
}




