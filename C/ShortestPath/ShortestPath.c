#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m=13,n=13;
    float graph[m][n];
    int flag[m][n], path[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
            path[i][j]=0;
            flag[i][j]=0;
        }
    }

    
int x=12,y=12;
int X=2,Y=0;

graph[x][y]=1; flag[x][y]=1; path[x][y]=1;

while(x!=X || y!=Y)
{
    int minx,miny;
    float gmax=9999;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(x+1-i>=0 && y+1-j>=0 && x+1-i<=12 && y+1-j<=12)
            {
                if(flag[x+1-i][y+1-j]!=1)
                {
                    graph[x+1-i][y+1-j]=sqrt((X-(x+1-i))*(X-(x+1-i))+(Y-(y+1-j))*(Y-(y+1-j)));
                    if(gmax>graph[x+1-i][y+1-j])
                    {
                        gmax=graph[x+1-i][y+1-j];minx=x+1-i;miny=y+1-j;
                    }
                    flag[x+1-i][y+1-j]=1;
                }
            }
        }            
    }
    x=minx; y=miny;
    path[x][y]=1;
    printf("%d %d\n",x,y);

}


for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
        printf("%d ",path[i][j]);
    printf("\n");
}

return 0;
}
