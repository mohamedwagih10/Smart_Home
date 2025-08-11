/*
 * EXTI_prg.c
 *
 *  Created By: WAGIH
 *      Author: WAGIH
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "EXTI_prv.h"

void EXT_vInit(){
    switch(INTERRUPT){
    case INT0 :
    MDIO_voidSetPinDir(PORT_INT0,PIN_INT0,DIO_INPUT);
    MDIO_voidSetPinVal(PORT_INT0,PIN_INT0,DIO_HIGH);
#if OPERATE == rising
    	SET_BIT(MCUCR,ISC00);
    	SET_BIT(MCUCR,ISC01);
    	SET_BIT(GICR,INT0);
#elif OPERATE == falling
    	CLR_BIT(MCUCR,ISC00);
    	SET_BIT(MCUCR,ISC01);
    	SET_BIT(GICR,INT0);
#endif
    	break;
    case INT1:
        MDIO_voidSetPinDir(PORT_INT1,PIN_INT1,DIO_INPUT);
        MDIO_voidSetPinVal(PORT_INT1,PIN_INT1,DIO_HIGH);
#if OPERATE == rising
    	SET_BIT(MCUCR,ISC10);
    	SET_BIT(MCUCR,ISC11);
    	SET_BIT(GICR,INT1);
#elif OPERATE == falling
    	CLR_BIT(MCUCR,ISC10);
    	SET_BIT(MCUCR,ISC11);
    	SET_BIT(GICR,INT1);
#endif
    	break;
    case INT2:
        MDIO_voidSetPinDir(PORT_INT2,PIN_INT2,DIO_INPUT);
        MDIO_voidSetPinVal(PORT_INT2,PIN_INT2,DIO_HIGH);
#if OPERATE == rising
    	SET_BIT(MCUCR,ISC2);
    	SET_BIT(GICR,INT2);
#elif OPERATE == falling
    	CLR_BIT(MCUCR,ISC2);
    	SET_BIT(GICR,INT2);
#endif
    	break;
    }

}

