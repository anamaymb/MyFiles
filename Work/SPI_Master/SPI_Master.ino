# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

char DATA=77;

void spitransmit(char a[])
{
for(int i=0;i<strlen(a);i++)
{  
  SPDR=a[i];                            //Putting the data to be transmitted in data register
  _delay_ms(4);                         //delay 
}
  _delay_ms(10);
}


void spitransmit(char a)
{
  SPDR=a;                            //Putting the data to be transmitted in data register
  _delay_ms(20);                         //delay 
}

void setup() {
  
SPCR |= (1<<SPE);                       //Enabling SPI communication
SPCR |= (1<<MSTR);                      //Declaring the controller as master device
SPCR &= ~(1<<SPR0);                     //Adjusting the SCK clock frequency
SPCR &= ~(1<<SPR1);                     //Here it is half of the clock frequncy of the controller
SPSR |= (1<<SPI2X);                     //

DDRB |= (1<<PB5);                       //SCK - Serial Clock
DDRB &= ~(1<<PB4);                      //MISO - Master in Slave out  (declared as input, all others are outputs)   
DDRB |= (1<<PB3);                       //MOSI - Master out Sslave in
DDRB |= (1<<PB2);                       //SS' - Slave select

_delay_ms(50);

  PORTB &= ~(1<<PB2);                   //SS' pin should be pulled low so as ti activate the slave, 
                                        //otherwise if the pin is pulled high, the slave will be passive and wont receive any data 
}

void loop() {
spitransmit(DATA);
}
