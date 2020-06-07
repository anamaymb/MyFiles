#include <gavthiserial.h>
#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

enum
{
CMD=0,
DATA,
};
 
char buf[100];
volatile char ind,flag,stringReceived;
char gpgga[]={'$','G','P','G','G','A'};
 
char latitude[12];
char logitude[12];


ISR(USART_RX_vect)
{
char ch=UDR0;
buf[ind]=ch;
ind++;
if(ind<7)
{
if(buf[ind-1] != gpgga[ind-1])               // $GPGGA
ind=0;
}
if(ind>=50)
stringReceived=1;
}

int main()
{
  sei();
serialbegin(9600);
serialprint("ok");
_delay_ms(2000);

while(1)
{
if(stringReceived == 1)
{
cli();
serialprint("Received String:");
for(int i=0;i<ind;i++)
serialprint(buf[i]);
ind=0;
stringReceived=0;
serialprintln(" ");
serialprint("Latitude:");
for(int i=15;i<27;i++)
{
latitude[i]=buf[i];
serialprint(latitude[i]);

}
serialprintln(" ");
serialprint("Logitude:");
for(int i=29;i<41;i++)
{
logitude[i]=buf[i];
serialprint(logitude[i]);
 
}
serialprintln(" ");
_delay_ms(2000);
sei();
}
}
return 0;
}
