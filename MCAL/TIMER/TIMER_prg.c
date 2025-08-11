/*
 * TIMER_prg.c
 *
 *  Created on: Jul 27, 2025
 *      Author: bahgt
 */
#include "../../LIB/BIT_MATH.h"

#include "TIMER_prv.h"
#include "TIMER_int.h"
#include "TIMER_cfg.h"
#include "../DIO/DIO_int.h"
u32 G_u32Counter = 0;
void (* G_fSetCalBack) (void) = NULL;
void (*ICU_SetCallBack) (void) =NULL;
void MTIMER0_vInit(void)
{
	/*Choose your mode */
	TCCR0 = 0b00000000;
	/*Enable Interrupt */
	SET_BIT(TIMSK,TOIE0);

}

void MTIMER0_vPreloadValue(u8 A_u8Preloade)
{
	TCNT0 = A_u8Preloade;
}

void MTIMER0_vStart(void)
{
	TCCR0 = (TCCR0 & (0xF8)) |(TIMER0_PRESCALER & (0x07));
}
void MTIMER0_vStop(void)
{
	TCCR0 = (TCCR0 & (0xF8));
}

void MTIMER0_vSetIntervalValue(u32 A_u32NumOfTick)
{
	G_u32Counter = A_u32NumOfTick;
}

void MTIMER0_vSetCallBackAddress( void (*A_fPtr) (void))
{
	G_fSetCalBack = A_fPtr;//100
}





void MTIMER0_vInit_CTC(void)
{
	TCCR0 = 0b00001000; // Mode = CTC   Ps = Off

	/*Enable CTC Interrupt */
	SET_BIT(TIMSK,1);
}

void (*SetCallBack_CTC) (void) = NULL ;
void MTIMER0_vSetCallBackAddress_CTC( void (*A_fPtr) (void))
{
	SetCallBack_CTC =A_fPtr;
}
void MTIMER0_vSetCompareMatch(u8 A_u8ComparVal)
{
	OCR0 = A_u8ComparVal;
}
void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	static u32 count=0;
	count++;
	if(count >=G_u32Counter )
	{
		count=0;
		if(SetCallBack_CTC != NULL)  SetCallBack_CTC();



	}
}




void MTIMER0_vInit_PWM (void)
{
	MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	TCCR0 = 0b01101000 ;
	/*Disable Interrupt*/

	CLR_BIT(TIMSK,1);
}

void MTIMER0_vSetDutyCycle (u8 A_u8Duty)
{
//	if (A_u8Duty > 100) A_u8Duty = 100;
//	OCR0 = (A_u8Duty*255UL) /100 ;
	MTIMER0_vStart();
//	while(GET_BIT(TIFR,1) != 1);
//	MTIMER0_vStop();
//	/*Clear flag*/
//	SET_BIT(TIFR,1);
	OCR0 = A_u8Duty;

}


/*Timer1A*/


void MTIMER1A_vInit_PWM(void)
{
	MDIO_voidSetPinDir(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	MDIO_voidSetPinDir(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);
	TCCR1A =0b10000010 ;
	TCCR1B =0b00011010 ;
	ICR1 = 20000 ;
}
void MTIMER1A_vSetCompareMatchValue(u16 A_u16ComparVal)
{

	if (A_u16ComparVal >20000UL) A_u16ComparVal =20000;
	OCR1A = A_u16ComparVal ;
}
void MTIMER1A_vSetCompareMatchValueServoB(u16 A_u16ComparVal){
	if (A_u16ComparVal >20000UL) A_u16ComparVal =20000;
		OCR1B = A_u16ComparVal ;
}



/*ICU*/
void MICU_vInit(void)
{
	TCCR1A = 0 ;
	TCCR1B = 0b01000010;
	MICU_vEnableInterrupt();
}
void MICU_vEnableInterrupt(void)
{
	SET_BIT(TIMSK,5);
}
void MICU_vDisableInterrupt(void)
{
	CLR_BIT(TIMSK,5);
}
u16 MICU_u16GetCaptureValue(void)
{
	return ICR1 ;
}
void MICU_vSetTrigger(u8 A_u8Trigger)
{
	switch(A_u8Trigger)
	{
	case ICU_FAILING :
		CLR_BIT(TCCR1B,6);
		break;
	case ICU_RISING :
		SET_BIT(TCCR1B,6);
		break;
	}
}

void MICU_vSetCallBack( void (*ptr) (void))
{
	ICU_SetCallBack = ptr;
}
void __vector_6 (void)  __attribute__((signal));
void __vector_6 (void)
{
	ICU_SetCallBack();
}











void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{
	static u32 count=0;
	count++;
	if(count >=G_u32Counter )
	{
		count=0;
		if(G_fSetCalBack != NULL)  G_fSetCalBack();



	}
}



