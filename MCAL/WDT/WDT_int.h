/*
 * WDT_int.h
 *
 *  Created on: Jul 31, 2025
 *      Author: bahgt
 */

#ifndef MCAL_WDT_WDT_INT_H_
#define MCAL_WDT_WDT_INT_H_


/*WDT prescaller*/
#define WDT_16ms3   0
#define WDT_32ms5   1
#define WDT_65ms0   2
#define WDT_0s13    3
#define WDT_0s26    4
#define WDT_0s52    5
#define WDT_1s0     6
#define WDT_2s1     7

void MWDT_vTurnOn  (u8 A_u8TimeOut);
void MWDT_vTurnOff (void);


#endif /* MCAL_WDT_WDT_INT_H_ */
