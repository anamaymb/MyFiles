#include <lpc214x.h>


unsigned int i;

void delay(int n)
{
	n*=1000;
	for(i=0; i<n; i++);
}





class serial{

char b[10];
	int count,len;
	int serialavailable;
	char z[100];

	
	public:
		




void y()
{
	if(U0LSR & (1<<0)){
	z[serialavailable]=U0RBR;
	serialavailable++;}

}





char Read()
{
	int n=z[0];
	
	for(int o=0;o<serialavailable-1;o++)
	z[o]=z[o+1];
	serialavailable--;
	return n;
}

int kitiaahe()
{
	return serialavailable;
}

void print(char t)
{
	U0THR= t;
	delay(3);
}

void println(char t)
{
	U0THR= t;
	delay(3);
	U0THR= 13;
	delay(3);
}

int strlen(char a[])
{
	len=0;
	while(a[len]!='\0')
		len++;
	
	return len;
}


void print(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{		
  U0THR = a[i];
  delay(10);
	}
	
}

void println(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{		
  U0THR = a[i];
  delay(10);
	}
	U0THR= 13;
	delay(3);
}


void itoa(int a)
{
	count=0;
	do
	{
		b[count]=(a%10)+48;
		count++;a/=10;
	}
	while(a!=0);

}




void print(int a)
{
	itoa(a);
U0THR = 0;
  delay(10);
	
	for(int i=(count-1);i>=0;i--){
		if(b[i]>=48 && b[i]<=57){
  U0THR = b[i];
  delay(10);}
}
//	U0THR = 13;
//  delay(10);
}



void println(int a)
{
		itoa(a);

	for(int i=(count-1);i>=0;i--){
		if(b[i]>=48 && b[i]<=57){
  U0THR = b[i];
  delay(10);}
}
	U0THR= 13;
	delay(3);
}

}serial;

__irq void send(void)							//UART0 RX interrupt
{

	serial.y();
}

void serialbegin()
{
		//If simulating on proteus, Adjust clock frequency of the lpc module to 20MHz
	
	PINSEL0 |= (1<<0);						//Setting the pin as Tx
	PINSEL0 &= ~(1<<1);
	
	PINSEL0 |= (1<<2);						//Setting the function of the pi as Rx
	PINSEL0 &= ~(1<<3);
	
	U0LCR |= (1<<7);							//Enabling divisor latch access bit
	
	U0DLM=2;
	U0DLL=139;										//Setting the divisor for baud rate
	
	//U0FDR = 0x00000063;						//Setting the clock prescaler multiplier

	U0LCR &= ~(1<<7);							//Disabling the divisor latch bit
	
	U0LCR |= (1<<0)|(1<<1);				//Setting the length of the data as 8 bit
	
	U0LCR &= ~(1<<3);							//One stop bit
	U0LCR &= ~(1<<2) ;						//Disabling parity bit

	U0IER |= (1<<0);
	
	U0TER |= (1<<7);							//Enabling transmission at Tx


	VPBDIV |= (1<<0);							//VPB bus clock is the same as the processor clock.
//////////////////////////////////////////////////

	VICIntEnable |= (1<<6);										//Enabling UART0 interrupt

	VICIntSelect &= ~(1<<6);									//Setting the interrupt in as vectored IRQ (And not FIQ)

	VICVectCntl4 |= (1<<5);										//Enabling selected vectored IRQ function (and not nonvectored interrupt)
	VICVectCntl4 |= 6;												//Putting the interrupt number (for UART0 it is 6)

	VICVectAddr4 = (unsigned int)send;					//Assigning the address of ISR to the register (for selected vectored interrupt)
delay(100);
}





char r='A';
int y=840;
int pate=0;
int main(void)
{
serialbegin();
	
  while(1)
  {
		serial.print(y);
		delay(5);
		pate++;
		if(pate==5)
	{y-=40;pate=0;}
	
  }
	
}


