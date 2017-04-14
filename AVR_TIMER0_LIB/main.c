/*
 * AVR_LIB_TIMER0.c
 *
 * Created: 2/8/2017 6:01:44 AM
 * Author : moibrahim
 */ 

#include <avr/interrupt.h>
#include "Types.h"
#include "Util.h"
#include "DIO.h"
#include "TIMER0.h"

void startOS(void);
uint8 flag;

int main(void)
{
    /* Replace with your application code */
	Dio_InitReg();
	Timer0_InitAndRun();
    while (1) 
    {
		startOS();
    }
}


ISR(TIMER0_COMPA_vect)
{
	flag++;
}

void startOS(void)
{
	if(flag == 1000)
	{
		Dio_WriteOnPort(PA, 0xFF);
		flag = 0;
	}
}


