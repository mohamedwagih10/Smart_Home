/*
 * LCD_int.h
 *
 *  Created by: WAGIH
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "../../LIB/STD_TYPES.h"
//init
void HLCD_voidInit(void);

//command
void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSetCurs(u8 Copy_u8Row, u8 Copy_u8Col);

//Data
void HLCD_voidSendChar(u8 A_u8Char);
void HLCD_voidPrintString(u8* Copy_pu8Str);
void HLCD_voidPrintNUM(u16 Copy_u8Num);
void HLCD_voidClear();
#endif /* HAL_LCD_LCD_INT_H_ */
