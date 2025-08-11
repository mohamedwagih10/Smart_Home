
#include "../../MCAL/DIO/DIO_int.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SWITCH_cfg.h"
#include "SWITCH_int.h"
#include "SWITCH_prv.h"


void HSWITCH_vInit(){
	MDIO_voidSetPinDir(SWITCH_PORT,SWITCH_PIN,DIO_INPUT);
#if SWITCH_TYPE == PULLUP
	MDIO_voidSetPinVal(SWITCH_PORT,SWITCH_PIN,DIO_HIGH);
#elif SWITCH_TYPE == PULLDOWN
	MDIO_voidSetPinVal(SWITCH_PORT,SWITCH_PIN,DIO_HIGH);
#endif
}
