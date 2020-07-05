#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int date=11 , mnt=2 , yr=2018;         //From
    char day[10]="Sunday";
    
    int thd=895;                           //th Day

    int count=0,warn,dec;


    char dday[7][10]={"Sunday","Monday","Teusday","Wednusday","Thursday","Friday","Saturday"};
    
    for(int j=0;j<7;j++)
    {
        for(int i=0;i<strlen(day);i++)
        {
            if(day[i]==dday[j][i])
                count++;
        }
        if(strlen(day)==count)
        {
            warn=j;break;
        }
        count=0;
    }

    dec=warn+thd%7;
    if(dec>=7)
        dec=dec-7;

    for(int i=0;i<strlen(dday[dec]);i++)
        printf("%c",dday[dec][i]);

    printf("\n");

    int month[2][13]={{0,31,31+28,31+28+31,31+28+31+30,31+28+31+30+31,31+28+31+30+31+30,31+28+31+30+31+30+31,31+28+31+30+31+30+31+31,31+28+31+30+31+30+31+31+30,31+28+31+30+31+30+31+31+30+31,31+28+31+30+31+30+31+31+30+31+30,31+28+31+30+31+30+31+31+30+31+30+31},
                      {0,31,31+29,31+29+31,31+29+31+30,31+29+31+30+31,31+29+31+30+31+30,31+29+31+30+31+30+31,31+29+31+30+31+30+31+31,31+29+31+30+31+30+31+31+30,31+29+31+30+31+30+31+31+30+31,31+29+31+30+31+30+31+31+30+31+30,31+29+31+30+31+30+31+31+30+31+30+31}};
    int mm[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

    int flag= 1*(yr%4==0),nyr=yr,res=0;

res=date+month[flag][mnt-1];

thd=thd+res;

int temp= thd,dd,o=0;
while(1)
{

    if(temp-mm[flag][o]>0)
    {
        temp=temp-mm[flag][o];
        o++;
    }
    else
    {
        dd=temp;break;
    }
    if(o==12)
    {
        o=0;nyr++;flag= 1*(nyr%4==0);
    }

}
printf("%d / %d / %d",dd,o+1,nyr);
return 0;
}