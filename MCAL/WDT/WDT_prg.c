/*
 * WDT_prg.c
 *
 *  Created on: Jul 31, 2025
 *      Author: bahgt
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_int.h"
#include "WDT_prv.h"
void MWDT_vTurnOn  (u8 A_u8TimeOut)
{
	/*set time out */

	if (A_u8TimeOut == WDT_16ms3)
	{
		CLR_BIT (WDTCR , WDP0) ; /*prescaller 000 to reset after 16.3ms*/
		CLR_BIT (WDTCR , WDP1) ;
		CLR_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_32ms5)
	{
		SET_BIT (WDTCR , WDP0) ; /*prescaller 001 to reset after 32.5ms*/
		CLR_BIT (WDTCR , WDP1) ;
		CLR_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_65ms0)
	{
		CLR_BIT (WDTCR , WDP0) ; /*prescaller 010 to reset after 65ms*/
		SET_BIT (WDTCR , WDP1) ;
		CLR_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_0s13)
	{
		SET_BIT (WDTCR , WDP0) ; /*prescaller 011 to reset after 0.13s*/
		SET_BIT (WDTCR , WDP1) ;
		CLR_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_0s26)
	{
		CLR_BIT (WDTCR , WDP0) ; /*prescaller 000 to reset after 0.26s*/
		CLR_BIT (WDTCR , WDP1) ;
		SET_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_0s52)
	{
		SET_BIT (WDTCR , WDP0) ; /*prescaller 000 to reset after 0.52s*/
		CLR_BIT (WDTCR , WDP1) ;
		SET_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_1s0)
	{
		CLR_BIT (WDTCR , WDP0) ; /*prescaller 000 to reset after 1s*/
		SET_BIT (WDTCR , WDP1) ;
		SET_BIT (WDTCR , WDP2) ;
	}
	else if (A_u8TimeOut == WDT_2s1)
	{
		SET_BIT (WDTCR , WDP0) ; /*prescaller 000 to reset after 2.1s*/
		SET_BIT (WDTCR , WDP1) ;
		SET_BIT (WDTCR , WDP2) ;
	}

	/*Enable WDT*/
	SET_BIT (WDTCR , WDE) ;
}
void MWDT_vTurnOff (void)
{
	WDTCR = WDT_DISABLE ; /*set WDE and WDTOE in the same line*/
	WDTCR = 0 ; /*disable WDT*/
}
