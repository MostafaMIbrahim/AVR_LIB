/*
 * memmaps.h
 *
 * Created: 3/17/2017 12:27:02 PM
 *  Author: moibrahim
 */ 


#ifndef MEM_H_
#define MEM_H_


/****************ADC*******************/
#if AVR_ADC_MODULE==1
#define		ADMUX				(*(volatile u8 *)0x7C)
#define		ADCSRA				(*(volatile u8 *)0x7A)
#define		ADCSRB				(*(volatile u8 *)0x7B)
#define		ADCH				(*(volatile u8 *)0x79)
#define		ADCL				(*(volatile u8 *)0x78)


/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0


#endif

#endif /* MEM_H_ */