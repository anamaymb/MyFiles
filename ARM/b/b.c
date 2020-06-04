#include <lpc214x.h>
unsigned int i;

void delay(int n)
{
	//unsigned int i;
	n*=1000;
	for(i=0; i<n; i++);
}

int main(void)
{
  IO0DIR = 0xFFFFFFFF;
  
  while(1)
  {
    IO0CLR = (1<<10)|(1<<11);
    delay(500);
    IO0SET = (1<<10)|(1<<11);
    delay(500);
  }
}
