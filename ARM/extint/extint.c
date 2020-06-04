#define Falling 'F'
#define Rising 'R'

#include <lpc214x.h>
unsigned int i;
int tmp;

void delay(int n)
{
	n*=1000;
	for(i=0; i<n; i++);
}


__irq void afunc(void)
{

		IO0SET |= (1<<10);					//Toggling the the led
    delay(500);
    IO0CLR |= (1<<10);

		EXTINT |= (1<<1)|(1<<0)|(1<<2)|(1<<3);			//This bit shoulb be reset before closing the ISR
	
}

void interrupt_init(int adrs,int intnum,int pinn,char edge)
{
	
	

	if(intnum==1)
	{
		if(pinn==3)
		PINSEL0 |=(1<<6)|(1<<7);							//Selecting the interrupt function on that pin
		if(pinn==14){
		PINSEL0 |=(1<<29);
		PINSEL0 &= ~(1<<28);}
	}
	if(intnum==0)
	{
		if(pinn==1)
		PINSEL0 |=(1<<2)|(1<<3);							//Selecting the interrupt function on that pin
		if(pinn==16){
		PINSEL1 |=(1<<0);
		PINSEL1 &= ~(1<<1);}
	}
	if(intnum==2)
	{
		if(pinn==7)
		PINSEL0 |=(1<<14)|(1<<15);							//Selecting the interrupt function on that pin
		if(pinn==15){
		PINSEL0 |=(1<<31);
		PINSEL0 &= ~(1<<30);}
	}
	if(intnum==3)
	{
		if(pinn==9)
		PINSEL0 |=(1<<18)|(1<<19);							//Selecting the interrupt function on that pin
		if(pinn==20)
		PINSEL1 |=(1<<9)|(1<<8);
		if(pinn==30){
		PINSEL1 |=(1<<29);
		PINSEL1 &= ~(1<<28);
		}
	}

	
	VICIntSelect &= ~(1<<(intnum+14));				//Setting the interrupt in as vectored IRQ (And not FIQ)

	EXTMODE |= (1<<intnum);										//setting mode as edge triggered (and not state sensitive)

	if(edge=='F')
	EXTPOLAR &= ~(1<<1);									    //Setting falling edge (and not rising)	
	else if(edge=='R')
	EXTPOLAR |= (1<<intnum);									//Setting rising edge (and not falling)
	
	VICVectCntl5 |= (1<<5);										//Enabling selected vectored IRQ function (and not nonvectored interrupt)
	VICVectCntl5 |= (intnum+14);							//Putting the interrupt number (for EXTINT1 it is 15)
	
  VICVectAddr5 = adrs;											//Assigning the address of ISR to the register (for selected vectored interrupt)
	
	VICIntEnable |=(1<<(intnum+14));					//Enabling interrupt flag on the pin
	
	VICDefVectAddr = adrs; 										//Assigning the address of ISR to the register (for default loaction in case of nonvectored interrupt)
	
}

int main(void)
{
	
	interrupt_init((unsigned int)afunc,2,15,Falling);

	
	IO0DIR |= (1<<10);						//Setting the pins as output
  
	while(1)
  {

  }
}
