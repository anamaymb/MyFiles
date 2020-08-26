#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n=5;
    int graph[5][5]={{0 , 34 , 0 , 0 , 78},
                    {0 , 0 , 11 , 41 , 3},
                    {0 , 0 , 0 , 57 , 0},
                    {0 , 0 , 0 , 0 , 144},
                    {0 , 0 , 0 , 0 , 0}};

    /*
    int graph[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    
    while(1)
    {
        int m,N,weight;
        char ans='q';
        printf("From ...");
        scanf("%d",&m);
        printf("To ...");
        scanf("%d",&N);
        printf("Weight = ");
        scanf("%d",&weight);
        if(m>N)
        graph[N][m]=weight;
        else
        graph[m][N]=weight;
        printf("Want 2 continue? y/n : ");
        scanf("\n%c",&ans);
        if(ans=='n')
        break;
        else if(ans=='y')
        printf("\n");
    } 
    */
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(graph[i][j]!=0)
            {
                printf("There is a link between %d and %d whose weight is %d.\n",i,j,graph[i][j]);
            }
        }

    }


    int src,flag[5]={0,0,0,0,0},dist[5]={10000,10000,10000,10000,10000},count=0;
    printf("Enter the start point : ");
    scanf("\n%d",&src);
    flag[src]=1;dist[src]=0;


    while(count<(n+1))
    {
    for(int i=0;i<n;i++)
    {
        if(flag[i]!=1 && graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)]!=0)
        {
            if(dist[i]>dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)])
            {
                dist[i]=dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)];
            }
        }
        
    }
    int min=9999;
    for (int j=0;j<n;j++)
    {

        if(!flag[j])
        {
            if(dist[j]<min)
            {
                min=dist[j];
                src=j;
            }
        }
    }
    flag[src]=1;
    count++;
    }
    printf("%d %d %d %d %d ",dist[0],dist[1],dist[2],dist[3],dist[4]);

    return 0;
}
