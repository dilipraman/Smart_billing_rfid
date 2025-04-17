#include<lpc21XX.h>
void delay_seconds(unsigned int seconds)
{
  T0PR=15000000-1;
  T0TCR=0X01;
  while(T0TC<seconds);
  T0TCR=0X03;
  T0TCR=0X00;
  }
  void delay_ms(unsigned int miliseconds)
  {
  T0PR=15000-1;
  T0TCR=0X01;
  while(T0TC<miliseconds);
  T0TCR=0X03;
  T0TCR=0X00;
  }
  void delay_us(unsigned int microseconds)
  {
  T0PR=15-1;
  T0TCR=0X01;
  while(T0TC<microseconds);
  T0TCR=0X03;
  T0TCR=0X00;
  }
