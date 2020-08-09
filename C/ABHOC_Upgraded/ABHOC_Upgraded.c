#include<stdio.h>
#include<stdlib.h>

int main()
{

    float hours[12]={120,150,180,210,240,270,300,330,0,30,60,90};

    int  hr=11;
    float mint=55,sec=48;
    float mang;
    int angle=0;
    float diff;

    for(int i=0;i<10;i++)
    {

    do
    {
    if(mint>=45 && mint<60)
    mang=(mint-45)*6;
    else if(mint==0.0)
    mang=90;
    else
    mang=mint*6 + 90;

    mang=mang+(0.1*sec);

    float f=hours[hr-1]+(mint/2)+(sec*0.00833);
    diff=mang-f;

    if(diff<0)
    diff=-diff;
    if(diff>180.0)
    diff=360.0-diff;

    if(sec<59)
    sec++;
    else
    {
        
        sec=0;
        if(mint<59)
        mint=mint+1;
        else
        {
            mint=0;
            if(hr<12)
            hr++;
            else
            hr=1;
        }
    }
    }
    while(diff<(angle-0.1) || diff>(angle+0.1));

    printf("%f\n",diff);
    printf("Hour: %d, Min: %f, sec: %f \n",hr,mint,sec-1*(sec!=0));

    sec=sec+3;

    }

    return 0;
}