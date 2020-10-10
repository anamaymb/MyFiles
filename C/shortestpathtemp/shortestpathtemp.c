#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int xs[100],ys[100],cnt=0;
int xray[100],yray[100],inc=0,prev_inc=inc,maxx,maxy,flagmax=0;
int mx,my;

float max=0;
int min=9999;
int maxima(int X,int Y,int p, int q)
{
    if(max<=sqrt((X-p)*(X-p)+(Y-q)*(Y-q)))
    {
        
    max=sqrt((X-p)*(X-p)+(Y-q)*(Y-q));maxx=p;maxy=q;flagmax=0;
    // printf("Hi %f %d %d \n",sqrt((X-p)*(X-p)+(Y-q)*(Y-q)),p,q);
    }
    else if(flagmax==0)
    {
        xray[inc]=maxx;yray[inc]=maxy;
        // printf("%d %d \n",maxx,maxy);
        inc++;//max=0;
        flagmax=1;
    }
    else{
        max=sqrt((X-p)*(X-p)+(Y-q)*(Y-q));
        // printf("Hello %f %d %d \n",sqrt((X-p)*(X-p)+(Y-q)*(Y-q)),p,q);
    }
}


int minima(int X,int Y,int p, int q)
{
    if(min>sqrt((X-p)*(X-p)+(Y-q)*(Y-q)))
    {
        
    min=sqrt((X-p)*(X-p)+(Y-q)*(Y-q));maxx=p;maxy=q;flagmax=0;mx=p;my=q;
    printf("Hi %f %d %d \n",sqrt((X-p)*(X-p)+(Y-q)*(Y-q)),p,q);
    }
    else if(flagmax==0)
    {
        xray[inc]=maxx;yray[inc]=maxy;
        // printf("%d %d \n",maxx,maxy);
        inc++;//max=0;
        flagmax=1;
    }
    else{
        min=sqrt((X-p)*(X-p)+(Y-q)*(Y-q));
        // printf("Hello %f %d %d \n",sqrt((X-p)*(X-p)+(Y-q)*(Y-q)),p,q);
    }
}





int main()
{
    int n=13;
                     //   0       1       2       3        4       5       6      7       8       9       10      11     12
    float graph[13][13]={{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //0
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //1
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //2
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //3
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //4
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //5
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //6
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //7
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //8
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //9
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //10
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, //11
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}};//12

    int flag[13][13]={{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, 
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}};

    int obstcl[13][13]={{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, 
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8, 8},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}};
                       
    int path[13][13]={{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, 
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}};

    
int x=12,y=7,initx=x,inity=y;
int X=1,Y=3;
int count=0;
int bmanx=x,bmany=y;
graph[x][y]=1;
flag[x][y]=1;
path[x][y]=1;

// while(x!=X || y!=Y)
while(count<45)
{
    int minx,miny;
    float gmax=9999;
    // maxima(X,Y,x,y);
    // minima(bmanx,bmany,x,y);
    if(prev_inc!=inc)
    {
        bmanx=mx;bmany=my;prev_inc=inc;//min=9999;
        printf("bmanx bmany %d %d\n",mx,my);
        // printf("Bmanx %d  Bmany %d ",bmanx,bmany);
    }

if(0/*flag[x][y]==1 && count!=0*/)
{
    printf("Anamay");
    x=bmanx;y=bmany;
    flag[x][y]=0;
}
else{

float surr[6],surrtemp=9999;
int surrx[6],surry[6],surrxtemp,surrytemp;


    int surrounded=0,surrc=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(x+1-i>=0 && y+1-j>=0 && x+1-i<=12 && y+1-j<=12)
            {
                if((x+1-i)!=x || (y+1-j)!=y)
                {

                    // if(flag[x+1-i][y+1-j]!=1 )
                    if(obstcl[x+1-i][y+1-j]==0 /*&& (flag[x+1-i][y+1-j]!=1 )*/ )
                    {
                        graph[x+1-i][y+1-j]=sqrt((X-(x+1-i))*(X-(x+1-i))+(Y-(y+1-j))*(Y-(y+1-j))) + sqrt((x-(x+1-i))*(x-(x+1-i))+(y-(y+1-j))*(y-(y+1-j)));
                        // printf("%d %d %f \n",x+1-i,y+1-j,graph[x+1-i][y+1-j]);
                        surr[surrc]=sqrt((x-(x+1-i))*(x-(x+1-i))+(y-(y+1-j))*(y-(y+1-j)));
                        surrx[surrc]=x+1-i;surry[surrc]=y+1-j;
                        surrc++;

                        if(gmax>graph[x+1-i][y+1-j] && flag[x+1-i][y+1-j]==0)
                        {
                            gmax=graph[x+1-i][y+1-j];minx=x+1-i;miny=y+1-j;surrounded=1;
                        }
                        
                        
                    }
                }
            }
        }            
    }
    if(surrounded==0)
    {
        flag[x][y]=1;
        // printf("Hey");
        for(int m=0;m<surrc;m++)
        {
            if(surrtemp>surr[m])
            {
                surrtemp=surr[m];surrxtemp=surrx[m];surrytemp=surry[m];
            }
        }
        x=surrxtemp;y=surrytemp;
        printf("surrxtemp       %d %d \n",surrxtemp,surrytemp);
    }
else{
    flag[x][y]=1;
    x=minx; 
    y=miny;
    path[x][y]=1;
}
// maxima(X,Y,x,y);

}
    // if(x==minx && y==miny)
    // {
    //     break;
    // }
    
    
    // store(x,y);
    printf("%d     %d\n",x,y);
    count++;
    // break;
}


for(int i=0;i<13;i++)
{
    for(int j=0;j<13;j++)
        printf("%d ",path[i][j]+obstcl[i][j]);
    printf("\n");
}

for(int i=0;i<inc;i++)
{
    printf("%d %d\n",xray[i],yray[i]);
    
}
// printf("\n");printf("\n");
// for(int i=0;i<13;i++)
// {
//     for(int j=0;j<13;j++)
//         printf("%d ",flag[i][j]);
//     printf("\n");
// }

// for(int i=0;i<cnt;i++)
// {
//     printf("%d %d\n",xs[i],ys[i]);
//     // printf("\n");
// }

return 0;
}
