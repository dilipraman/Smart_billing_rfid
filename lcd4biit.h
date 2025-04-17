
#include"delay.h"

#define LCD_D 0xf<<20

#define RS 1<<17

#define W 1<<18

#define E 1<<19


void LCD_INIT(void);

void LCD_DATA(unsigned char);

void LCD_CMD(unsigned char);

void LCD_STR(unsigned char*);

void LCD_INT(int);

void LCD_FLOAT(float);




void LCD_INIT(void)

{

	IODIR1=LCD_D|RS|E|W;

	LCD_CMD(0X01);

	LCD_CMD(0X02);

	LCD_CMD(0X0C);

	LCD_CMD(0X28);

	LCD_CMD(0X80);

}


void LCD_CMD(unsigned char cmd)

{

	IOCLR1=LCD_D;

	IOSET1=(cmd&0xf0)<<16;

	IOCLR1=RS;

	IOCLR1=W;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;

	

	IOCLR1=LCD_D;

	IOSET1=(cmd&0x0f)<<20;

	IOCLR1=RS;

	IOCLR1=W;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;

}

void LCD_DATA(unsigned char d)

{

	IOCLR1=LCD_D;

	IOSET1=(d&0xf0)<<16;

	IOSET1=RS;

	IOCLR1=W;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;

	

	IOCLR1=LCD_D;

	IOSET1=(d&0x0f)<<20;

	IOSET1=RS;

	IOCLR1=W;

	IOSET1=E;

	delay_ms(2);

	IOCLR1=E;

}


void LCD_STR(unsigned char *p)

{

	int count=0;

	while(*p)

	{

		count++;

		LCD_DATA(*p++);

	}

	if(count==16)

		LCD_CMD(0XC0);

}


void LCD_INT(int n)

{

	unsigned char s[50];

	signed int i=0;

	if(n==0)

		LCD_DATA('0');

	else

	{

		if(n<0)

		{

			LCD_DATA('-');

			n=-n;

		}

		while(n>0)

		{

			s[i++]=n%10;

		  n/=10;

		}

	

	for(--i;i>=0;i--)

	{

		LCD_DATA(s[i]+48);

	}

}


}

void LCD_FLOAT(float f)

{

	int temp;

	temp=f;

	LCD_INT(temp);

	LCD_DATA('.');

	temp=((f-temp)*100);

	LCD_INT(temp);

}
	