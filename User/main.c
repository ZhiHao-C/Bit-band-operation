#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "key.h"

#define GPIOB_ODR_Addr    (GPIOB_BASE+0X0C)
#define PBOUT(n)          *(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr & 0x00FFFFFF)<<5)+(n<<2))

#define GPIOA_IDR_Addr    (GPIOA_BASE+0X08)
#define PAIN(n)          *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000)+0x02000000+((GPIOA_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))
 
#define GPIOC_IDR_Addr    (GPIOC_BASE+0X08)
#define PCIN(n)          *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))

uint8_t keynum;
uint8_t key;

void delay_ms(int n)//????
{
	int i;
	while (n--)
	{
		for(i=0;i<115;i++);
	}
}



int main()
{
//	LED_R_GPIO_Config();
	LED_G_GPIO_Config();
	KEY1_GPIO_Config();
	
	
	while (1)
	{
		
		
		
//		PBOUT(0)=1;
//		delay_ms(20000);
//		PBOUT(0)=0;
//		delay_ms(20000);
//		PBOUT(0)=1;
//		PBOUT(1)=1;
//		delay_ms(20000);
//		PBOUT(1)=0;
//		delay_ms(20000);
//		PBOUT(1)=1;
		
		
		
		
		
		if(PAIN(0)==key_on)
		{
			while(PAIN(0)==key_on);
			LED_G_TOGGLE;
		}
//		
		KEY2_GPIO_Config();
		if(PCIN(13)==key_on)
		{
			while(PCIN(13)==key_on);
			LED_G_TOGGLE;
		}
//		
//		key=key_scan(GPIOC,KEY2_GPIO_PIN);
//		if(key_scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==key_on)
//		{
//			LED_R_TOGGLE;
//		}
//		
		
//		if(key==key_on)
//		{
//			keynum=1-keynum;
//			if(keynum==1)
//			{
//				LED_G_GPIO_PORT->ODR &=~0x20;
//			}
//			else if (keynum==0)
//			{
//				LED_G_GPIO_PORT->ODR|=0x20;
//			}
//		}
	}
}

