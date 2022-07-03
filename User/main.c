/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  Huan-Nguyen-Duy
  * @version V1.0
  ******************************************************************************
*/  
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "delay.h"
#include <stdio.h>
#include "stm32f10x_gpio.h"
#include "LED.h"
#include "seg.h"
/*----------------------------------------------------------------------------*/





int main(void)
{
  /*--Init--*/	
	  
	  

	
	 while (1)
	{ 
		/*--Code here--*/
		
		
		
	}
  

  return 0;
}


/*--------------Test kit ----------------*/

//		GPIO_InitTypeDef  GPIO_InitStructure;
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;			    
//    GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
//    GPIO_Init(GPIOA, &GPIO_InitStructure);


//		GPIO_SetBits(GPIOA, GPIO_Pin_3);
//		delay_ms(1000);
//		GPIO_ResetBits (GPIOA,GPIO_Pin_3);
//	  delay_ms(1000);
