#include <gavthiserial.h>
//#include <softserial.h>
#include<unoio.h>
int zjqxatk79=0,zjqxatk86=0;


void analogwrite(int pinn, int pwm)
{
sei();

if(pinn==3)
zjqxatk79=pinn;
else if(pinn==6)
zjqxatk86=pinn;

if(pinn==3){
TCCR0A &= ~(1<<COM0A0);
TCCR0A |= (1<<COM0A1);
}
if(pinn==6){
TCCR0A &= ~(1<<COM0B0);
TCCR0A |= (1<<COM0B1);
}

TCCR0A |= (1<<WGM02)|(1<<WGM01)|(1<<WGM00);

TCCR0B |= (1<<CS00);
TCCR0B |= (1<<CS01);
TCCR0B &= ~(1<<CS02);

if(pinn==3)
OCR0A=pwm;
else if(pinn==6)
OCR0B=pwm;

if(pinn==3)
TIMSK0|=(1<<1)|(1<<0);
else if(pinn==6)
TIMSK0|=(1<<2)|(1<<0);

if(pinn==3)
TIFR0|=(1<<1)|(1<<0);
else if(pinn==6)
TIFR0|=(1<<2)|(1<<0);


pinmode(pinn,1);

}



int main() {

while(1)
{
  analogwrite(6,43);
    analogwrite(3,233);
}

return 0;
}


ISR(TIMER0_COMPA_vect)
{
  digitalwrite(zjqxatk79,0);
}
ISR(TIMER0_COMPB_vect)
{
  digitalwrite(zjqxatk86,0);
}
ISR(TIMER0_OVF_vect)
{
  if(zjqxatk79)
  digitalwrite(zjqxatk79,1);
  if(zjqxatk86)
  digitalwrite(zjqxatk86,1);
}
