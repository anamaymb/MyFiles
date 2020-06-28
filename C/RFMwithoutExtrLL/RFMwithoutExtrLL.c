#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=(struct Node*)malloc(sizeof(struct Node));
struct Node* dokya=head;

void printlist(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
}


int length(struct Node* n)
{
    int m=0;
    
    while(n!=NULL)
    {
        n=n->next;
        m++;
    }
    
    return m;
}

void reverseMid(struct Node* n, int m)
{

    int y=0;
    while(y!=m-1)
    {
        head=head->next;
        y++;
    }
    struct Node* w=head;
    int len=length(head);
    int latt=len;
    int temp ;
    for(int j=0;j<len-1;j++)
    {
    for(int i=0;i<latt-1;i++)
    {
    temp = head->data;
    head->data=head->next->data;
    head=head->next;
    head->data=temp;
    }
    head=w;
    latt--;
    }
    head=dokya;
}



int main()
{

    int a[6]={234,907,635,192,1,872};
    for(int i=0;i<6;i++)
    {
        head->data=a[i];

        if(i!=5)
        {
            head->next=(struct Node*)malloc(sizeof(struct Node));
            head=head->next;
        }
        else
        head->next=NULL;
        
    }
    
    head=dokya;

    printf("\nOriginal                              : ");
    printlist(head);
    reverseMid(head,3);
    printf("\n");
    printf("Reversed from somewhere in the middle : ");
    printlist(head);
    printf("\n\n");



    return 0;
}