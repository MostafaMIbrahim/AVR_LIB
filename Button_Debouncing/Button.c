/*
 * Button.c
 *
 * Created: 1/15/2017 5:33:12 PM
 *  Author: moibrahim
 */ 
#include <avr/io.h>
#include "Types.h"
#include "Dio.h"
#include "Button.h"

static boolean button = 0;
static boolean new;
static boolean prev = 0;
static uint8 count = 0;
Dio_pin_type input;

void Key_Init(void)
{
	input = portA0;
}

boolean Key_GetKey(void)
{
	return button;
}

void Key_Task(void)
{
	new = Dio_ReadPin(input);
	if(new == prev)
	{
		count++;
	} else
	{
		count = 0;
	}
	
	if(count>=5)
	{
		button = new;
	}
	
	prev = new;
}
