#include<stdio.h>
#include<stdlib.h>

int main()
{

    float hours[12]={120,150,180,210,240,270,300,330,0,30,60,90};

    int  hr=8;
    float mint=43,sec=38;
    float mang;

    if(mint>=45 && mint<60)
    mang=(mint-45)*6;
    else if(mint==0.0)
    mang=90;
    else
    mang=mint*6 + 90;

    mang=mang+(0.1*sec);

    float f=hours[hr-1]+(mint/2)+(sec*0.00833);
    float diff=mang-f;
    if(diff<0)
    diff=-diff;
    if(diff>180.0)
    diff=360.0-diff;
    printf("%f\n",diff);
    return 0;
}