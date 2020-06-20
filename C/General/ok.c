#include<stdio.h>

int main()
{
    float x[3]={ 0.5 , 2.3 , 2.9 }, y[3]={ 1.4 , 1.9 , 3.2 }, h=0.001;

    float m=1.0, mt=1.001, c=10.00, ct=10.001, sum=0.0, sum_m=0.0, sum_c=0.0;

    int w=0;

    float error[3], error_m[3], error_c[3];

    for(int j=0;j<999;j++)
    {
       for(int i=0;i<3;i++)
    {
        error[i] =y[i] - m * x[i] - c;
        error_m[i] =y[i] - mt * x[i] - c;
        error_c[i] =y[i ]- m * x[i] - ct;    

        sum =sum + (error[i] * error[i]);   
        sum_m = sum_m + (error_m[i] * error_m[i]);
        sum_c = sum_c + (error_c[i] * error_c[i]);
    }

    printf("m = %f  c = %f\n",m,c);   
    
    if(!(j%20))                             
    w^=1;                                                   //Toggles every 20 iterations

    if(w)
    {
    m=m+(sum-sum_m)*0.85;                                   //correcting 'm' for 20 iterations
    mt=m+h;
    }

    else
    {
    c=c+(sum-sum_c)*0.4;                                    //correcting 'c' for next 20 iterations
    ct=c+(h*100);
    }

    sum_m=0;   sum=0;   sum_c=0;
    }

    return 0;
}