#define A0 20
#define A1 21
#define A2 22
#define A3 23
#define A4 24
#define A5 25
int zjqxatk=0;

void pinmode(int pin,int dir)
{

 if(dir==1){ 
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    pin=pin-20;
    DDRC|=(1<<pin);
  }
  else if(pin>=0 && pin<=7)
  {
    DDRD|=(1<<pin);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    DDRB|=(1<<pin);
  }
}


 if(dir==0){ 
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    pin=pin-20;
    DDRC&= ~(1<<pin);
  }
  else if(pin>=0 && pin<=7)
  {
    DDRD&= ~(1<<pin);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    DDRB&= ~(1<<pin);
  }
}


 if(dir==2){ 
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    pin=pin-20;
    DDRC&= ~(1<<pin);
    PORTC |= (1<<pin);
  }
  else if(pin>=0 && pin<=7)
  {
    DDRD&= ~(1<<pin);
    PORTC |= (1<<pin);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    DDRB&= ~(1<<pin);
    PORTC |= (1<<pin);
  }
}

}

int digitalread(int pin){
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    int pin1=pin-20;
    int a=(PINC&(1<<pin1))/(1<<pin1);
    return(a);
  }
  else if(pin>=0 && pin<=7)
  {
    int a=(PIND&(1<<pin))/(1<<pin);
    return(a);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    int a=(PINB&(1<<pin))/(1<<pin);
    return(a);
  }

}

void digitalwrite(int pin,int val)
{
 if(val){ 
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    pin=pin-20;
    PORTC|=(1<<pin);
  }
  else if(pin>=0 && pin<=7)
  {
    PORTD|=(1<<pin);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    PORTB|=(1<<pin);
  }
}

 if(!val){ 
  if(pin==A0 || pin==A1 || pin==A2 || pin==A3 || pin==A4 || pin==A5)
  {
    pin=pin-20;
    PORTC &= ~(1<<pin);
  }
  else if(pin>=0 && pin<=7)
  {
    PORTD &= ~(1<<pin);
  }
  else if(pin>=8 && pin<=13)
  {
    pin=pin-8;
    PORTB &= ~(1<<pin);
  }
}


}




int analogread(int pinn)
{
ADCSRA |= (1<<ADEN);

ADMUX &= ~(1<<ADLAR);

ADCSRA |= (1<<ADPS2);
ADCSRA &= ~(1<<ADPS1);
ADCSRA &= ~(1<<ADPS0);

ADMUX &= ~(1<<REFS1);
ADMUX |= (1<<REFS0);

ADCSRA |= (1<<ADATE);

if(pinn%2==0)
ADMUX &= ~(1<<MUX0);
else
ADMUX |= (1<<MUX0);

if(((pinn-20)/2)%2==0)
ADMUX &= ~(1<<MUX1);
else
ADMUX |= (1<<MUX1);

if(!((pinn-20)/4))
ADMUX &= ~(1<<MUX2);
else
ADMUX |= (1<<MUX2);

ADMUX &= ~(1<<MUX3);

ADCSRB |= (1<<ADTS2);
ADCSRB &= ~(1<<ADTS1);
ADCSRB &= ~(1<<ADTS0);

sei();

ADCSRA |= (1<<ADIE);
delay(2);
return zjqxatk;
}


ISR(ADC_vect)
{
  int a,b;
  a=ADCL;
  b=ADCH;
  b=(b<<8);
  zjqxatk=a+b;
 }

