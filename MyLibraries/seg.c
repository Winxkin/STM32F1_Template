#include "seg.h"

void seg_init (GPIO_TypeDef* GPIOx)
{ 
	GPIO_InitTypeDef  GPIO_InitStructure;
      
	
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
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
	//set seg_pin
	GPIO_InitStructure.GPIO_Pin = a;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = b;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = c;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = d;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = e;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = f;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = g;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = dp;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);	
  
}

void seg_bit (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x, uint8_t value)
{
	if (value == 1)
	{
		GPIO_SetBits(GPIOx, GPIO_Pin_x);
	}
	else
	{
	  GPIO_ResetBits (GPIOx,GPIO_Pin_x);
	}


}


void seg_set (GPIO_TypeDef* GPIOx, uint8_t Data)
{
	uint8_t buf[8];
	if(Data & 1)  buf[0]=1 ;
	else buf[0]=0;
	
	if(Data & 2)  buf[1]=1;
	else buf[1]=0;
	
	if(Data & 4)  buf[2]=1;
	else buf[2]=0;
	
	if(Data & 8)  buf[3]=1;
	else buf[3]=0;
	
	if(Data & 16)  buf[4]=1;
	else buf[4]=0;
	
	if(Data & 32)  buf[5]=1;
	else buf[5]=0;
	
	if(Data & 64)  buf[6]=1;
	else buf[6]=0;
	
	if(Data & 128) buf[7]=1;
	else buf[7]=0;

	seg_bit (GPIOx, a, buf[0]);
	seg_bit (GPIOx, b, buf[1]);
	seg_bit (GPIOx, c, buf[2]);
	seg_bit (GPIOx, d, buf[3]);
	seg_bit (GPIOx, e, buf[4]);
	seg_bit (GPIOx, f, buf[5]);
	seg_bit (GPIOx, g, buf[6]);
	seg_bit (GPIOx, dp, buf[7]);
}



void seg_setnumberA (GPIO_TypeDef* GPIOx, uint8_t number)
{
  if(number == 0)  seg_set (GPIOx, 0xC0);
	else if (number == 1 ) seg_set (GPIOx,0xF9);
	else if (number == 2 ) seg_set (GPIOx,0xA4);
	else if (number == 3 ) seg_set (GPIOx,0xB0);
	else if (number == 4 ) seg_set (GPIOx,0x99);
	else if (number == 5 ) seg_set (GPIOx,0x92);
	else if (number == 6 ) seg_set (GPIOx,0x82);
	else if (number == 7 ) seg_set (GPIOx,0x8F);
	else if (number == 8 ) seg_set (GPIOx,0x80);
	else if (number == 9 ) seg_set (GPIOx,0x90);
	else seg_set (GPIOx, 0xFF);
	

}

void seg_setnumberK (GPIO_TypeDef* GPIOx, uint8_t number)
{
  if(number == 0)  seg_set (GPIOx,0x3F);
	else if (number == 1 ) seg_set (GPIOx,0x06);
	else if (number == 2 ) seg_set (GPIOx,0x5B);
	else if (number == 3 ) seg_set (GPIOx,0x40);
	else if (number == 4 ) seg_set (GPIOx,0x66);
	else if (number == 5 ) seg_set (GPIOx,0x6D);
	else if (number == 6 ) seg_set (GPIOx,0x7D);
	else if (number == 7 ) seg_set (GPIOx,0x07);
	else if (number == 8 ) seg_set (GPIOx,0x7F);
	else if (number == 9 ) seg_set (GPIOx,0x6F);
	else seg_set (GPIOx,0x00);
	

}










