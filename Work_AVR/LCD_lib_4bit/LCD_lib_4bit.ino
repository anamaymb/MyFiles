# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

char a[]="Anamay Mahesh Belekar",b[]="Belekar";
int i=0,m=0,len,Len,col=0,Col=0;
uint8_t DL=40,DC=15,CD=1,DATA=65;


void pulse()                          //pulse on the enable pin after every instruction 
{_delay_ms(10);  
PORTB |= (1<<0);                      //Here enable pin is made high and low as pulse to  
_delay_ms(10);                        //pass the instruction to be collected from the lcd controller
PORTB &= ~(1<<0);
_delay_ms(10); 
}

void lcdbegin(int len)
{
DDRD = 255;                           //Initialising the pins as output
DDRB = 7;                             //Here PB0 = Enable, PB1 = RS
Len=len;
_delay_ms(20);
PORTB=0;                              //Here PB1 = 0, sending an instruction 
PORTD=0x20;                           //Data length selected = 8 bit, lines=2, font = 5 X 7
pulse();                              //.............
PORTD=0x80;                           //Data length selected = 8 bit, lines=2, font = 5 X 7
pulse();                              //.............
_delay_ms(20);


PORTB=0;
PORTD=0x00;                           //Display on, Cursor on, blink
pulse();
PORTD=0xF0;                           //Data length selected = 8 bit, lines=2, font = 5 X 7
pulse();                              //.............
_delay_ms(20);

PORTB=0;
PORTD=0x00;                           //Clear Display, Cursor at home
pulse();
PORTD=0x10;                           //Data length selected = 8 bit, lines=2, font = 5 X 7
pulse();                              //.............
_delay_ms(20);


_delay_ms(50);
}

void lcdprint(char a[])
{

for(i=0;i<=200;i++)
{
DATA=a[i];

PORTB |= (1<<1);                              //Here PB1 = 1, sending the data
PORTD = DATA;                                   //sending the data to lcd one byte at a time
pulse();
//_delay_ms(1000);
PORTB |= (1<<1);                              //Here PB1 = 1, sending the data
PORTD = (DATA<<4);                                   //sending the data to lcd one byte at a time
pulse();


if(i>=(Len-Col) && !m)                        //if the first line of the lcd is full, then
{
m=1;
PORTB=0;
PORTD=0xC0;                                   //Cursor at start of line 2
pulse();
PORTD=0x00;                                   //Cursor at start of line 2
pulse();
}
}
m=0;
}

void lcdclr()
{
PORTB=0;
PORTD=0x01;                                   ////Clear Display, Cursor at home
pulse();
col=0;
Col=0;
}

void lcdmovecursor(int col)
{
  Col=col;
  for(i=0;i<col;i++)
  {
    PORTB=0;
    PORTD=0x14;                               //Shift cursor position to right
    pulse();
  }
}


void setup()
{
lcdbegin(16);                                 //initialise lcd
pinMode(10,OUTPUT);
}

void loop() {
analogWrite(10,127);
lcdprint("Password please");
}
