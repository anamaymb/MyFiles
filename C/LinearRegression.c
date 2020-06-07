#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<Simplecpp>
int main()
{
    float x1=1.0,y1=2.0,x2=2.0,y2=4.0,x3=3.0,y3=6.0,h=0.001;
    float m=1.0,mt=1.001,m_prev=0.97,c=0.0,sum=0.0,sum_prev=0.0,m1=0.0;
    float e[3]={y1-m_prev*x1-c,y2-m_prev*x2-c,y3-m_prev*x3-c},e1[3]={y1-mt*x1-c,y2-mt*x2-c,y3-mt*x3-c};
   
    for(int j=0;j<599;j++)
    // while(fabs(m-m_prev)>0.0)
    {
    e[0]=y1-m*x1-c;
    e[1]=y2-m*x2-c;
    e[2]=y3-m*x3-c;
    e1[0]=y1-mt*x1-c;
    e1[1]=y2-mt*x2-c;
    e1[2]=y3-mt*x3-c;
    for(int i=0;i<3;i++)
    {
        sum=sum+(e[i]*e[i]);   
        sum_prev=sum_prev+(e1[i]*e1[i]);
    }
    printf("sum = %f  m = %f  c = %f  m_prev = %f   sum_prev = %f  sum-sumprev = %f\n",sum,m,c,m_prev,sum_prev,sum-sum_prev);   
    

    m=m+(sum-sum_prev)*0.25;

    // if(sum<sum_prev){
    //     m1=m;
    // m=m+((-sum+sum_prev)*(m>m_prev)+(sum-sum_prev)*(m<m_prev))*0.07;//c=c+sum*(0.01);
    // }
    // if(sum>sum_prev){
    //     m1=m;
    // m=m-((sum-sum_prev)*(m>m_prev)+(-sum+sum_prev)*(m<m_prev))*0.04;//c=c-sum*(0.01);

    // if(sum<sum_prev){
    //     m1=m;
    // m=m+((sum/*+sum_prev*/)*(m>m_prev)+(-sum/*-sum_prev*/)*(m<m_prev))*0.09;//c=c+sum*(0.01);
    // }
    // if(sum>sum_prev){
    //     m1=m;
    // m=m-((sum/*-sum_prev*/)*(m>m_prev)+(-sum/*+sum_prev*/)*(m<m_prev))*0.06;//c=c-sum*(0.01);
 
    // }
    mt=m+h;

    
    m_prev=m1;
    // printf("Hi");

    sum_prev=0;
    sum=0;
    
    }
  
    printf("%f  %f\n",fabs(m_prev-m),m);
    return 0;
}