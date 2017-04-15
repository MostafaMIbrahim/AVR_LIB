/*
 * Timer_Generic.c
 *
 * Created: 11/19/2016 8:31:38 PM
 * Author : moibrahim
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Types.h"
#include "DioRegister.h"
#include "Dio.h"
#include "Timer_Register.h"

void toggleLed(void);
void startOS(void);
uint16 flag;

int main(void)
{
    InitReg();
    Timer0_InitAndRun();
    while (1) 
    {
	startOS();
    }
}

ISR(TIMER0_COMPA_vect)
{
	static uint8 counter = 0;
	counter++;
	flag = counter;
}

void startOS(void)
{
	if(flag == 1000)
	{
		toggleLed();
		flag = 0;
	}
}
void toggleLed(void)
{
	PORTB ^= 0xFF;
}

