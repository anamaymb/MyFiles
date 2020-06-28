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

void reverseMid(struct Node* n, int m)
{

    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* w=temp1;

    int y=0;
    while(y!=m-1)
    {

        if(y==0)
        {
        
        temp1->data=n->data;
        temp1->next=NULL;
        n=n->next;
        }
        else
        {
            temp1->next=(struct Node*)malloc(sizeof(struct Node));
            temp1=temp1->next;
            temp1->data=n->data;
            temp1->next=NULL;
            n=n->next;
        }
        y++;
    }

    int q=0;
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    while(n!=NULL)
    {
        
        if(q==0)
        {
            t->next=NULL;
        }
        else
        {
        struct Node* s = (struct Node*)malloc(sizeof(struct Node));
        s->next = t;
        t=s;
        }

        t->data=n->data;
        n=n->next;
        q++;
    }

    temp1->next=t;
    head=w;
}



int main()
{

    int a[6]={102,782,312,400,92,112};
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
    reverseMid(head,5);
    printf("\n");
    printf("Reversed from somewhere in the middle : ");
    printlist(head);
    printf("\n\n");



    return 0;
}