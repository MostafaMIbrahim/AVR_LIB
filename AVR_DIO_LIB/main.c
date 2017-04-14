/*
 * AVR_LIB_DIO.c
 *
 * Created: 1/31/2017 7:16:21 PM
 * Author : moibrahim
 */ 
#include "Types.h"
#include "DIO.h"
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	Dio_InitReg();
    while (1) 
    {
		Dio_WriteOnPin(portA0, 1);
    }
}

