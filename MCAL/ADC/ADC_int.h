#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include "../../LIB/STD_TYPES.h"

#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7

void MADC_vInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNum);

#endif /* MCAL_ADC_ADC_INT_H_ */

