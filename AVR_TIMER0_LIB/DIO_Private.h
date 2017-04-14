/*
 * DIO_Private.h
 *
 * Created: 1/31/2017 7:22:33 PM
 *  Author: moibrahim
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

    typedef struct
    {
	  uint8 pin0:1;
	  uint8 pin1:1;
	  uint8 pin2:1;
	  uint8 pin3:1;
	  uint8 pin4:1;
	  uint8 pin5:1;
	  uint8 pin6:1;
	  uint8 pin7:1;
    }Dio_port_pin;

    typedef union
    {
	  uint8 fullPort;
	  Dio_port_pin pin;
    }Dio_port;

    #ifndef DDRA
    #define DDRA  (*(volatile uint8*) 0x21)
    #endif 
	
	#ifndef DDRB
	#define DDRB   (*(volatile uint8*) 0x24)
	#endif
	
	#ifndef DDRC
	#define DDRC   (*(volatile uint8*) 0x27)
	#endif
	
	#ifndef DDRD
	#define DDRD   (*(volatile uint8*) 0x2A)
	#endif
	
	#ifndef DDRE
	#define DDRE   (*(volatile uint8*) 0x2D)
	#endif
	
	#ifndef DDRF
	#define DDRF   (*(volatile uint8*) 0x30)
	#endif
	
	#ifndef DDRG
	#define DDRG   (*(volatile uint8*) 0x33)
	#endif
	
	#ifndef DDRH
	#define DDRH   (*(volatile uint8*) 0x101)
	#endif
	
	#ifndef DDRJ
	#define DDRJ   (*(volatile uint8*) 0x104)
	#endif
	
	#ifndef DDRK
	#define DDRK   (*(volatile uint8*) 0x107)
	#endif
	
	#ifndef DDRL
	#define DDRL   (*(volatile uint8*) 0x10A)
	#endif
	
	#ifndef PORTA
	#define PORTA   ((Dio_port*) 0x22)
	#endif
	
	#ifndef PORTB
	#define PORTB   ((Dio_port*) 0x25)
	#endif
	
	#ifndef PORTC
	#define PORTC   ((Dio_port*) 0x28)
	#endif
	
	#ifndef PORTD
	#define PORTD   ((Dio_port*) 0x2B)
	#endif
	
	#ifndef PORTE
	#define PORTE   ((Dio_port*) 0x2E)
	#endif
	
	#ifndef PORTF
	#define PORTF   ((Dio_port*) 0x31)
	#endif
	
	#ifndef PORTG
	#define PORTG   ((Dio_port*) 0x34)
	#endif
	
	#ifndef PORTH
	#define PORTH   ((Dio_port*) 0x102)
	#endif
	
	#ifndef PORTJ
	#define PORTJ   ((Dio_port*) 0x105)
	#endif
	
	#ifndef PORTK
	#define PORTK   ((Dio_port*) 0x108)
	#endif
	
	#ifndef PORTL
	#define PORTL   ((Dio_port*) 0x10B)
	#endif
	
	#ifndef PINA
	#define PINA   ((Dio_port*) 0x20)
	#endif
	
	#ifndef PINB
	#define PINB   ((Dio_port*) 0x23)
	#endif
	
	#ifndef PINC
	#define PINC   ((Dio_port*) 0x26)
	#endif
	
	#ifndef PIND
	#define PIND   ((Dio_port*) 0x29)
	#endif
	
	#ifndef PINE
	#define PINE   ((Dio_port*) 0x2C)
	#endif
	
	#ifndef PINF
	#define PINF   ((Dio_port*) 0x2F)
	#endif
	
	#ifndef PING
	#define PING   ((Dio_port*) 0x32)
	#endif
	
	#ifndef PINH
	#define PINH   ((Dio_port*) 0x100)
	#endif
	
	#ifndef PINJ
	#define PINJ   ((Dio_port*) 0x103)
	#endif
	
	#ifndef PINK
	#define PINK   ((Dio_port*) 0x106)
	#endif
	
	#ifndef PINL
	#define PINL   ((Dio_port*) 0x109)
	#endif




#endif /* DIO_PRIVATE_H_ */