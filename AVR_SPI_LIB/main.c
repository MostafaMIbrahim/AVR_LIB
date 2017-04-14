/*
 * AVR_LIB_SPI.c
 *
 * Created: 3/19/2017 1:28:42 PM
 * Author : moibrahim
 */ 
#include <avr/interrupt.h>
#include "Types.h"
#include "DIO.h"
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	 Dio_InitReg();
	 SPI_init();
    while (1) 
    {
	   SPI_send_byte('A');	
    }
}

