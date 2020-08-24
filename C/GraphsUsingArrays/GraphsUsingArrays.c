#include <stdio.h>
#include <stdlib.h>
/*
struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=(struct Node*)malloc(sizeof(struct Node));
*/

int main()
{
/*
    head->data=2;
    head->next=NULL;
    printf("%d",head->data);
    return 0;*/


    // int graph[5][5]={{0 , 34 , 0 , 0 , 78},
    //                 {0 , 0 , 11 , 41 , 3},
    //                 {0 , 0 , 0 , 57 , 0},
    //                 {0 , 0 , 0 , 0 , 144},
    //                 {0 , 0 , 0 , 0 , 0}};

    int graph[5][5];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            graph[i][j]=0;
        }
    }
    
    while(1)
    {
        int m,n,weight;
        char ans='q';
        printf("From ...");
        scanf("%d",&m);
        printf("To ...");
        scanf("%d",&n);
        printf("Weight = ");
        scanf("%d",&weight);
        if(m>n)
        graph[n][m]=weight;
        else
        graph[m][n]=weight;
        printf("Want 2 continue? y/n : ");
        scanf("\n%c",&ans);
        if(ans=='n')
        break;
        else if(ans=='y')
        printf("\n");
    } 

    for(int i=0;i<5-1;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(graph[i][j]!=0)
            {
                printf("There is a link between %d and %d whose weight is %d.\n",i,j,graph[i][j]);
            }
        }

    }
    return 0;
}
