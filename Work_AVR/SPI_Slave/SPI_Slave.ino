# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
//#include <gavthiserial.h>
char DATA;

void setup() {
SPCR |= (1<<SPE);                        //Enabling SPI communication
SPCR |= (1<<SPIE);                       //SPI interrupt enable (interrupt is generated at end of transfer of 1 byte)
SPCR &= ~(1<<MSTR);                      //Declaring the controller as slave device
//SPCR |= (1<<SPR0);                  
//SPCR |= (1<<SPR1);                    //No need of declaring the frerquency at the slave end   
//SPSR &= ~(1<<SPI2X);
Serial.begin(9600);

sei();                                    //Global interrupt enable

DDRB &= ~(1<<PB5);                      //SCK,MOSI and SS' pins are already declared as input pins as soon as we declare the controller as slave 
DDRB |= (1<<PB4);                         //No need of redeclaration, only MISO pin to be declared as output  
DDRB &= ~(1<<PB3);
DDRB &= ~(1<<PB2);
}

void loop() {

}

ISR (SPI_STC_vect)                        //ISR - When the SPIF flag is set after the completion of the transfer of a single byte, this interrupt is generated and the SPIF bit is reset  
{
DATA=SPDR;                                //fetching the data from the data register
Serial.print(DATA);
}

