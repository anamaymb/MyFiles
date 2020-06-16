# include <gavthiserial.h>
# include <unoio.h>

void setup() {
serialbegin(9600);
}
int cobr=0,i=0;
char a='A';
/*
int cobr=0;


int zjqxatk=0;
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
*/
void loop() {

cobr=analogread(A5);

serialprint(cobr);

 /*while(i<=5){
  Serial.print(a);
  i++;
  a++;
  _delay_ms(10);
 }

delay(500);

while(i<=10){
  Serial.print(a);
  i++;
  a++;
  _delay_ms(10);
 }
 
  if(i==11)
  while(1);
  */
}
