class softserial 
{  
  int n;
  
    public: 

    void Begin(int s)
    {
      n=s;
      pinMode(n,OUTPUT);
      digitalWrite(n,1);
      delay(300);
    }
  
    void Print(char a) 
    { 
        digitalWrite(n,0);
        delayMicroseconds(100);

        for(int i=0;i<8;i++)
        {
          digitalWrite(n,(a &(1<<i)));
          delayMicroseconds(100);
        }
        
        digitalWrite(n,1);
        delayMicroseconds(100);
    } 
    void Printnxt(char a) 
    { 
      a+=1;
        digitalWrite(n,0);
        delayMicroseconds(100);

        for(int i=0;i<8;i++)
        {
          digitalWrite(n,(a &(1<<i)));
          delayMicroseconds(100);
        }
        
        digitalWrite(n,1);
        delayMicroseconds(100);
    }
}; 






softserial ss;
char chr;




void softserialprint(char a)
{
  digitalWrite(3,0);
delayMicroseconds(100);


for(int i=0;i<8;i++){
  digitalWrite(3,(a &(1<<i)));
  delayMicroseconds(100);
}

digitalWrite(3,1);
delayMicroseconds(100);
}

void setup() {
ss.Begin(9);
}
void loop() {
  

chr='G';

/*digitalWrite(3,1);
delayMicroseconds(100);
digitalWrite(3,1);
delayMicroseconds(100);
digitalWrite(3,0);
delayMicroseconds(100);
digitalWrite(3,0);
delayMicroseconds(100);
digitalWrite(3,0);
delayMicroseconds(100);
digitalWrite(3,0);
delayMicroseconds(100);
digitalWrite(3,1);
delayMicroseconds(100);
digitalWrite(3,0);
delayMicroseconds(100);
*/

ss.Print(chr);

delay(10);


}
