/*
 * I2C_prv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_I2C_I2C_PRV_H_
#define MCAL_I2C_I2C_PRV_H_

#define TWBR (*((volatile u8 *)(0x20)))

#define TWCR (*((volatile u8 *)(0x56)))

#define TWSR (*((volatile u8 *)(0x21)))

#define TWDR (*((volatile u8 *)(0x23)))

#define TWAR (*((volatile u8 *)(0x22)))

#define TWINT 1 // clear soft
#define TWEA 1 // ACK
#define TWSTA 1// start
#define TWSTO 1 // STOP


#endif /* MCAL_I2C_I2C_PRV_H_ */
