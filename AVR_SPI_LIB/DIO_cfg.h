/*
 * DIO_cfg.h
 *
 * Created: 1/31/2017 7:21:59 PM
 *  Author: moibrahim
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

    typedef enum
	{
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
		portC0,
		portC1,
		portC2,
		portC3,
		portC4,
		portC5,
		portC6,
		portC7,
		portD0,
		portD1,
		portD2,
		portD3,
		portD4,
		portD5,
		portD6,
		portD7,
		portE0,
		portE1,
		portE2,
		portE3,
		portE4,
		portE5,
		portE6,
		portE7,
		portF0,
		portF1,
		portF2,
		portF3,
		portF4,
		portF5,
		portF6,
		portF7,
		portG0,
		portG1,
		portG2,
		portG3,
		portG4,
		portG5,
		portG6,
		portG7,
		portH0,
		portH1,
		portH2,
		portH3,
		portH4,
		portH5,
		portH6,
		portH7,
		portJ0,
		portJ1,
		portJ2,
		portJ3,
		portJ4,
		portJ5,
		portJ6,
		portJ7,
		portK0,
		portK1,
		portK2,
		portK3,
		portK4,
		portK5,
		portK6,
		portK7,
		portL0,
		portL1,
		portL2,
		portL3,
		portL4,
		portL5,
		portL6,
		portL7,
		LAST_PIN
	}Dio_pin_type;
    
	typedef enum
	{
		OUTPUT = 0,
		INPULLUP,
		INFREE
	}Dio_pin_state_type;
	
	#define SPI_Master_Mode_Enable		1
    #define SPI_Slave_mode_Enable		0
	
 extern const Dio_pin_state_type pin_state[LAST_PIN];

#endif /* DIO_CFG_H_ */