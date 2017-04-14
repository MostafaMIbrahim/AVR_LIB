/*
 * Util.h
 *
 * Created: 2/21/2017 11:20:37 AM
 *  Author: moibrahim
 */ 


#ifndef UTIL_H_
#define UTIL_H_
    
	/**  Register manipulation  **/
	#define SET_REG(Reg)             Reg |= (0xFF)
	#define CLEAR_REG(Reg)           Reg &= (0x00)
    #define TOGGLE_REG(Reg)          Reg^=(0xFF)
    #define ASSIGN_REG(Reg, Value)   Reg = Value
	
	/**  Bit manipulation  **/
	#define SET_BIT(Reg, Bit)        Reg |= (1<<Bit)
    #define CLEAR_BIT(Reg, Bit)      Reg &= ~(1<<Bit)
	#define TOGGLE_BIT(Reg, Bit)     Reg ^= (1<<Bit)
	#define NOT_BIT(Reg, Bit)        Reg = !(1<<Bit)
	
	/**  Get manipulation  **/
	#define GET_BIT(Reg,Bit) 		(Reg>>Bit)&(1)
	#define GET_NIBBLE_HH(Reg) 			Reg&(0xF0)
	#define GET_NIBBLE_LL(Reg)			Reg&(0x0F)

#endif /* UTIL_H_ */