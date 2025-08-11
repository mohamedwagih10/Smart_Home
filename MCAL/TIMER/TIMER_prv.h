/*
 * TIMER_prv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_TIMER_TIMER_PRV_H_
#define MCAL_TIMER_TIMER_PRV_H_

#define TCCR0 (*((volatile u8 *)(0x53)))
#define TCNT0 (*((volatile u8 *)(0x52)))
#define TIMSK (*((volatile u8 *)(0x59)))
#define TIFR (*((volatile u8 *)(0x58)))
#define OCR0 (*((volatile u8 *)(0x5C)))

#define WGM01 3
#define WGM00 6

#define TOIE0 0
#define TOIE1 1

#define TOV0 0

#define OCIE0

#define TCCR1A (*((volatile u8 *)(0x4F)))
#define TCCR1B (*((volatile u8 *)(0x4E)))
#define TCNT1 (*((volatile u16 *)(0x4C)))
#define OCR1A (*((volatile u16 *)(0x4A)))
#define OCR1B (*((volatile u16 *)(0x48)))
#define ICR1 (*((volatile u16 *)(0x46)))
#endif /* MCAL_TIMER_TIMER_PRV_H_ */
