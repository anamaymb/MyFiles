#include <lpc214x.h>
#include "armserial.h"

unsigned int i;
void delay(int n)
{
	n*=1000;
	for(i=0; i<n; i++);
}

int main(void)
{
serialbegin();
char k;
int l;
float m;
  
	while(1)
  {
		if(serial.kitiaahe())
		{
			l=serial.Read();
			serial.println(l);
		}
  }
}

