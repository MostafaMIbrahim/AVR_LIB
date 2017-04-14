/*
 * AVR_LIB_ADC.c
 *
 * Created: 3/1/2017 8:40:49 PM
 * Author : moibrahim
 */ 
#define  F_CPU 16000000

#include <util/delay.h>
#include <avr/io.h>
#include "Types.h"
#include "ADC.h"

int main(void)
{
    /* Replace with your application code */
	ADC_Init();
    while (1) 
    {
		 ADC_start();
		_delay_ms(100);
		uint16 adcValue = ADC_Read();
		PORTA = adcValue;
    }
}

