#include<serial.h>
int a=200;


void setup()
{
 
  serialbegin(9600);    // the GPRS baud rate 
  _delay_ms(1000);
}
 
void loop()
{
   
      _delay_ms(2);          
       Send2Pachube(a);
       a+=50;
}
void Send2Pachube(int a)
{
  char b[10];
itoa(a,b,10);
  
  serialprintln("AT");
  _delay_ms(1000);

  serialprintln("AT+CPIN?");
  _delay_ms(1000);

  serialprintln("AT+CREG?");
  _delay_ms(1000);

  serialprintln("AT+CGATT?");
  _delay_ms(1000);

  serialprintln("AT+CIPSHUT");
  _delay_ms(1000);

  serialprintln("AT+CIPSTATUS");
  _delay_ms(2000);

  serialprintln("AT+CIPMUX=0");
  _delay_ms(2000);
 
  serialprintln("AT+CSTT=\"bsnlnet\"");//start task and setting the APN,
  _delay_ms(1000);
 
  serialprintln("AT+CIICR");//bring up wireless connection
  _delay_ms(3000);
 
  serialprintln("AT+CIFSR");//get local IP adress
  _delay_ms(2000);
 
  serialprintln("AT+CIPSPRT=0");
  _delay_ms(3000);
 
  serialprintln("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  _delay_ms(6000);
 
  serialprintln("AT+CIPSEND");//begin send data to remote server
  _delay_ms(4000);
  
    char str[]="GET http://api.thingspeak.com/update?api_key=57VK2JJYA7HKD9HL&field1=0";
    strcat(str, b);
  serialprintln(str);//begin send data to remote server
  _delay_ms(4000);

  serialprintln((char)26);//sending
  _delay_ms(5000);//waitting for reply, important! the time is base on the condition of internet 
 
  serialprintln("AT+CIPSHUT");//close the connection
  _delay_ms(100);
} 
