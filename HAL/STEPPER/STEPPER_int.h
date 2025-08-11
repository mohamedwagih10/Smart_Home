/*
 * STEPPER_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef HAL_STEPPER_STEPPER_INT_H_
#define HAL_STEPPER_STEPPER_INT_H_

#include "../../LIB/STD_TYPES.h"

typedef struct Stepper
{
	u8 PortNum[4];
	u8 PinNum[4];
	u16 InitialAngle;
}Stepper_Motor_cfg_t;

void HSTEPPER_vInit();
void HSTEPPER_vMoveAngle(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle);

extern Stepper_Motor_cfg_t Motor[];
#endif /* HAL_STEPPER_STEPPER_INT_H_ */
