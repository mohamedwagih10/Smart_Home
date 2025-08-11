/*
 * WDT_prv.h
 *
 *  Created on: Jul 31, 2025
 *      Author: bahgt
 */

#ifndef MCAL_WDT_WDT_PRV_H_
#define MCAL_WDT_WDT_PRV_H_


#define WDTCR   *((volatile u8 *)(0x41))


#define WDP0  0
#define WDP1  1
#define WDP2  2
#define WDE   3
#define WDTOE 4

#define WDT_DISABLE 0b11000


#endif /* MCAL_WDT_WDT_PRV_H_ */
