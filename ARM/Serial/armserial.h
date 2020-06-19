class serial{

	char b[10],bf[15];
	int count,countf,len;
	int serialavailable;
	char z[100];
	int scara;

	
	private:
	
		void rotate()
		{
			for(int o=0;o<serialavailable-1;o++)
			z[o]=z[o+1];
			serialavailable--;
		}
		int rev(int y,int e)												//reversing a number
		{
			int d=0;

			for(int p=e-1;p>=0;p--)
			{
				d=d+ten(p)*(y%10);
				y=y/10;
			}
			return d;
		}
		
		
		void delayms(int n)
		{
			n*=1000;
			for(scara=0; scara<n; scara++);
		}
		int revf(float y,int e)												//reversing a number
		{
			float d=0.0;
			int c=y;
			for(int p=e-1;p>=0;p--)
			{
				d=d+ten(p)*(c%10);
				c=c/10;
			}
			
			return d;
		}	
	
	
	
	public:

		void y()												            //ISR
		{
			if(U0LSR & (1<<0)){														//Empty the receive buffer
			z[serialavailable]=U0RBR;											//in the array (queue) z[]
			serialavailable++;}														//serialavailable keeps check of number of available unread data
		}

		void flush()																				//to empty the receive buffer z[], for newest data to receive
		{
			U0IER &= ~(1<<0);																						//Avoiding disturbance of interrupt in the function 
			
			while(serialavailable){

				rotate();
				
				if (serialavailable<6 && z[0]=='\0')											//In case if int data is getting flushed
					break;

				if(!serialavailable)
				{
					U0IER |= (1<<0);
					while (serialavailable<5);
					U0IER &= ~(1<<0);
				}
				}
			U0IER |= (1<<0);
		}

		int ten(int y)															//to obtain any power of 10
		{
			int u=1;
			for(int g=0;g<y;g++)
			u*=10;
			return u;
		}
		
		float point(float y)
		{
			float u=1.0;
			for(int g=0;g<y;g++)
			u/=10;
			return u;
		}
		
		
		float Read()
		{
			int n=z[0],m=0,md=0,g=0,nice=0;
			float mf=0;
			if(n=='\0')
			{

				rotate();
				
						if(z[0]=='\0')
						{
						
						delayms(35);
							
						rotate();
							
						if(z[0]==45)
						{
						nice=1;
						rotate();
						}
						
						mf=mf+ten(g)*(z[0]-48);
						g++;
						
						rotate();
						
						for(g=1;z[0]!='.';g++)
						{
						mf=mf+ten(g)*(z[0]-48);
						rotate();
						}
						
						rotate();

						md=mf;
						mf=rev(md,g);
						
						for(int y=0;y<4;y++)
						{
						mf=mf+point(y+1)*(z[0]-48);
						rotate();
						}
						
						if(z[0]==13)
						{
						rotate();
						}
						
						
						return ((1 +  (-2)*nice)*mf);

						}
				else{
				
				delayms(15);
				

				if(z[0]==45)
				{
				nice=1;
				rotate();
				}
				
				m=m+ten(g)*(z[0]-48);
				g++;
				
				rotate();
				
				for(g=1;(z[0]!='\0' && z[0]!=13);g++)
				{

				m=m+ten(g)*(z[0]-48);

				rotate();
				}
				
				if(z[0]==13)
				{
					rotate();
				}
				
				if (nice)
				return (-1*rev(m,g));
				else
				return rev(m,g);
			}		
		}
			else
			{
			rotate();
			return n;
			}
		}


		int kitiaahe()
		{
			if(z[0]=='\0')
			while(serialavailable<=15);
			return serialavailable;
		}

		void print(char t)
		{
			U0THR= t;
			delayms(3);
		}

		void println(char t)
		{
			U0THR= t;
			delayms(3);
			U0THR= 13;
			delayms(3);
		}

		int strlen(char a[])
		{
			len=0;
			while(a[len]!='\0')
				len++;
			
			return len;
		}


		void print(char a[])
		{
			for(int i=0;i<strlen(a);i++)
			{		
			U0THR = a[i];
			delayms(10);
			}
			
		}

		void println(char a[])
		{
			for(int i=0;i<strlen(a);i++)
			{		
			U0THR = a[i];
			delayms(10);
			}
			U0THR= 13;
			delayms(3);
		}


		void itoa(int a)
		{
			int r=a;
			count=0;
			if(r<0)
			a=-a;
			do
			{
				b[count]=(a%10)+48;
				count++;a/=10;
			}
			while(a!=0);

			if(r<0)
			{
				b[count]=45;
				count++;
			}
		}

		void ftoa(float a)
		{
			
			float q=0.0;
			if(a<0){
			a=-a;q=1.0;}
			
			int tem;
			tem=a;
			
			char bt[10];
			countf=0;
			int floatemp=0;
			float temf=a-tem;
			
			do
			{
				bt[countf]=(tem%10)+48;
				countf++;tem/=10;
			}
			while(tem!=0);
			
			if(q==1.0)
			{
				bt[countf]=45;
				countf++;
			}
			
			for(int i=0;i<countf;i++)
			bf[countf-i-1]=bt[i];
			
			
			bf[countf]=46;
			countf++;
			
			
			temf=temf*10000;

			floatemp=temf;

			
			for (int i=0;i<4;i++)
			{
				bf[countf+3-i]=floatemp%10 + 48;
				floatemp/=10;
			}
			countf+=4;
			
		}

		void print(float a)
		{
			ftoa(a);
			U0THR = 0;
			delayms(10);
			U0THR = 0;
			delayms(10);
			
			for(int i=0;i<countf;i++)
			{
			if((bf[i]>=48 && bf[i]<=57) || bf[i]==46 || bf[i]==45){
			U0THR = bf[i];
			delayms(10);}
			}
			

		}
		
		
		void println(float a)
		{
			ftoa(a);
			U0THR = 0;
			delayms(10);
			U0THR = 0;
			delayms(10);
			
			for(int i=0;i<countf;i++)
			{
			if((bf[i]>=48 && bf[i]<=57) || bf[i]==46 || bf[i]==45){
			U0THR = bf[i];
			delayms(10);}
			}
			
			U0THR= 13;
			delayms(3);

		}
		
		void print(int a)
		{
			itoa(a);

			U0THR = 0;
			delayms(10);
			
			for(int i=(count-1);i>=0;i--){
				if((b[i]>=48 && b[i]<=57) || b[i]==45){
			U0THR = b[i];
			delayms(10);}
		}
		}



		void println(int a)
		{
				itoa(a);

			U0THR = 0;
			delayms(10);
			
			for(int i=(count-1);i>=0;i--){
				if((b[i]>=48 && b[i]<=57) || b[i]==45){
			U0THR = b[i];
			delayms(10);}
		}
			U0THR= 13;
			delayms(3);
		}

}serial;

