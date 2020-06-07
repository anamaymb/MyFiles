#include <gavthiserial.h>
#include <unoio.h>

const int ROWS = 4; //four rows
const int COLS = 3; //three columns
int keys[ROWS][COLS] = {
  {1,2,3},
  {4,5,6},
  {7,8,9},
  {0,0,0}
};

byte rowpins[ROWS] = {A0, A1, A2, A3};
byte colpins[COLS] = {A4, A5, 13};

/*
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
*/

int getkey()
{
      digitalwrite(colpins[0],1);
      digitalwrite(colpins[1],1);
      digitalwrite(colpins[2],1);
  for(int i=0;i<COLS;i++)
  {
    digitalwrite(colpins[i],0);
    for(int j=0;j<ROWS;j++){
    if(!digitalread(rowpins[j])){
      while(!digitalread(rowpins[j]));
      digitalwrite(colpins[i],1);
      return(keys[j][i]);
    }
    }
    digitalwrite(colpins[i],1);
    
  }
  return(10);
}


int main() {
serialbegin(9600);
pinmode(A0,2);
pinmode(A1,2);
pinmode(A2,2);
pinmode(A3,2);
pinmode(A4,1);
pinmode(A5,1);
pinmode(13,1);


while(1) {
int a=getkey();
if(a!=10)
serialprintln(a);
}
}
