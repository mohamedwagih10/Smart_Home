/*
 * DIO_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_prv.h"

//DDR
void MDIO_voidSetPinDir(u8 A_u8PorNum , u8 A_u8PinNum , u8 A_u8Dir){
    if(A_u8PinNum >= 0 && A_u8PinNum <= 7){
        switch(A_u8PorNum){
            case DIO_PORTA:
                if(A_u8Dir == DIO_OUTPUT)
                    SET_BIT(DDRA, A_u8PinNum);
                else
                    CLR_BIT(DDRA, A_u8PinNum);
                break;

            case DIO_PORTB:
                if(A_u8Dir == DIO_OUTPUT)
                    SET_BIT(DDRB, A_u8PinNum);
                else
                    CLR_BIT(DDRB, A_u8PinNum);
                break;

            case DIO_PORTC:
                if(A_u8Dir == DIO_OUTPUT)
                    SET_BIT(DDRC, A_u8PinNum);
                else
                    CLR_BIT(DDRC, A_u8PinNum);
                break;

            case DIO_PORTD:
                if(A_u8Dir == DIO_OUTPUT)
                    SET_BIT(DDRD, A_u8PinNum);
                else
                    CLR_BIT(DDRD, A_u8PinNum);
                break;
        }
    }
}



void MDIO_voidSetPortDir(u8 A_u8PortNum , u8 A_u8PortDir){
switch(A_u8PortNum){
case DIO_PORTA: DDRA = A_u8PortDir; break;
case DIO_PORTB: DDRB = A_u8PortDir; break;
case DIO_PORTC: DDRC = A_u8PortDir; break;
case DIO_PORTD: DDRD = A_u8PortDir; break;
}

}
//PORT
void MDIO_voidSetPinVal(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinVal){
	if(A_u8PinNum>=0 && A_u8PinNum<=7){
		switch(A_u8PortNum){
		case DIO_PORTA:
			if(A_u8PinVal == DIO_HIGH){
				SET_BIT(PORTA,A_u8PinNum);
			}
			else{
				CLR_BIT(PORTA,A_u8PinNum);
			}
			break;
		case DIO_PORTB:
					if(A_u8PinVal == DIO_HIGH){
						SET_BIT(PORTB,A_u8PinNum);
					}
					else{
						CLR_BIT(PORTB,A_u8PinNum);
					}
					break;
		case DIO_PORTC:
					if(A_u8PinVal == DIO_HIGH){
						SET_BIT(PORTC,A_u8PinNum);
					}
					else{
						CLR_BIT(PORTC,A_u8PinNum);
					}
					break;
		case DIO_PORTD:
					if(A_u8PinVal == DIO_HIGH){
						SET_BIT(PORTD,A_u8PinNum);
					}
					else{
						CLR_BIT(PORTD,A_u8PinNum);
					}
					break;
		}
	}

}
void MDIO_voidSetPortVal(u8 A_u8PortNum,u8 A_u8PortVal){
	switch(A_u8PortNum){
	case DIO_PORTA: PORTA = A_u8PortVal; break;
	case DIO_PORTB: PORTB = A_u8PortVal; break;
	case DIO_PORTC: PORTC = A_u8PortVal; break;
	case DIO_PORTD: PORTD = A_u8PortVal; break;
	}
}
//pin
s8 MDIO_s8GetPinVal(u8 A_u8PortNum , u8 A_u8PinNum){
	s8 L_s8RetVal = -1;
	if(A_u8PinNum>=0 && A_u8PinNum<=7){
		switch(A_u8PortNum){
		case DIO_PORTA: L_s8RetVal = GET_BIT(PINA, A_u8PinNum);
			break;

		case DIO_PORTB: L_s8RetVal = GET_BIT(PINB, A_u8PinNum);
					break;

		case DIO_PORTC: L_s8RetVal = GET_BIT(PINC, A_u8PinNum);
					break;
		case DIO_PORTD: L_s8RetVal = GET_BIT(PIND, A_u8PinNum);
					break;
	}
	}

return L_s8RetVal;
}
s8 MDIO_s8GetPortVal(u8 A_u8PortNum){
	s8 L_s8RetVal = -1;
     switch(A_u8PortNum){
     case DIO_PORTA:L_s8RetVal=PINA; break;
     case DIO_PORTB: L_s8RetVal=PINB; break;
     case DIO_PORTC:L_s8RetVal=PINC; break;
     case DIO_PORTD:L_s8RetVal=PIND; break;
     }
return L_s8RetVal;
}

