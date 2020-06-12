#include <gavthiserial.h>
#include <softserial.h>

void setup() {
serialbegin(9600);
}
/*
void y()
{
  z[serialavailable]=UDR0;
  serialavailable++;
  UCSR0B |= (1<<RXCIE0);
}
char serialread()
{
int n=z[0];
for(int o=0;o<serialavailable-1;o++)
z[o]=z[o+1];

serialprintln(serialavailable);
serialavailable--;
return n;
}*/

char a;
void loop() 
{
delay(200);
  
if(serial.kitiaahe()){
a=serial.Read();
serialprintln(a);
}

}
/*
ISR(USART_RX_vect)
{
  UCSR0B &= ~(1<<RXCIE0);
  serial.y();
}*/
