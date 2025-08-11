/*
 * ADC_prg.c
 *
 *  Created on: Jul 24, 2025
 *      Author: bahgt
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"

void MADC_vInit(void)
{
    /* 1- Vref Selection */
#if ADC_REF == AVCC
    SET_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
#elif ADC_REF == AREF
    CLR_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);
#elif ADC_REF == V2_65
    SET_BIT(ADMUX, 6);
    SET_BIT(ADMUX, 7);
#endif

    /* 2- Data Adjustment direction = Right Adjust */
    CLR_BIT(ADMUX, 5);

    /* 3- Select Prescaler */
    ADCSRA = (ADCSRA & 0b11111000) | PRESCALER;

    /* 4- Auto Trigger Disabled */
    CLR_BIT(ADCSRA, 5);

    /* 5- Interrupt Disabled */
    CLR_BIT(ADCSRA, 3);

    /* 6- Enable ADC */
    SET_BIT(ADCSRA, 7);
}

u16 MADC_u16AnalogRead(u8 A_u8ChannelNum)
{
    /* 1- Select ADC Channel */
    ADMUX = (ADMUX & 0b11100000) | (A_u8ChannelNum & 0x07);

    /* 2- Start Conversion */
    SET_BIT(ADCSRA, 6);

    /* 3- Wait for conversion complete */
    while (GET_BIT(ADCSRA, 4) == 0);

    /* 4- Clear the flag by writing 1 */
    SET_BIT(ADCSRA, 4);

    /* 5- Return ADC value */
    return ADC;
}
