/*
 * EXTI_prv.h
 *
 *  Created by: WAGIH
 *      Author: Dell
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define MCUCR (*((volatile u8*)(0x55)))
#define MCUCSR (*((volatile u8*)(0X54)))
#define GIFR (*((volatile u8*)(0x5A)))
#define GICR (*((volatile u8*)(0x5B)))


#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6

#define INT0 6
#define INT1 7
#define INT2 5

#define falling 0
#define rising 1

#endif /* MCAL_EXTI_EXTI_PRV_H_ */
