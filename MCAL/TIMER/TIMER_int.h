/*
 * TIMER_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_
#include "../../LIB/STD_TYPES.h"
void MTIMER0_vInit(void);
void MTIMER0_vPreloadValue(u8 A_u8Preloade);
void MTIMER0_vStart(void);
void MTIMER0_vStop(void);

void MTIMER0_vSetCallBackAddress( void (*A_fPtr) (void));

/*CTC Timer0*/
void MTIMER0_vInit_CTC(void);
void MTIMER0_vSetIntervalValue(u32 A_u32NumOfTick);
void MTIMER0_vSetCallBackAddress_CTC( void (*A_fPtr) (void));
void MTIMER0_vSetCompareMatch(u8 A_u8ComparVal);


/*PWM timer0*/
void MTIMER0_vInit_PWM (void);
void MTIMER0_vSetDutyCycle (u8 A_u8Duty) ;

/*PWM timer1 for Servo */
void MTIMER1A_vInit_PWM(void);
void MTIMER1A_vSetCompareMatchValue(u16 A_u16ComparVal);
void MTIMER1A_vSetCompareMatchValueServoB(u16 A_u16ComparVal);
#define ICU_FAILING   0
#define ICU_RISING    1

/*ICU*/
void MICU_vInit(void);
void MICU_vEnableInterrupt(void);
void MICU_vDisableInterrupt(void);
u16 MICU_u16GetCaptureValue(void);
void MICU_vSetTrigger(u8 A_u8Trigger);
void MICU_vSetCallBack( void (*ptr) (void));

#endif /* MCAL_TIMER_TIMER_INT_H_ */
