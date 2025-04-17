void UART_CONFIG(void)
{
   PINSEL0|=0x05;
   U0LCR=0x83;
   U0DLL=97;
   U0LCR=0x03;
}
 void UART_TX(unsigned char ch)
 {
     U0THR=ch;
	 while((U0LSR>>5&1)==0);
 }

 unsigned char UART_RX(void)
 {
     while((U0LSR&1)==0);
	 return U0RBR;
 }
 
 void UART_STR(unsigned char *s)
 {
    while(*s)
	UART_TX(*s++);
 }
