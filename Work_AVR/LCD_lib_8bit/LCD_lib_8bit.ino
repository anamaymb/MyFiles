# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

char a[]="Anamay Mahesh Belekar",b[]="Belekar";
int i=0,m=0,len,Len,col=0,Col=0;

void pulse()                          //pulse on the enable pin after every instruction 
{
PORTB |= (1<<0);                      //Here enable pin is made high and low as pulse to  
_delay_ms(10);                        //pass the instruction to be collected from the lcd controller
PORTB &= ~(1<<0);
}

void lcdbegin(int len)
{
DDRD = 255;                           //Initialising the pins as output
DDRB = 7;                             //Here PB0 = Enable, PB1 = RS
Len=len;

PORTB=0;                              //Here PB1 = 0, sending an instruction 
PORTD=0x38;                           //Data length selected = 8 bit, lines=2, font = 5 X 7
pulse();                              //.............

PORTB=0;
PORTD=0x0F;                           //Display on, Cursor on, blink
pulse();

PORTB=0;
PORTD=0x01;                           //Clear Display, Cursor at home
pulse();

_delay_ms(50);
}

void lcdprint(char a[])
{
for(i=0;i<=strlen(a);i++)
{
PORTB |= (1<<1);                              //Here PB1 = 1, sending the data
PORTD=a[i];                                   //sending the data to lcd one byte at a time
pulse();

if(i>=(Len-Col) && !m)                        //if the first line of the lcd is full, then
{
m=1;
PORTB=0;
PORTD=0xC0;                                   //Cursor at start of line 2
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
  pinMode(10,OUTPUT);
lcdbegin(16);                                 //initialise lcd
}

void loop() {

analogWrite(10,127);
lcdprint("Password please");
_delay_ms(100);
lcdclr();
_delay_ms(100);
lcdmovecursor(10);
lcdprint("BBBB BBBB BBBB BBBB B");
_delay_ms(100);
lcdclr();
lcdprint("CCCCCCCCCCCCCCCCCCCCCCCCCC");
while(1);
}
