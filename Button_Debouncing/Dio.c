/*
 * Dio.c
 *
 * Created: 11/18/2016 8:32:26 PM
 *  Author: moibrahim
 */ 
#include <avr/io.h>
#include "Types.h"
#include "Dio.h"
typedef enum
{
	ddrA = 0,
	ddrB,
	ddrC,
	ddrD,
	ddrE,
	ddrF,
	ddrG,
	ddrH,
	ddrJ,
	ddrK,
	ddrL
}DDR_Type;
void InitReg(void)
{
	uint8 i, pin;
	DDR_Type port;
	for(i=0;i<LAST_PIN;i++)
	{
		Dio_pin_state_type state;
		state = pin_state[i];
		port = i/8;
		pin = i%8;
		switch(state)
		{
			case OUTPUT:
			switch(port)
			{
				case ddrA:
				DDRA |= (1<<pin);
				break;
				case ddrB:
				DDRB |= (1<<pin);
				break;
				case ddrC:
				DDRC |= (1<<pin);
				break;
				case ddrD:
				DDRD |= (1<<pin);
				break;
				case ddrE:
				DDRE |= (1<<pin);
				break;
				case ddrF:
				DDRF |= (1<<pin);
				break;
				case ddrG:
				DDRG |= (1<<pin);
				break;
				case ddrH:
				DDRH |= (1<<pin);
				break;
				case ddrJ:
				DDRJ |= (1<<pin);
				break;
				case ddrK:
				DDRK |= (1<<pin);
				break;
				case ddrL:
				DDRL |= (1<<pin);
				break;
			}
			break;
			case INPULLUP:
			switch(port)
			{
				case ddrA:
				DDRA |= ~(1<<pin);
				PORTA |=(1<<pin);
				break;
				case ddrB:
				DDRB |= ~(1<<pin);
				PORTB |=(1<<pin);
				break;
				case ddrC:
				DDRC |= ~(1<<pin);
				PORTC |=(1<<pin);
				break;
				case ddrD:
				DDRD |= ~(1<<pin);
				PORTD |=(1<<pin);
				break;
				case ddrE:
				DDRE |= ~(1<<pin);
				PORTE |=(1<<pin);
				break;
				case ddrF:
				DDRF |= ~(1<<pin);
				PORTE |=(1<<pin);
				break;
				case ddrG:
				DDRG |= ~(1<<pin);
				PORTG |=(1<<pin);
				break;
				case ddrH:
				DDRH |= ~(1<<pin);
				PORTH |=(1<<pin);
				break;
				case ddrJ:
				DDRJ |= ~(1<<pin);
				PORTJ |=(1<<pin);
				break;
				case ddrK:
				DDRK |= ~(1<<pin);
				PORTK |=(1<<pin);
				break;
				case ddrL:
				DDRL |= ~(1<<pin);
				PORTL |=(1<<pin);
				break;
			}
			break;
			case INFREE:
			switch(port)
			{
				case ddrA:
				DDRA |= ~(1<<pin);
				PORTA |= ~(1<<pin);
				break;
				case ddrB:
				DDRB |= ~(1<<pin);
				PORTB |= ~(1<<pin);
				break;
				case ddrC:
				DDRC |= ~(1<<pin);
				PORTC |= ~(1<<pin);
				break;
				case ddrD:
				DDRD |= ~(1<<pin);
				PORTD |= ~(1<<pin);
				break;
				case ddrE:
				DDRE |= ~(1<<pin);
				PORTE |= ~(1<<pin);
				break;
				case ddrF:
				DDRF |= ~(1<<pin);
				PORTE |= ~(1<<pin);
				break;
				case ddrG:
				DDRG |= ~(1<<pin);
				PORTG |= ~(1<<pin);
				break;
				case ddrH:
				DDRH |= ~(1<<pin);
				PORTH |= ~(1<<pin);
				break;
				case ddrJ:
				DDRJ |= ~(1<<pin);
				PORTJ |= ~(1<<pin);
				break;
				case ddrK:
				DDRK |= ~(1<<pin);
				PORTK |= ~(1<<pin);
				break;
				case ddrL:
				DDRL |= ~(1<<pin);
				PORTL |= ~(1<<pin);
				break;
			}
			break;
		}
	}
}
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
		case PC:
		if(0==value)
		{
			PORTC&=~(1<<pin);
		}
		else
		{
			PORTC|=(1<<pin);
		}
		break;	
		case PD:
		if(0==value)
		{
			PORTD&=~(1<<pin);
		}
		else
		{
			PORTD|=(1<<pin);
		}
		
		break;	
		case PE:
		if(0==value)
		{
			PORTD&=~(1<<pin);
		}
		else
		{
			PORTE|=(1<<pin);
		}
		break;	
		case PF:
		if(0==value)
		{
			PORTD&=~(1<<pin);
		}
		else
		{
			PORTF|=(1<<pin);
		}
		break;
		case PG:
		if(0==value)
		{
			PORTG&=~(1<<pin);
		}
		else
		PORTG|=(1<<pin);
		break;	
		case PH:
		if(0==value)
		{
			PORTH&=~(1<<pin);
		}
		else
		{
			PORTH|=(1<<pin);
		}
		break;	
		case PJ:
		if(0==value)
		{
			PORTJ&=~(1<<pin);
		}
		else
		{
			PORTJ|=(1<<pin);
		}
		break;	
		case PK:
		if(0==value)
		{
			PORTK&=~(1<<pin);
		}
		else
		{
			PORTK|=(1<<pin);
		}
		break;	
		case PL:
		if(0==value)
		{
			PORTL&=~(1<<pin);
		}
		else
		{
			PORTL|=(1<<pin);
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
		case PC:
		if(0 !=(PINC & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PD:
		if(0 != (PIND & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PE:
		if(0 != (PINE & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PF:
		if(0 != (PINF & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PG:
		if(0 != (PING & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PH:
		if(0 != (PINH & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PJ:
		if(0 != (PINJ & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PK:
		if(0 != (PINK & (1<<pin)))
		{
			value = 1;
		}
		break;
		case PL:
		if(0 != (PINL & (1<<pin)))
		{
			value = 1;
		}
		break;
		
	}
	return value;
}

