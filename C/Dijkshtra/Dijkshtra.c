#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n=5;
    // int graph[5][5]={{0 , 34 , 0 , 0 , 78},
    //                 {0 , 0 , 11 , 41 , 3},
    //                 {0 , 0 , 0 , 57 , 0},
    //                 {0 , 0 , 0 , 0 , 144},
    //                 {0 , 0 , 0 , 0 , 0}};

    int graph[5][5]={{0 , 30 , 10 , 0 , 0},
                     {0 , 0 , 9 , 50 , 10},
                     {0 , 0 , 0 , 20 , 0},
                     {0 , 0 , 0 , 0 , 70},
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


    int src,flag[5]={0,0,0,0,0},dist[5]={10000,10000,10000,10000,10000},count=0,path[5][5];
    printf("Enter the start point : ");
    scanf("\n%d",&src);
    flag[src]=1;dist[src]=0;
    
    for(int i=0;i<5;i++)
    {
    path[i][0]=src;
    }
    int cnt[5]={1,1,1,1,1};



    while(count<(n+1))
    {
    for(int i=0;i<n;i++)
    {
        if(flag[i]!=1 && graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)]!=0)
        {
            if(dist[i]>dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)])
            {
                dist[i]=dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)];
                
                if(path[i][cnt[i]-1]!=src)
                {
                if(cnt[src]>=2)
                {
                for(int k=1;k<cnt[src];k++){
                path[i][cnt[i]]=path[src][k];
                cnt[i]++;
                }
                }
                
                path[i][cnt[i]]=src;
                cnt[i]++;
                }

                
                // path[i][cnt[i]]=src;
                // cnt[i]++;
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
    // printf("%d ",src);
    }
    printf("\nThe distance of node from : \n Node 0 is %d\n Node 1 is %d\n Node 2 is %d\n Node 3 is %d\n Node 4 is %d\n",dist[0],dist[1],dist[2],dist[3],dist[4]);

    for(int i=0;i<n;i++)
    {
        path[i][cnt[i]]=i;
        cnt[i]++;
    }

    for(int j=0;j<5;j++)
    {    
    int i=0;
    printf("The path for %d is : ",j);
    while(i<cnt[j])
    {
    
    printf("%d ",path[j][i]);
    i++;
    }
    printf("\n");
    
    }
    
return 0;
}
