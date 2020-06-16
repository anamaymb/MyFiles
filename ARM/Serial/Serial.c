#include <lpc214x.h>
unsigned int i;

void delay(int n)
{
	n*=1000;
	for(i=0; i<n; i++);
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

	
	U0TER |= (1<<7);							//Enabling transmission at Tx


	VPBDIV |= (1<<0);							//VPB bus clock is the same as the processor clock.

	delay(100);
}

void serialprint(char t)
{
	U0THR= t;
	delay(3);
}
void serialprintln(char t)
{
	U0THR= t;
	delay(3);
	U0THR= 13;
	delay(3);
}


char r='H';

int main(void)
{
serialbegin();
  while(1)
  {
		serialprintln(r);
		r++;
		delay(10);
  }
}


