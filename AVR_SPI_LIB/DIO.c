/*
 * DIO.c
 *
 * Created: 1/31/2017 7:22:19 PM
 *  Author: moibrahim
 */ 

#include "Types.h"
#include "DIO.h"

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

void Dio_InitReg(void)
{
	uint8 i, pin;
	DDR_Type port;
	
	for(i = 0;i<LAST_PIN;i++)
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
				   PORTA->fullPort |=(1<<pin);
				   break;
				   case ddrB:
				   DDRB |= ~(1<<pin);
				   PORTB->fullPort |=(1<<pin);
				   break;
				   case ddrC:
				   DDRC |= ~(1<<pin);
				   PORTC->fullPort |=(1<<pin);
				   break;
				   case ddrD:
				   DDRD |= ~(1<<pin);
				   PORTD->fullPort |=(1<<pin);
				   break;
				   case ddrE:
				   DDRE |= ~(1<<pin);
				   PORTE->fullPort |=(1<<pin);
				   break;
				   case ddrF:
				   DDRF |= ~(1<<pin);
				   PORTF->fullPort |=(1<<pin);
				   break;
				   case ddrG:
				   DDRG |= ~(1<<pin);
				   PORTG->fullPort |=(1<<pin);
				   break;
				   case ddrH:
				   DDRH |= ~(1<<pin);
				   PORTH->fullPort |=(1<<pin);
				   break;
				   case ddrJ:
				   DDRJ |= ~(1<<pin);
				   PORTJ->fullPort |=(1<<pin);
				   break;
				   case ddrK:
				   DDRK |= ~(1<<pin);
				   PORTK->fullPort |=(1<<pin);
				   break;
				   case ddrL:
				   DDRL |= ~(1<<pin);
				   PORTL->fullPort |=(1<<pin);
				   break;
			   }
			break;
			
			case INFREE:
			  switch(port)
			  {
				  case ddrA:
				  DDRA |= ~(1<<pin);
				  PORTA->fullPort |= ~(1<<pin);
				  break;
				  case ddrB:
				  DDRB |= ~(1<<pin);
				  PORTB->fullPort |= ~(1<<pin);
				  break;
				  case ddrC:
				  DDRC |= ~(1<<pin);
				  PORTC->fullPort |= ~(1<<pin);
				  break;
				  case ddrD:
				  DDRD |= ~(1<<pin);
				  PORTD->fullPort |= ~(1<<pin);
				  break;
				  case ddrE:
				  DDRE |= ~(1<<pin);
				  PORTE->fullPort |= ~(1<<pin);
				  break;
				  case ddrF:
				  DDRF |= ~(1<<pin);
				  PORTE->fullPort |= ~(1<<pin);
				  break;
				  case ddrG:
				  DDRG |= ~(1<<pin);
				  PORTG ->fullPort|= ~(1<<pin);
				  break;
				  case ddrH:
				  DDRH |= ~(1<<pin);
				  PORTH->fullPort |= ~(1<<pin);
				  break;
				  case ddrJ:
				  DDRJ |= ~(1<<pin);
				  PORTJ->fullPort |= ~(1<<pin);
				  break;
				  case ddrK:
				  DDRK |= ~(1<<pin);
				  PORTK->fullPort |= ~(1<<pin);
				  break;
				  case ddrL:
				  DDRL |= ~(1<<pin);
				  PORTL->fullPort |= ~(1<<pin);
				  break;
			  }
			break;
		}
	}
}

void Dio_WriteOnPin(Dio_pin_type input,uint8 value)
{
	
	Dio_port* port;
	port_type gpio_port;
	uint8 pin;
	gpio_port = input/8;
	pin = input%8;
	switch(gpio_port)
	{
	   case PA:
	     port = PORTA;
	   break;
	   case PB:
	     port =  PORTB;
	   break;
	   case PC:
	     port = PORTC;
	   break;
	   case PD:
	     port = PORTD;
	   break;
	   case PE:
	     port = PORTE;
	   break;
	   case PF:
	     port = PORTF;
	   break;
	   case PG:
	     port = PORTG;
	   break;
	   case PH:
	     port = PORTH;
	   break;
	   case PJ:
	     port = PORTJ;
	   break;
	   case PK:
	     port = PORTK;
	   break;
	   case PL:
	     port = PORTL;
	   break;	
	}
	switch(pin)
	{
		case 0:
		port->pin.pin0 = value;
		break;
		case 1:
		port->pin.pin1 = value;
		break;
		case 2:
		port->pin.pin2 = value;
		break;
		case 3:
		port->pin.pin3 = value;
		break;
		case 4:
		port->pin.pin4 = value;
		break;
		case 5:
		port->pin.pin5 = value;
		break;
		case 6:
		port->pin.pin6 = value;
		break;
		case 7:
		port->pin.pin7 = value;
		break;
	}
}

uint8 Dio_ReadFromPin(Dio_pin_type input)
{
	Dio_port* port;
	uint8 pin;
	port_type gpio_port;
	uint8 value = 0;
	
	gpio_port = input / 8;
	pin = input % 8;
	
	switch(gpio_port)
	{
		case PA:
		port = PINA;
		break;
		case PB:
		port =  PINB;
		break;
		case PC:
		port = PINC;
		break;
		case PD:
		port = PIND;
		break;
		case PE:
		port = PINE;
		break;
		case PF:
		port = PINF;
		break;
		case PG:
		port = PING;
		break;
		case PH:
		port = PINH;
		break;
		case PJ:
		port = PINJ;
		break;
		case PK:
		port = PINK;
		break;
		case PL:
		port = PINL;
		break;
	}
	
	switch(pin)
	{
		case 0:
		value = port->pin.pin0;
		break;
		case 1:
		value = port->pin.pin1;
		break;
		case 2:
		value = port->pin.pin2;
		break;
		case 3:
		value = port->pin.pin3;
		break;
		case 4:
		value = port->pin.pin4;
		break;
		case 5:
		value = port->pin.pin5;
		break;
		case 6:
		value = port->pin.pin6;
		break;
		case 7:
		value = port->pin.pin7;
		break;
	}
	
	return value;
}

void Dio_WriteOnPort(port_type input,uint8 value)
{
	Dio_port* port;
	switch(input)
	{
		case PA:
		port = PORTA;
		break;
		case PB:
		port =  PORTB;
		break;
		case PC:
		port = PORTC;
		break;
		case PD:
		port = PORTD;
		break;
		case PE:
		port = PORTE;
		break;
		case PF:
		port = PORTF;
		break;
		case PG:
		port = PORTG;
		break;
		case PH:
		port = PORTH;
		break;
		case PJ:
		port = PORTJ;
		break;
		case PK:
		port = PORTK;
		break;
		case PL:
		port = PORTL;
		break;
	}
	port->fullPort = value;
}

uint8 Dio_ReadFromPort(port_type input)
{
  Dio_port* port;
  switch(input)
  {
	  case PA:
	  port = PINA;
	  break;
	  case PB:
	  port =  PINB;
	  break;
	  case PC:
	  port = PINC;
	  break;
	  case PD:
	  port = PIND;
	  break;
	  case PE:
	  port = PINE;
	  break;
	  case PF:
	  port = PINF;
	  break;
	  case PG:
	  port = PING;
	  break;
	  case PH:
	  port = PINH;
	  break;
	  case PJ:
	  port = PINJ;
	  break;
	  case PK:
	  port = PINK;
	  break;
	  case PL:
	  port = PINL;
	  break;
  }	
  
  return port->fullPort;
}