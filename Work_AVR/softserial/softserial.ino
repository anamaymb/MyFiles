#include <gavthiserial.h>
#include <softserial.h>
  
/*
class softserial 
{  
  int n,m;

    public: 

    void Begin(int s,int r)
    {

      n=s;
      m=r;
      pinmode(n,1);
      pinmode(m,0);
      digitalwrite(n,1);
      _delay_ms(104);
    }

    char receive()
    {
      char w=0;
      while(digitalread(m));
      _delay_us(52);
      if(!digitalread(m))
      {
        _delay_us(100);
        for(int i=0;i<8;i++)
        {
          w=w|(digitalread(m)<<i);
          _delay_us(100);
        }
        
      }
      else 
      receive();
      //Serial.print(w);
      return (w);
    }

    void Print(int a) 
    { 
      char b[10];itoa(a,b,10);

      for (int j=0;j<strlen(b);j++)
      {
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(b[j] &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    } 
    }

    void Println(int a) 
    { 
      char b[10];itoa(a,b,10);

      for (int j=0;j<strlen(b);j++)
      {
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(b[j] &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    } 
    int ab=13;
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(ab &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    }

  
    void Print(char a) 
    { 
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(a &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    } 

    void Print(char a[]) 
    { 
      for(int j=0;j<strlen(a);j++)
      {
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(a[j] &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(1004);
    }
    }

    void Println(char a[]) 
    { 
      for(int j=0;j<strlen(a);j++)
      {
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(a[j] &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(1004);
    }

        int ab=13;
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(ab &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    
    }


    
    void Println(char a) 
    { 
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(a &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_ms(1);

        a=13;
        digitalwrite(n,0);
        _delay_us(104);

        for(int i=0;i<8;i++)
        {
          digitalwrite(n,(a &(1<<i)));
          _delay_us(104);
        }
        
        digitalwrite(n,1);
        _delay_us(104);
    }
}; 
*/

softserial ss;
char e;

void setup() {
ss.Begin(A0,9);              //Enter pin number (Tx,Rx)
_delay_ms(100);

}
void loop() {

e=ss.receive();

ss.Println(e);

}
