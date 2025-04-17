#include<lpc21xx.h>
#include<string.h>
#include"lcd4biit.h"
#include"UART.c"
#include"INTR.c"
#define EINT0 0x01
#define EINT1 0x20000000

int main()
{
    PINSEL1|=EINT0;
	PINSEL0|=EINT1;
	LCD_INIT();
	LCD_CMD(0xc0);
	LCD_STR("WELCOME");
	LCD_CMD(0xc0);
	LCD_STR("SMART TROLLEY");
	
	VICIntSelect=0;//intrupts irq
	VICVectCntl0=(0x20)|14;
	VICVectAddr0=(int)TOTAL;
	VICVectCntl1=(0x20)|15;
	VICVectAddr1=(int)REMOVE;
	
	EXTMODE=0x00;
	EXTPOLAR=0x00;
	
	VICIntEnable=1<<14|1<<15;
	UART_CONFIG();
	while(1)
	{
	   for(i=0;i<12;i++)
	   {
	   
	      rx_bytes[i]=UART_RX();
		  UART_TX(rx_bytes[i]);
		}
	   if(strstr(rx_bytes,"0600672F317F"))
	   
	   {
	        ic_cnt++;
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STR("ICECREAM COUNT:");
			LCD_INT(ic_cnt);

			LCD_CMD(0xc0);
			LCD_STR("PRICE: ");
			LCD_INT(ic_cnt*icecream);
		}

		 if(strstr(rx_bytes,"0600672F612F"))
	   
	   {
	        bk_cnt++;
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STR("BOOK COUNT:");
			LCD_INT(bk_cnt);
			LCD_CMD(0xc0);
			LCD_STR("PRICE: ");
			LCD_INT(bk_cnt*book);
		}
	}
}
