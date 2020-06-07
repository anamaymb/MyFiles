# include <gavthiserial.h>

void setup() {
//PRR &= (1<<PRADC);
  
ADCSRA |= (1<<ADEN);

ADMUX &= ~(1<<ADLAR);

ADCSRA |= (1<<ADPS2);
ADCSRA &= ~(1<<ADPS1);
ADCSRA &= ~(1<<ADPS0);

ADMUX &= ~(1<<REFS1);
ADMUX |= (1<<REFS0);

ADCSRA |= (1<<ADATE);

ADMUX &= ~(1<<MUX1);
ADMUX &= ~(1<<MUX0);
ADMUX &= ~(1<<MUX2);
ADMUX &= ~(1<<MUX3);

ADCSRB |= (1<<ADTS2);
ADCSRB &= ~(1<<ADTS1);
ADCSRB &= ~(1<<ADTS0);

sei();

ADCSRA |= (1<<ADIE);

serialbegin(9600);
pinMode(5,OUTPUT);
}
int a,b;
void loop() {
  analogWrite(5,200);
}

ISR(ADC_vect)
{
  a=ADCL;
  b=ADCH;
  b=(b<<8);
  serialprintln(a+b);
}

