/*
 * DioRegister.c
 *
 * Created: 11/18/2016 9:01:55 PM
 *  Author: moibrahim
 */ 
#include <avr/io.h>
#include "Types.h"
#include "Dio.h"
#include "DioRegister.h"

typedef enum
{
	OUTPUT =0,
	INPULLUP,
	INFREE
}Dio_pin_state_type;

typedef enum
{
	ddrA = 0,
	ddrB
}DDR_Type;
const Dio_pin_state_type pin_state[LAST_PIN] = 
{
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT,
	OUTPUT
};


void InitReg(void)
{
  uint32 i, pin;
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
			  }
		  break;
	  }
  }	
} 
