/*
 * Dio.h
 *
 * Created: 11/18/2016 8:26:43 PM
 *  Author: moibrahim
 */ 
#ifndef DIO_H
    #define DIO_H
	typedef enum{
		portA0=0,
		portA1,
		portA2,
		portA3,
		portA4,
		portA5,
		portA6,
		portA7,
		portB0,
		portB1,
		portB2,
		portB3,
		portB4,
		portB5,
		portB6,
		portB7,
		LAST_PIN
	}Dio_pin_type;
	
	extern void Dio_WritePin(Dio_pin_type input,uint8 value);
	extern uint8 Dio_ReadPin(Dio_pin_type input);
#endif
