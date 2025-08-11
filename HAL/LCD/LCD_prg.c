#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

static u8 CursorIndex = 0;

void HLCD_voidInit(void){
	MDIO_voidSetPortDir(LCD_DATA_PORT,0xFF);
	// RS RW EN
	MDIO_voidSetPinDir(LCD_CONTROLL,LCD_RS,DIO_OUTPUT);
	MDIO_voidSetPinDir(LCD_CONTROLL,LCD_RW,DIO_OUTPUT);
	MDIO_voidSetPinDir(LCD_CONTROLL,LCD_ENAble,DIO_OUTPUT);
	_delay_ms(50);
	//FUNCTION SET
	HLCD_voidSendCommand(0x38);
    _delay_ms(1);
	HLCD_voidSendCommand(0x0C);
    _delay_ms(1);
    // CLEAR
    HLCD_voidSendCommand(0x01);
    _delay_ms(2);
    // ENTRY MODE SET
    HLCD_voidSendCommand(0x06);
}


void HLCD_voidSendCommand(u8 A_u8Command){
	// RS =LOW
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_RS,DIO_LOW);
	// WRITE =LOW
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_RW,DIO_LOW);
	//SEND COMMAND
	MDIO_voidSetPortVal(LCD_DATA_PORT,A_u8Command);
	//ENABLE
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_ENAble,DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_ENAble,DIO_LOW);
	_delay_ms(1);
}


void HLCD_voidSetCurs(u8 Copy_u8Row, u8 Copy_u8Col) {
	if (Copy_u8Col <= 15) {
	        switch (Copy_u8Row) {
	            case 0:
	                HLCD_voidSendCommand(0x80 + Copy_u8Col);
	                CursorIndex =Copy_u8Col;
	                break;
	            case 1:
	                HLCD_voidSendCommand(0xC0 + Copy_u8Col);
	                CursorIndex =Copy_u8Col+16;
	                break;
	        }
	    }
}

void HLCD_voidSendChar(u8 A_u8Char){
	// RS =1
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_RS,DIO_HIGH);
	// RW =0
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_RW,DIO_LOW);
	// SEND DATA
	MDIO_voidSetPortVal(LCD_DATA_PORT,A_u8Char);
	//ENABLE
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_ENAble,DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinVal(LCD_CONTROLL,LCD_ENAble,DIO_LOW);
	_delay_ms(1);

	 CursorIndex++;
	    if (CursorIndex == 16){
	        HLCD_voidSetCurs(1, 0);}
	    else if (CursorIndex == 32)
	    {
	        HLCD_voidSetCurs(0, 0);
	        CursorIndex = 0;

}
}
void HLCD_voidPrintString(u8* Copy_pu8Str){
	  u8 i = 0;
	    while (Copy_pu8Str[i] != '\0') {
	        HLCD_voidSendChar(Copy_pu8Str[i]);
	        i++;
	    }
}
void HLCD_voidPrintNUM(u16 Copy_u8Num){
	  u8 arr[10];
	    u8 count = 0;

	    if (Copy_u8Num == 0) {
	        HLCD_voidSendChar('0');
	        return;
	    }

	    while (Copy_u8Num != 0) {
	        arr[count++] = Copy_u8Num % 10;
	        Copy_u8Num /= 10;
	    }

	    for (s8 i = count - 1; i >= 0; i--) {
	        HLCD_voidSendChar(arr[i] + '0');
	    }
}
void HLCD_voidClear(){
   HLCD_voidSendCommand(LCD_CLK_SCREEN);
   _delay_ms(2);
    CursorIndex = 0;
}
