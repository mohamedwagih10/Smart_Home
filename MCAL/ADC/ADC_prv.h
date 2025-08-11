#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define ADMUX   (*(volatile u8*)(0x27))
#define ADCSRA  (*(volatile u8*)(0x26))
#define ADC     (*(volatile u16*)(0x24))

#define AVCC    1
#define AREF    2
#define V2_65   3

#define P_2     (u8)0b010
#define P_64    (u8)0b110

#endif /* MCAL_ADC_ADC_PRV_H_ */

