#include<stdio.h>

int main()
{
    float x1=0.5,y1=1.4,x2=2.3,y2=1.9,x3=2.9,y3=3.2,h=0.001;
    float m=1.0,mt=1.001,m_prev=0.97,c=10.00,ct=10.001,sum=0.0,sum_prev=0.0,sum_prev2=0,m1=0.0;
    int w=0;
    float e[3]={y1-m_prev*x1-c,y2-m_prev*x2-c,y3-m_prev*x3-c},e1[3]={y1-mt*x1-c,y2-mt*x2-c,y3-mt*x3-c},e2[3]={y1-m*x1-ct,y2-m*x2-ct,y3-m*x3-ct};
   
    for(int j=0;j<999;j++)
    // while(fabs(m-m_prev)>0.0)
    {
    e[0]=y1-m*x1-c;
    e[1]=y2-m*x2-c;
    e[2]=y3-m*x3-c;
    e1[0]=y1-mt*x1-c;
    e1[1]=y2-mt*x2-c;
    e1[2]=y3-mt*x3-c;
    e2[0]=y1-m*x1-ct;
    e2[1]=y2-m*x2-ct;
    e2[2]=y3-m*x3-ct;
    for(int i=0;i<3;i++)
    {
        sum=sum+(e[i]*e[i]);   
        sum_prev=sum_prev+(e1[i]*e1[i]);
        sum_prev2=sum_prev2+(e2[i]*e2[i]);
    }
    printf("sum = %f  m = %f  c = %f  m_prev = %f   sum_prev = %f  sum-sumprev = %f\n",sum,m,c,m_prev,sum_prev,sum-sum_prev);   
    
    if(!(j%20))
    w^=1;

    if(w){
    m=m+(sum-sum_prev)*0.85;
    mt=m+h;}
    else{
    c=c+(sum-sum_prev2)*0.4;
    ct=c+(h*100);
    }
    m_prev=m1;

    sum_prev=0;
    sum=0;
    sum_prev2=0;
    
    }
  
    //printf("%f  %f\n",fabs(m_prev-m),m);
    return 0;
}