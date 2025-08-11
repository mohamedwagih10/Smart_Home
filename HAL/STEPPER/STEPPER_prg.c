/*
 * STEPPER_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */


#include "../../MCAL/DIO/DIO_int.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "STEPPER_cfg.h"
#include "STEPPER_int.h"
#include "STEPPER_prv.h"
#include <util/delay.h>

static const u8 CGA_u8FullStep[4]={1,2,4,8};

static const u8 CGA_u8HalfStep[8]={9,1,3,2,6,4,12,8};

static void HSTEPPER_svMotorCW(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle);
static void HSTEPPER_svMotorCCW(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle);

extern Stepper_Motor_cfg_t    Motor[NUMBER_OF_Motor];
void HSTEPPER_vInit(){
   for (u8 L_u8iterator =0; L_u8iterator<NUMBER_OF_Motor; L_u8iterator++ ){
	   for(u8 L_u8SecIterator=0; L_u8SecIterator < 4; L_u8SecIterator++){
		   MDIO_voidSetPinDir(Motor[L_u8SecIterator].PortNum[L_u8SecIterator],Motor[L_u8SecIterator].PinNum[L_u8SecIterator],DIO_OUTPUT);
		   MDIO_voidSetPinVal(Motor[L_u8SecIterator].PortNum[L_u8SecIterator],Motor[L_u8SecIterator].PinNum[L_u8SecIterator],DIO_LOW);
	   }
   }

}

static void HSTEPPER_svMotorCW(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle)
{
#if TYPE == FULL

	f64 L_f64Angle = (f64)A_u16Angle/(STEP);
	L_f64Angle = L_f64Angle/4.0;
	for(u32 L_u32i=0;L_u32i<(u32)L_f64Angle;L_u32i++)
	{
		for(u8 L_u8J=0;L_u8J<4;L_u8J++)
		{
			MDIO_voidSetPinVal(A_SMotor->PortNum[orange],A_SMotor->PinNum[orange],GET_BIT(CGA_u8FullStep[L_u8J],0));
			MDIO_voidSetPinVal(A_SMotor->PortNum[yellow],A_SMotor->PinNum[yellow],GET_BIT(CGA_u8FullStep[L_u8J],1));
			MDIO_voidSetPinVal(A_SMotor->PortNum[pink],A_SMotor->PinNum[pink],GET_BIT(CGA_u8FullStep[L_u8J],2));
			MDIO_voidSetPinVal(A_SMotor->PortNum[blue],A_SMotor->PinNum[blue],GET_BIT(CGA_u8FullStep[L_u8J],3));
			_delay_ms(DELAY_OF_STEP_IN_ML);
		}

	}
#elif  TYPE == HALF
	f64 L_f64Angle = (f64)A_u16Angle/(STEP);
	L_f64Angle = L_f64Angle/8.0;
	for(u32 L_u32i=0;L_u32i<(u32)L_f64Angle;L_u32i++)
	{
		for(u8 L_u8J=0;L_u8J<8;L_u8J++)
		{
			MDIO_voidSetPinVal(A_SMotor->PortNum[orange],A_SMotor->PinNum[orange],GET_BIT(CGA_u8HalfStep[L_u8J],0));
			MDIO_voidSetPinVal(A_SMotor->PortNum[yellow],A_SMotor->PinNum[yellow],GET_BIT(CGA_u8HalfStep[L_u8J],1));
			MDIO_voidSetPinVal(A_SMotor->PortNum[pink],A_SMotor->PinNum[pink],GET_BIT(CGA_u8HalfStep[L_u8J],2));
			MDIO_voidSetPinVal(A_SMotor->PortNum[blue],A_SMotor->PinNum[blue],GET_BIT(CGA_u8HalfStep[L_u8J],3));
			_delay_ms(DELAY_OF_STEP_IN_ML);
		}

	}
#endif
}
static void HSTEPPER_svMotorCCW(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle)
{
#if TYPE == FULL
	f64 L_f64Angle = (f64)A_u16Angle/(STEP);
	L_f64Angle = L_f64Angle/4.0;
	for(u32 L_u32i=0;L_u32i<(u32)L_f64Angle;L_u32i++)
	{
		for(u8 L_u8J=4;L_u8J>0;L_u8J--)
		{
			MDIO_voidSetPinVal(A_SMotor->PortNum[orange],A_SMotor->PinNum[orange],GET_BIT(CGA_u8FullStep[L_u8J-1],0));
			MDIO_voidSetPinVal(A_SMotor->PortNum[yellow],A_SMotor->PinNum[yellow],GET_BIT(CGA_u8FullStep[L_u8J-1],1));
			MDIO_voidSetPinVal(A_SMotor->PortNum[pink],A_SMotor->PinNum[pink],GET_BIT(CGA_u8FullStep[L_u8J-1],2));
			MDIO_voidSetPinVal(A_SMotor->PortNum[blue],A_SMotor->PinNum[blue],GET_BIT(CGA_u8FullStep[L_u8J-1],3));
			_delay_ms(DELAY_OF_STEP_IN_ML);
		}

	}
#elif  TYPE == HALF
	f64 L_f64Angle = (f64)A_u16Angle/(STEP);
		L_f64Angle = L_f64Angle/8.0;
		for(u32 L_u32i=0;L_u32i<(u32)L_f64Angle;L_u32i++)
		{
			for(u8 L_u8J=8;L_u8J>0;L_u8J--)
			{
				MDIO_voidSetPinVal(A_SMotor->PortNum[orange],A_SMotor->PinNum[orange],GET_BIT(CGA_u8HalfStep[L_u8J-1],0));
				MDIO_voidSetPinVal(A_SMotor->PortNum[yellow],A_SMotor->PinNum[yellow],GET_BIT(CGA_u8HalfStep[L_u8J-1],1));
				MDIO_voidSetPinVal(A_SMotor->PortNum[pink],A_SMotor->PinNum[pink],GET_BIT(CGA_u8HalfStep[L_u8J-1],2));
				MDIO_voidSetPinVal(A_SMotor->PortNum[blue],A_SMotor->PinNum[blue],GET_BIT(CGA_u8HalfStep[L_u8J-1],3));
				_delay_ms(DELAY_OF_STEP_IN_ML);
			}

		}
#endif
}
void HSTEPPER_vAngle(Stepper_Motor_cfg_t *A_SMotor,u16 A_u16Angle)
{
	if(A_u16Angle>360)
	{
		A_u16Angle = A_u16Angle -360;
	}
	if(A_u16Angle > (A_SMotor->InitialAngle)  )
	{
		HSTEPPER_svMotorCW(A_SMotor,(A_u16Angle-(A_SMotor->InitialAngle)));
		A_SMotor->InitialAngle = A_u16Angle ;
	}
	else
	{
		HSTEPPER_svMotorCCW(A_SMotor,(A_SMotor->InitialAngle-(A_u16Angle)));
		A_SMotor->InitialAngle = A_u16Angle ;
	}
}
