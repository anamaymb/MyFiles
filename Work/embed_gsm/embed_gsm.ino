#include <serial.h>

int main()
{
  serialbegin(9600);
char a=26;
    _delay_ms(1000);
  
  while(1)
  {

    serialprintln("AT+CMGF=1");//+\r\n");
    _delay_ms(1000);

    serialprintln("AT+CMGS=\"9405958834\"\r");//+\r\n");
    _delay_ms(1000);//    Serial.print("5");

    serialprintln("AnamayMBelekar");//+\r\n");
    _delay_ms(1000);//    Serial.print("6");

    serialprintln(char(26));//\r\n");
    _delay_ms(1000);

  }
}
