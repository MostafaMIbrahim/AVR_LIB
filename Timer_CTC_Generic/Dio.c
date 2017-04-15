/*
 * Dio.c
 *
 * Created: 11/18/2016 8:32:26 PM
 *  Author: moibrahim
 */ 
#include <avr/io.h>
#include "Types.h"
#include "Dio.h"

typedef enum{
	PA,
	PB
}port_type;

void Dio_WritePin(Dio_pin_type input,uint8 value){
	
	port_type port ;
	uint8 pin;
	port = input/8;
	pin = input%8;
	
	switch(port)
	{
		case PA:
		if(0==value)
		{
			PORTA&=~(1<<pin);
		}
		else
		{
			PORTA|=(1<<pin);
		}
		break;	
		case PB:
		if(0==value)
		{
			PORTB&=~(1<<pin);
		}
		else
		{
			PORTB|=(1<<pin);
		}
		break;	
		
	}	
}

uint8 Dio_ReadPin(Dio_pin_type input){
	
	uint8 pin;
	port_type port;
	uint8 value = 0;
	
	port = input / 8;
	pin = input % 8;
	
	switch(port)
	{
		case PA:
		if(0 != (PINA & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PB:
		if(0 != (PINB & (1<<pin)))
		{
			value = 1;
		}
		break;	
	}
	return value;
}