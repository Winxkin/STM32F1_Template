#include "LCD.h"

void LCD_init (GPIO_TypeDef* GPIOx )
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
	GPIO_InitStructure.GPIO_Pin = D0;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = D1;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = D2;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = D3;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = D4;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = D5;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = D6;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = D7;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);	
  
	
	GPIO_InitStructure.GPIO_Pin = LCD_EN;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LCD_RS;			     
  GPIO_Init(GPIOx, &GPIO_InitStructure);
	
}

void LCD_setbit (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x, uint8_t value)
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

void LCD_sentDATA (GPIO_TypeDef* GPIOx, uint8_t Data)
{
  uint8_t b[8];
	if(Data & 1)  b[0]=1;
	else b[0] =0;
	
	if(Data & 2)  b[1]=1;
	else b[1] =0;
	
	if(Data & 4)  b[2]=1;
	else b[2] =0;
	
	if(Data & 8)  b[3]=1;
	else b[3] =0;
	
	if(Data & 16)  b[4]=1;
	else b[4] =0;
	
	if(Data & 32)  b[5]=1;
	else b[5] =0;
	
	if(Data & 64)  b[6]=1;
	else b[6] =0;
	
	if(Data & 128)  b[7]=1;
	else b[7] =0;
	
	
	LCD_setbit (GPIOx, D0, b[0]);
	LCD_setbit (GPIOx, D1, b[1]);
	LCD_setbit (GPIOx, D2, b[2]);
	LCD_setbit (GPIOx, D3, b[3]);
	LCD_setbit (GPIOx, D4, b[4]);
	LCD_setbit (GPIOx, D5, b[5]);
	LCD_setbit (GPIOx, D6, b[6]);
	LCD_setbit (GPIOx, D7, b[7]);
	
	
}

void LCD_sentCMD (GPIO_TypeDef* GPIOx, uint8_t cmd)
{
	GPIO_ResetBits (GPIOx,LCD_RS);
	LCD_sentDATA (GPIOx ,cmd);
	GPIO_ResetBits (GPIOx,LCD_EN);
	GPIO_SetBits (GPIOx,LCD_EN);
	delay_ms (1);
  
}

void LCD_sentCHAR (GPIO_TypeDef* GPIOx, uint8_t _char)
{
	GPIO_SetBits (GPIOx,LCD_RS);
	LCD_sentDATA (GPIOx, _char);
	GPIO_ResetBits (GPIOx,LCD_EN);
	GPIO_SetBits (GPIOx,LCD_EN);
	delay_ms (1);
  
}


void LCD_sentString (GPIO_TypeDef* GPIOx, uint8_t *str)
{
	int i;
	for(i=0; *(str) != '\0';i++)
	{
	   LCD_sentCHAR (GPIOx, *(str)++);
	}
	
}

void LCD_start (GPIO_TypeDef* GPIOx)
{
  LCD_sentCMD(GPIOx, clear);
	LCD_sentCMD(GPIOx,dis_2line);  //note
	LCD_sentCMD(GPIOx,display);
 
}


void LCD_displaystr (GPIO_TypeDef* GPIOx, uint8_t *str, _line line)
{ 
	LCD_start(GPIOx);
  if(line == l1)
	{
	  LCD_sentCMD(GPIOx,line1);
		LCD_sentString(GPIOx,str);
	}
	else if (line == l2)
	{
		LCD_sentCMD(GPIOx,line2);
		LCD_sentString(GPIOx,str);
	}
	else if (line == l3)
	{
		LCD_sentCMD(GPIOx,line3);
		LCD_sentString(GPIOx,str);
	}	
	else 
	{
		LCD_sentCMD(GPIOx,line4);
		LCD_sentString(GPIOx,str);
	}		
	

}


void LCD_setfull_str (GPIO_TypeDef* GPIOx, uint8_t *str1, uint8_t *str2)
{
	 LCD_start(GPIOx);
	 LCD_displaystr (GPIOx,str1,l1);
	 LCD_displaystr (GPIOx,str2,l2);
}


void LCD_sentint (GPIO_TypeDef* GPIOx, uint8_t _int)
{ 
	 uint8_t hundred =0;
		 uint8_t dozen = 0;
		 uint8_t unit  =0;
	
	 if(_int<10)
	 {
			LCD_sentCHAR(GPIOx, _int+0x30);
	 }
	 else if (_int>=10 && _int<100)
	 {
	     dozen = _int/10;
		   unit = _int%10;
		  
		  LCD_sentCHAR (GPIOx, dozen + 0x30);
		  LCD_sentCHAR (GPIOx, unit + 0x30);
	 
	 }
	 else
	 { 
		 hundred = _int/100;
		 dozen = (_int/10)%10;
		 unit = _int%10;
	    
		 LCD_sentCHAR (GPIOx, hundred + 0x30);
		 LCD_sentCHAR (GPIOx, dozen + 0x30);
		 LCD_sentCHAR (GPIOx, unit + 0x30);
	 }
}

void LCD_displaynum (GPIO_TypeDef* GPIOx, uint8_t _int,_line line)
{
  if(line == l1)
	{
	  LCD_sentCMD(GPIOx, line1);
		LCD_sentint (GPIOx, _int);
	}
	else if(line == l2)
	{
		LCD_sentCMD(GPIOx, line2);
		LCD_sentint (GPIOx, _int);
	}
	else if(line == l3)
	{
		LCD_sentCMD(GPIOx, line3);
		LCD_sentint (GPIOx, _int);
	}
	else if(line == l4)
	{
		LCD_sentCMD(GPIOx, line4);
		LCD_sentint (GPIOx, _int);
	}

}


