

void serialprint(char a[]){
  for(int i=0;i<strlen(a);i++){
  UDR0 = a[i];
  _delay_ms(2);
}}

void serialprintln(char a[]){
  for(int i=0;i<strlen(a);i++){
  UDR0 = a[i]; _delay_ms(2);
}
   UDR0 = 10; _delay_ms(2);
}

void serialprint(int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}}

void serialprintln(int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}
  UDR0 = 10; _delay_ms(2);
}

void serialprint(unsigned int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}}

void serialprintln(unsigned int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}
  UDR0 = 10; _delay_ms(2);
}

void serialprint(unsigned long int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}}

void serialprintln(unsigned long int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}
  UDR0 = 10; _delay_ms(2);
}

void serialprint(long int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}}

void serialprintln(long int a){
char b[10];itoa(a,b,10);
  for(int i=0;i<strlen(b);i++){
  UDR0 = b[i];
  _delay_ms(2);
}
  UDR0 = 10; _delay_ms(2);
}

void serialprint(char a){
  UDR0 = a;_delay_ms(2);
}

void serialprintln(char a){
  UDR0 = a;_delay_ms(2);
  UDR0 = 10;_delay_ms(2);
}



void serialbegin(int baud)
{
sei();
int ubrr;
ubrr=(16000000/baud)/16-1;                  //Setting baud rate
UBRR0L = ubrr;                              //Here 9600
UBRR0H = (ubrr>>8);                         //SAme as Serial.begin


UCSR0B |= ((1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0));      //Enabling the transmitter

UCSR0B &= ~(1<<UCSZ02);                     //ninth bit, here 0

UCSR0C &= ~(1<<UMSEL00);                    //Selecting the type of operation of Usart
UCSR0C &= ~(1<<UMSEL01);                    //Here Asynchronous USART

UCSR0C &= ~(1<<UPM00);                       //Parity bit
UCSR0C &= ~(1<<UPM01);                       //parity disabled here

UCSR0C |= (1<<UCSZ01);                      //Selecting the width of data, here 8 bit
UCSR0C |= (1<<UCSZ00);

UCSR0C &= ~(1<<USBS0);                      //one stop bit

//UCSR0A |= ((1<<TXC0));                      //Setting the USART transmit complete bit
}
