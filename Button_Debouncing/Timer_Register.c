/*
 * Timer.c
 *
 * Created: 11/19/2016 2:54:17 PM
 *  Author: moibrahim
 */ 
#include <avr/interrupt.h>
#include "Types.h"
#include "Timer_Register.h"

typedef enum
{
	N1 = 8,
	N2 = 64,
	N3 = 256,
	N4 = 1024
}Timer_perscaler;

uint16 prescaler;
uint16 count;
uint16 init_t = 1;  //by ms
uint32 f_clk = 16000;

static void ConfigReg(void);

void Timer0_InitAndRun(void)
{

	ConfigReg();
	if(count)
	{
		OCR0A  = count;  // counter value to count 1ms
		TCCR0A |= 0x02;  // Set Operation mode to CTC bit 0 & 1
		TCCR0B |= 0x00;  // Disable Counter
		switch(prescaler)
		{
			case N1:
			TCCR0B |= 0x02;  // Set Operation mode to CTC bit 3
			break;
			case N2:
			TCCR0B |= 0x03;  // Set Operation mode to CTC bit 3
			break;
			case N3:
			TCCR0B |= 0x04;  // Set Operation mode to CTC bit 3
			break;
			case N4:
			TCCR0B |= 0x05;  // Set Operation mode to CTC bit 3
			break;
		}
		TIMSK0 |= 0x02; // Enable Counter interrupt
		sei();   // enable global interrupt
	}
	
}

static void ConfigReg(void)
{

	uint32 NX = 0;
	NX = f_clk / (2*init_t);
	if(NX % N1 == 0 && (NX/N1) < 256)
	{
		prescaler = N1;
		count = (NX / N1)-1;
	}else if(NX % N2 == 0 && (NX/N2) <256)
	{
		prescaler = N2;
		count = (NX / N2)-1;
	}else if(NX % N3 == 0 && (NX/N3) <256)
	{
		prescaler = N3;
		count = (NX / N3)-1;
	}else if(NX % N4 == 0 && (NX/N4) <256)
	{
		prescaler = N4;
		count = (NX / N4)-1;
	}
}