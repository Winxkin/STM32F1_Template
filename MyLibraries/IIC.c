#include "IIC.h"




void IIC_init (GPIO_TypeDef* GPIOx)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
      
	Timer_init ();
	if (GPIOx == GPIOA) {
		// Enable clock for GPIOA
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	} else if (GPIOx == GPIOB) {
		// Enable clock for GPIOB
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	} else if (GPIOx == GPIOC) {
		// Enable clock for GPIOC
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	}else if (GPIOx == GPIOD) {
		// Enable clock for GPIOD
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

	}else if (GPIOx == GPIOE) {
		// Enable clock for GPIOE
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

	}else if (GPIOx == GPIOF) {
		// Enable clock for GPIOF
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

	}else if (GPIOx == GPIOG) {
		// Enable clock for GPIOG
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

	}
	 
  GPIO_InitStructure.GPIO_Pin = SDA | SCL;			    
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOx, &GPIO_InitStructure);		
	
	GPIO_SetBits(GPIOx, SDA);
	GPIO_SetBits(GPIOx, SCL);
	
}

void IIC_Start (GPIO_TypeDef* GPIOx)
{ 
	GPIO_SetBits(GPIOx, SCL);
	delay_us(3);
	GPIO_SetBits(GPIOx, SDA);
	delay_us(3);
  GPIO_ResetBits (GPIOA,SDA);
	delay_us(3);
	GPIO_ResetBits (GPIOA,SCL);
}

void IIC_Stop (GPIO_TypeDef* GPIOx)
{
  GPIO_SetBits(GPIOx, SCL);
	delay_us(3);
	GPIO_ResetBits(GPIOx, SDA);
	delay_us(3);
  GPIO_SetBits (GPIOA,SDA);
	delay_us(3);
}

uint8_t IIC_Write (GPIO_TypeDef* GPIOx, uint8_t datau8)
{
  uint8_t i;
	for(i=0;i<8;i++)
	{	if(datau8 & 0x80)
		{GPIO_SetBits (GPIOA,SDA);}
		else
		{GPIO_ResetBits(GPIOx, SDA);}
	  
		delay_us(3);
		GPIO_SetBits(GPIOx, SCL);
		delay_us(5);
		GPIO_ResetBits(GPIOx, SCL);
		delay_us(2);
	}
	  GPIO_SetBits (GPIOA,SDA);
	  delay_us(3);
	  datau8 <<=1;
	
	if(GPIO_ReadInputDataBit(GPIOx, SDA))
	{
		
	}
}

uint8_t IIC_Read (uint8_t ACKu8)
{

}



