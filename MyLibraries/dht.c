#include "dht.h"
void DHT_init (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
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
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;			    
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOx, &GPIO_InitStructure);			    
}    





void MCUgetwire (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{ 
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;			    
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void MCUfreewire (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;			    
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING ;	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOx, &GPIO_InitStructure);	
}

uint8_t onewire_state(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
	return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin_x);
}






void DHT_RST (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x) 
{ MCUgetwire (GPIOx, GPIO_Pin_x);  //MCU control can push or pull wire
	GPIO_SetBits(GPIOx, GPIO_Pin_x);
	GPIO_ResetBits (GPIOx,GPIO_Pin_x);
	delay_ms (20); // delay at least 18ms
	GPIO_SetBits(GPIOx, GPIO_Pin_x);
	delay_us (30);	// 20-40us
	MCUfreewire (GPIOx, GPIO_Pin_x);	
}

uint8_t check_DHT11 (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
uint32_t time =0;
  
  while((onewire_state(GPIOx, GPIO_Pin_x)==1) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait down
	if(time>=80) return 0; //error
		

	time =0;
	while((onewire_state(GPIOx, GPIO_Pin_x)==0) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait up
	if(time>=80) return 0; //error
	
	return 1;
	
}





uint8_t Readbit (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{ uint32_t time =0;
	
	while((onewire_state(GPIOx , GPIO_Pin_x)==1) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait down
	
	
	time =0;
	while((onewire_state(GPIOx , GPIO_Pin_x)==0) && (time<100)) 
	{ time ++;
		delay_us(1);
	} // wait up
	
	delay_us(40);
	if(onewire_state(GPIOx , GPIO_Pin_x)==0) return 0;
	else return 1;
	

}

uint8_t Readbyte (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{ u8 i;
	u8 byte = 0;
	
	for(i=0;i<5;i++)
	{
	  byte<<=1;
		byte|=Readbit(GPIOx , GPIO_Pin_x);
	}
	
	return byte;
	
}



uint8_t Read_temp_humi(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x, uint8_t* temp, uint8_t* humi)
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	DHT_RST (GPIOx , GPIO_Pin_x);
	
	if(check_DHT11 (GPIOx , GPIO_Pin_x))
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte (GPIOx , GPIO_Pin_x);
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 *temp = buf[2];
			*humi = buf[0];
		}
	 
	 return 1;
	}
	else	return 0; //error 
  
	
}



uint8_t Readtemp(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	 DHT_RST (GPIOx , GPIO_Pin_x);
	
	if(check_DHT11 (GPIOx , GPIO_Pin_x) ==1 )
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte (GPIOx , GPIO_Pin_x);
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 return buf[2];
		}
	 
	}
  return 0;
	
}


uint8_t Readhumi(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{ 
	uint32_t i=0;
	uint8_t buf[5]={0,0,0,0,0};
	
	DHT_RST (GPIOx , GPIO_Pin_x);
	
	if(check_DHT11 (GPIOx , GPIO_Pin_x)==1)
	{
		for(i=0;i<5;i++)
		{
			buf[i]=Readbyte (GPIOx , GPIO_Pin_x);
		
		}
	  // checksum
		if((buf[0] + buf[1] + buf[2] + buf[3])==buf[4])
		{
		 return buf[0];
		}
	 	
	}
  return 0;
}



