#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n=13;
    // int graph[5][5]={{0 , 34 , 0 , 0 , 78},
    //                 {0 , 0 , 11 , 41 , 3},
    //                 {0 , 0 , 0 , 57 , 0},
    //                 {0 , 0 , 0 , 0 , 144},
    //                 {0 , 0 , 0 , 0 , 0}};

    // int graph[5][5]={{0 , 30 , 10 , 0 , 0},
    //                  {0 , 0 , 9 , 50 , 10},
    //                  {0 , 0 , 0 , 20 , 0},
    //                  {0 , 0 , 0 , 0 , 70},
    //                  {0 , 0 , 0 , 0 , 0}};

                     // 0   1   2   3   4   5   6   7   8   9   10  11 12
    int graph[13][13]={{0 , 7 , 2 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}, 
                       {0 , 0 , 3 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 4 , 0 , 1 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 5 , 0 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 , 0 , 0 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 2},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 , 4, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4, 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 5},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0}};

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




    int src,flag[n],dist[n],count=0,path[n][n];
    
    for(int i=0;i<13;i++)
    {
        flag[i]=0;
        dist[i]=10000;
    }
    printf("Enter the start point : ");
    scanf("\n%d",&src);
    flag[src]=1;dist[src]=0;
    int cnt[n];
    for(int i=0;i<n;i++)
    {
    path[i][0]=src;
    cnt[i]=1;
    }
    // int cnt[5]={1,1,1,1,1};



    while(count<(n+1))
    {
    for(int i=0;i<n;i++)
    {
        if(flag[i]!=1 && graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)]!=0)
        {
            if(dist[i]>dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)])
            {
                int temp=dist[i];
                dist[i]=dist[src]+graph[src*(src<=i)+i*(src>i)][i*(src<=i)+src*(src>i)];
                
                if(temp!=10000)
                cnt[i]=1;
                
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
    printf("\nThe distance of node from : \n");

    for(int i=0;i<n;i++)
    {
    printf("Node %d is %d \n",i,dist[i]);
    }
    for(int i=0;i<n;i++)
    {
        path[i][cnt[i]]=i;
        cnt[i]++;
    }

    for(int j=0;j<n;j++)
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
