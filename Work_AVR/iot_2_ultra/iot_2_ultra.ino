//#include <serial.h>
#include <unoio.h>

# define F_CPU 16000000UL


void ultra(int trig,int echo, int trig1,int echo1)
{

if(echo<=7)
{
PCICR |= (1<<PCIE2);
PCMSK2 |= (1<<echo);
}
else if(echo>19 && echo<26)
{
echo-=20;
PCICR |= (1<<PCIE1);
PCMSK1 |= (1<<echo);
}
else if(echo>=8 && echo<=13)
{
echo-=8;
PCICR |= (1<<PCIE0);
PCMSK0 |= (1<<echo);
}

if(echo1<=7)
{
PCICR |= (1<<PCIE2);
PCMSK2 |= (1<<echo);
}
else if(echo1>19 && echo1<26)
{
echo1-=20;
PCICR |= (1<<PCIE1);
PCMSK1 |= (1<<echo);
}
else if(echo1>=8 && echo1<=13)
{
echo1-=8;
PCICR |= (1<<PCIE0);
PCMSK0 |= (1<<echo);
}

sei();
TCCR0B|=(1<<CS02);    
TCCR0B&=~(1<<CS01);    //prescaler 256 
TCCR0B|=(1<<CS00);     


pinmode(echo,0);
pinmode(trig,1);
pinmode(echo1,0);
pinmode(trig1,1);
digitalwrite(trig,0);

_delay_ms(100);
}





int b=0,d=0;
float c[2],e;
int main() {

Serial.begin(9600);

//ultra(2,8);

//ultra1(3,10);

pinmode(9,0);
pinmode(3,1);
pinmode(8,0);
pinmode(2,1);

PCICR |= (1<<PCIE0);
PCMSK0 |= (1<<1);
PCICR |= (1<<PCIE0);
PCMSK0 |= (1<<0);

sei();

TCCR0B|=(1<<CS02);    
TCCR0B&=~(1<<CS01);    //prescaler 256 
TCCR0B|=(1<<CS00);     
digitalwrite(2,0);
digitalwrite(3,0);

while(1) {
digitalwrite(2,0);
_delay_us(10);
digitalwrite(2,1);
_delay_us(10);
digitalwrite(2,0);
_delay_ms(500);
d^=1;
digitalwrite(3,0);
_delay_us(10);
digitalwrite(3,1);
_delay_us(10);
digitalwrite(3,0);
_delay_ms(500);
//Serial.print("hi");
e=(c[0]+c[1])/2;
Serial.println(e);
d^=1;


}
}

ISR(PCINT0_vect)
{
if(!b)
{TCNT0=0; b=1;}
else
{c[d]=TCNT0;c[d]=1.1*c[d];b=0;  
//Serial.println(c);
}
}

ISR(PCINT1_vect)
{
if(!b)
{TCNT0=0; b=1;}
else
{c[d]=TCNT0;c[d]=1.1*c[d];b=0;   
//Serial.println(c);
}
}

ISR(PCINT2_vect)
{
if(!b)
{TCNT0=0; b=1;}
else
{c[d]=TCNT0;c[d]=1.1*c[d];b=0;  
//Serial.println(c);
}
}
