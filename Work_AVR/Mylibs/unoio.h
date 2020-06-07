#define A0 20
#define A1 21
#define A2 22
#define A3 23
#define A4 24
#define A5 25


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
