/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: Dell
 */
/*
 * main.c
 *
 *  Created BY: WAGIH
 *      Author: Dell
 */
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include "../HAL/KEYBAD/KEY_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

int main(){
	/*
	 * ADC
	 * STEP 5/1024
	 * VOLT ANLAOG *STEP
	 * LM35 10MV 1C
	 * LDR
	 * PINA5
	 * DARK LOW_VOLT LOW_ADC
	 * LIGHT HIGH_VOLT HIGH_ADC
	 * ONLY ONE CHANNEL USED IN ADC
	 */
	u8 pass[4]={'1','2','3','4'};
	u8 input_pass[4];
    u8 Blt=0;
    u8 KeyBad=0;
	u16 Value_of_ADC;
	f32 temp ,Analoge_voltage;
	u8 status=0;

	u16 Value_of_Ldr;

	MDIO_voidSetPinDir(DIO_PORTA,DIO_PIN5,DIO_INPUT); //LDR

	MDIO_voidSetPinDir(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
	//MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_HIGH); // MOTOR
	MDIO_voidSetPinDir(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
	//MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_HIGH); // LED
	u8 L_u8Letter;
	HKEY_vInit();

	HLCD_voidInit();
	MDIO_voidSetPinDir(DIO_PORTA,DIO_PIN4,DIO_INPUT); // LM35
	MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN4,DIO_HIGH);
	MADC_vInit();
	MTIMER1A_vInit_PWM(); // OCR1A PORTD
	UART_vInit();

	 HLCD_voidPrintString("1- Keypad");
	    HLCD_voidSetCurs(1,0);
	    HLCD_voidPrintString("2- Bluetooth");

	    u8 input_method = 0;
	    do {
	        input_method = HKEY_GetKeyBad();
	    } while(input_method == 0xFF);

	    HLCD_voidClear();
	    HLCD_voidPrintString("Enter Password:");
	    HLCD_voidSetCurs(1, 0);

	    // ==== Password Entry ====
	    for (u8 i = 0; i < 4; i++) {
	        if (input_method == '1') {
	        	KeyBad=1;
	            do {
	                input_pass[i] = HKEY_GetKeyBad();
	            } while(input_pass[i] == 0xFF);
	        } else if (input_method == '2') {
	        	Blt=1;
	            input_pass[i] = (u8)UART_vRecive();
	            UART_vSend((u16)input_pass[i]);
	        }
	        HLCD_voidSendChar('*');
	    }

	    // ==== Password Check ====
	    u8 is_correct = 1;
	    for (u8 i = 0; i < 4; i++) {
	        if (input_pass[i] != pass[i]) {
	            is_correct = 0;
	            break;
	        }
	    }

	    HLCD_voidClear();
	    if (is_correct) {
	        HLCD_voidPrintString("Access Granted");
	        _delay_ms(1000);
	        HLCD_voidClear();}


	    while (!is_correct) {
	            HLCD_voidClear();
	            HLCD_voidPrintString("Enter Password:");
	            HLCD_voidSetCurs(1, 0);

	            for (u8 i = 0; i < 4; i++) {
	                if (KeyBad) {
	                    do {
	                        input_pass[i] = HKEY_GetKeyBad();
	                    } while(input_pass[i] == 0xFF);
	                }
	                else if (Blt) {

	                    input_pass[i] = (u8)UART_vRecive();
	                    UART_vSend((u16)input_pass[i]); // Echo
	                }
	                HLCD_voidSendChar('*');
	            }


	            is_correct = 1;
	            for (u8 i = 0; i < 4; i++) {
	                if (input_pass[i] != pass[i]) {
	                    is_correct = 0;
	                    break;
	                }
	            }

	            if (!is_correct) {
	                HLCD_voidClear();
	                HLCD_voidPrintString("Wrong Password!");
	                _delay_ms(1000);
	            }
	        }


	        HLCD_voidClear();
	        HLCD_voidPrintString("Access Granted");
	        _delay_ms(1000);
	        HLCD_voidClear();




						while(1){


		// SHOW ON LCD
				HLCD_voidSetCurs(0,2);
				HLCD_voidPrintString("OPTIONS 4-stop");

				HLCD_voidSetCurs(1,0);
				HLCD_voidPrintString("1-FAN 2-LED 3-DR");
               // _delay_ms(100);
				//DOOR
				MTIMER1A_vSetCompareMatchValue(1500);
				// LDR
				Value_of_Ldr = MADC_u16AnalogRead(5);
				if(Value_of_Ldr >700  ){
					MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_HIGH);
				}
				else{
					MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_LOW);
				}

				// LM35
				Value_of_ADC = MADC_u16AnalogRead(4);
				Analoge_voltage = ((f32)Value_of_ADC *5)/1024.0 ;
				temp = Analoge_voltage *100;
				if(temp > 30){
								MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_HIGH);
							}
				else{
			         		MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
					}

				// INTERFACE WITH KEYBAD
				if(KeyBad){
				L_u8Letter=HKEY_GetKeyBad();
				if(L_u8Letter == '3'){
					HLCD_voidClear();
					HLCD_voidPrintString("3-DR");
					MTIMER1A_vSetCompareMatchValue(1000);
					  _delay_ms(1000);
					  HLCD_voidClear();

		}
				if(L_u8Letter == '1'){
					HLCD_voidClear();
					HLCD_voidPrintString("1-FAN ");
					MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_HIGH);
					HLCD_voidPrintString(" TEMP ");
					HLCD_voidSetCurs(1,0);
					HLCD_voidPrintNUM((u16)temp);
					_delay_ms(5000);
					HLCD_voidClear();
				}
				if(L_u8Letter == '2'){

					HLCD_voidPrintString("2-LED  ");
					MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_HIGH);
					HLCD_voidPrintString(" LDR ");
					if(Value_of_Ldr >700 && Value_of_Ldr <1023 ){
						HLCD_voidSetCurs(1,0);
						HLCD_voidPrintString(" DARK WANT LIGHT ");
						HLCD_voidPrintNUM((u16)Value_of_Ldr);
									}
					else{
						HLCD_voidSetCurs(1,0);
						HLCD_voidPrintString(" LIGHT ");
						HLCD_voidPrintNUM((u16)Value_of_Ldr);
					}

					_delay_ms(5000);
					HLCD_voidClear();
				}
				 else if(L_u8Letter == '4'){
				                HLCD_voidClear();
				                HLCD_voidPrintString("Stopped...");
				                while(1){
				                	MTIMER1A_vSetCompareMatchValue(1000);
				                	MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_LOW);
				                	MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
				                    u8 resume_key = HKEY_GetKeyBad();
				                    if(resume_key != 0xFF){
				                        HLCD_voidClear();
				                        break;
				                    }
				                }
				 }
				}

				if(Blt){

					u8 L_Oblth = UART_u8ReadNonBlocking();
					if(L_Oblth){
					UART_vSend((u16)L_Oblth);
					if(L_Oblth == '3'){
						MTIMER1A_vSetCompareMatchValue(1000);
						_delay_ms(3000);

					}
					if(L_Oblth == '1'){
						HLCD_voidClear();
						HLCD_voidPrintString("1-FAN ");
						MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_HIGH);
						HLCD_voidPrintString(" TEMP ");
					    HLCD_voidSetCurs(1,0);
						HLCD_voidPrintNUM((u16)temp);
						_delay_ms(5000);
						HLCD_voidClear();


					}
					if(L_Oblth == '2'){
						HLCD_voidPrintString("2-LED  ");
						MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_HIGH);
						HLCD_voidPrintString(" LDR ");
						if(Value_of_Ldr >700 && Value_of_Ldr <1023 ){
						HLCD_voidSetCurs(1,0);
				     	HLCD_voidPrintString(" DARK WANT LIGHT ");
				     	HLCD_voidPrintNUM((u16)Value_of_Ldr);
					}
						else{
								HLCD_voidSetCurs(1,0);
								HLCD_voidPrintString(" LIGHT ");
										}

								_delay_ms(5000);
								HLCD_voidClear();
					}
					else if(L_Oblth == '4'){
					                HLCD_voidClear();
					                HLCD_voidPrintString("Stopped...");
					                while(1){
					                    u8 resume_bt = UART_u8ReadNonBlocking();
					                    MTIMER1A_vSetCompareMatchValue(1000);
					                   	MDIO_voidSetPinVal(DIO_PORTD,DIO_PIN7,DIO_LOW);
					                	MDIO_voidSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
					                    if(resume_bt){
					                        HLCD_voidClear();
					                        break;
					                    }
					                }
					            }

				}

						}
						}



	return 0;
}
