#ifndef __LED_H
#define __LED_H 			    
#include "delay.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stdio.h"	

typedef enum 
{ HIGH_positive=1, 
  LOW_positive=0
}mode_typedef;

void LED_INIT(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x);
void LED_ON(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x,mode_typedef mode); 
void LED_OFF(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x,mode_typedef mode);
//void LED_TOGGLE(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin_x);

#endif
