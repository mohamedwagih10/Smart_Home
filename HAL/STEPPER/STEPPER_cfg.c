/*
 * STEPPER_cfg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */


#include "../../LIB/STD_TYPES.h"
#include "STEPPER_int.h"
#include "STEPPER_cfg.h"
#include "STEPPER_prv.h"
#include "../../MCAL/DIO/DIO_int.h"


Stepper_Motor_cfg_t    Motor[NUMBER_OF_Motor] ={
		{
	     .InitialAngle = 0,
	    .PortNum[orange] =DIO_PORTD , .PinNum[orange]= DIO_PIN0,
		.PortNum[yellow] =DIO_PORTD , .PinNum[yellow]= DIO_PIN1,
		.PortNum[pink] =DIO_PORTD   , .PinNum[pink]= DIO_PIN2,
		.PortNum[blue] =DIO_PORTD   , .PinNum[blue]= DIO_PIN3},
};
