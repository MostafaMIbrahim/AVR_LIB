/*
 * Dio.h
 *
 * Created: 11/18/2016 8:26:43 PM
 *  Author: moibrahim
 */ 
#ifndef DIO_H
    #define DIO_H
	#include "Dio_cfg.h"	
    
	typedef enum
	{
		PA,
		PB,
		PC,
		PD,
		PE,
		PF,
		PG,
		PH,
		PJ,
		PK,
		PL
		}port_type;
	
	extern void InitReg(void);
	extern void Dio_WritePin(Dio_pin_type input,uint8 value);
	extern uint8 Dio_ReadPin(Dio_pin_type input);
#endif
