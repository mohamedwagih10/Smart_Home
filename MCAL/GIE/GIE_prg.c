/*
 * GIE_prg.c
 *
 *  Created by: WAGIH
 *      Author: Dell
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_int.h"
#include "GIE_prv.h"
void GIE_vEnable(){
    SET_BIT(SREG,7);
}
void GIE_vDisnable(){
    CLR_BIT(SREG,7);
}

