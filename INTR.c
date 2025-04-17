int ic_cnt=0,bk_cnt=0,total=0,icecream=20,book=40;
char rx_bytes[12],i;
void TOTAL(void)__irq
{
    delay_ms(250);
	total=((icecream*ic_cnt)+(book*bk_cnt));
	EXTINT=0x01;
	LCD_CMD(0x01);
	LCD_CMD(0x80);
	LCD_STR("TOTAL:");
	LCD_INT(total);
	LCD_CMD(0xc0);
	LCD_STR("THANK YOU!");
	icecream=0,book=0,ic_cnt=0,bk_cnt=0,total=0;
	VICVectAddr=0;
}

void REMOVE(void)__irq
{
    delay_ms(250);
	
	LCD_CMD(0x01);
	LCD_CMD(0x80);
	LCD_STR("REMOVING ITEM");
	//LCD_CMD("SCAN ITEM");
	EXTINT=0x02;
	while(1)
	{
	   for(i=0;i<12;i++)
	   {
	      rx_bytes[i]=UART_RX();
		  UART_TX(rx_bytes[i]);
		}
	   if(strstr(rx_bytes,"0600672F317F"))
	   
	   {
	        ic_cnt--;
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STR("ICECREAM COUNT:");
		    LCD_INT(ic_cnt);
			LCD_CMD(0xc0);
			LCD_STR("PRICE: ");
			LCD_INT(ic_cnt*icecream);break;
		}

		 if((strstr(rx_bytes,"0600672F612F"))&&(bk_cnt!=0))
	   
	   {
	        bk_cnt--;
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_STR("BOOK COUNT:");
		    LCD_INT(bk_cnt);
			LCD_CMD(0xc0);
			LCD_STR("PRICE: ");
			LCD_INT(bk_cnt*book);break;
		}
	}
	LCD_STR("ITEM REMOVED");
	VICVectAddr=0;
}