__irq void send(void)							//UART0 RX interrupt
{
	serial.y();
}

void serialbegin()
{
	int scara=0;
		//If simulating on proteus, Adjust clock frequency of the lpc module to 20MHz
	
	PINSEL0 |= (1<<0);						//Setting the pin as Tx
	PINSEL0 &= ~(1<<1);
	
	PINSEL0 |= (1<<2);						//Setting the function of the pi as Rx
	PINSEL0 &= ~(1<<3);
	
	U0LCR |= (1<<7);							//Enabling divisor latch access bit
	
	U0DLM=2;
	U0DLL=139;										//Setting the divisor for baud rate

//	U0DLM=1;
//	U0DLL=134;										//Setting the divisor for baud rate


	//U0FDR = 0x00000063;						//Setting the clock prescaler multiplier

	U0LCR &= ~(1<<7);							//Disabling the divisor latch bit
	
	U0LCR |= (1<<0)|(1<<1);				//Setting the length of the data as 8 bit
	
	U0LCR &= ~(1<<3);							//One stop bit
	U0LCR &= ~(1<<2) ;						//Disabling parity bit

	U0IER |= (1<<0);							//Enabling serial receive interrupt
	
	U0TER |= (1<<7);							//Enabling transmission at Tx


	VPBDIV |= (1<<0);							//VPB bus clock is the same as the processor clock.

//////////////////////////////////////////////////

	VICIntEnable |= (1<<6);										//Enabling UART0 interrupt

	VICIntSelect &= ~(1<<6);									//Setting the interrupt in as vectored IRQ (And not FIQ)

	VICVectCntl4 |= (1<<5);										//Enabling selected vectored IRQ function (and not nonvectored interrupt)
	VICVectCntl4 |= 6;												//Putting the interrupt number (for UART0 it is 6)

	VICVectAddr4 = (unsigned int)send;					//Assigning the address of ISR to the register (for selected vectored interrupt)
	
	for(scara=0; scara<100000; scara++);
	
}

