/*
 * ADC_Test.c
 *
 * Created: 1/15/2017 10:19:34 AM
 * Author : moibrahim
 */ 

#include <avr/io.h>
#include "Types.h"
#include "Dio.h"
#include "Button.h"
#include "Timer_Register.h"
#include "Schedular.h"

int main(void)
{
    /* Replace with your application code */
	InitReg();
	Timer0_InitAndRun();
	Key_Init();
    while (1) 
    {
		startOS();
		uint8 value =  Key_GetKey();
		if(1 == value)
		{
			Dio_WritePin(portA1,1);
		}else
		{
			Dio_WritePin(portA1,0);
		}
		
    }
}

