#include <lpc214x.h>
unsigned int i;

void delay(int n)
{
	//unsigned int i;
	n*=1000;
	for(i=0; i<n; i++);
}

int main(void)
{
	PINSEL0 |= (1<<0);
	PINSEL0 &= ~(1<<1);
	PINSEL0 |= (1<<2);
	PINSEL0 &= ~(1<<3);
	
	U0LCR |= (1<<7);
	U0DLM=0;
	U0DLL=93;
	U0FDR = 0x00000052;
		

  U0LCR &= ~(1<<7);
	
	//U0FCR |= (1<<0)|(1<<2);
	U0LCR |= (1<<0)|(1<<1);
	U0LCR &= ~(1<<3);
	U0LCR &= ~(1<<2) ;
	//U0LCR &= ~(1<<4);
	//U0LCR &= ~(1<<5);
	U0TER |= (1<<7);



/*
PLL0CON = 0x01;   //Enable PLL
  PLL0CFG = 0x24;   //Multiplier and divider setup    
  PLL0FEED = 0xAA;  //Feed sequence
  PLL0FEED = 0x55;
  
  while(!(PLL0STAT & 0x00000400)); //is locked?
    
  PLL0CON = 0x03;   //Connect PLL after PLL is locked
  PLL0FEED = 0xAA;  //Feed sequence
  PLL0FEED = 0x55;  //

	//*/
VPBDIV |= (1<<0);



  while(1)
  {

		//while (!(U0LSR & (1<<5)));
		U0THR='A';
		//while( (U0LSR & 0x40) == 0 );
		delay(100);
  }
}


/*
#include <lpc214x.h>
#include <stdint.h>
void UART0_init(void)
{
	PINSEL0 = PINSEL0 | 0x00000005;	// Enable UART0 Rx0 and Tx0 pins of UART0 
	U0LCR = 0x83;	  //DLAB = 1, 1 stop bit, 8-bit character length 
	U0DLM = 0x00;	// For baud rate of 9600 with Pclk = 15MHz 
	U0DLL = 0x61;		// We get these values of U0DLL and U0DLM from formula 
	U0LCR = 0x03; 	// DLAB = 0 
}
void UART0_TxChar(char ch) //A function to send a byte on UART0 
{
	U0THR = ch;
	while( (U0LSR & 0x40) == 0 );	// Wait till THRE bit becomes 1 which tells that transmission is completed 
}




int main(void)
{
	char receive;
	UART0_init();
	VPBDIV = 0x01;
	while(1)
	{

		UART0_TxChar('A');
		//UART0_SendString("\r\n");
	}
}

*/



/*

#include <lpc214x.h>

void initClocks(void);
void initUART0(void);
void U0Write(char data);
void Send_String(char* StringPtr);

char String[]="Hello from BINARYUPDATES.COM !!! \n\r\n";
unsigned int delay;

int main(void)
{
  initClocks(); // Set CCLK=60Mhz and PCLK=60Mhz 
  initUART0();
  
  while(1)    
  {        
    Send_String(String);    //Pass the string to the USART_putstring function and sends it over the serial     
    for(delay=0; delay<500000; delay++); // delay
  }
}

void initUART0(void)
{
  PINSEL0 = 0x5;  //Select TxD for P0.0 and RxD for P0.1 
  U0LCR = 0x83; // 8 bits, no Parity, 1 Stop bit | DLAB set to 1 
  
//	U0DLL = 110;
 // U0DLM = 1;   
  //U0FDR = 0xF1; // MULVAL=15(bits - 7:4) , DIVADDVAL=0(bits - 3:0)
  
	U0DLM=0;
	U0DLL=93;
	U0FDR = 0x00000052;
	
	
	U0LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
  //BaudRate is now ~9600 and we are ready for UART communication! 
}

void U0Write(char data)
{
  while (!(U0LSR & (1<<5))); // wait till the THR is empty
  // now we can write to the Tx FIFO
  U0THR = data;
}

void initClocks(void)
{
  PLL0CON = 0x01;   //Enable PLL
  PLL0CFG = 0x24;   //Multiplier and divider setup    
  PLL0FEED = 0xAA;  //Feed sequence
  PLL0FEED = 0x55;
  
  while(!(PLL0STAT & 0x00000400)); //is locked?
    
  PLL0CON = 0x03;   //Connect PLL after PLL is locked
  PLL0FEED = 0xAA;  //Feed sequence
  PLL0FEED = 0x55;
  VPBDIV = 0x01;    // PCLK is same as CCLK i.e.60 MHz
}

void Send_String(char* StringPtr){
 
 while(*StringPtr != 0x00){
 U0Write(*StringPtr);
 StringPtr++;}
}
*/

