#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=(struct Node*)malloc(sizeof(struct Node));
struct Node* dokya=head;

void printlist(struct Node* n)
{
    struct Node* m=n;
    printf(" %d ",n->data);
    n=n->next;
    while(n!=m)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
}

void rotate()
{
    head=head->next;
}

void insert(struct Node* n,int m)
{
    struct Node* t=n;
    if(n->data>m)
    {
    
    int f=n->data;
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    s->data=f;
    s->next = n->next;
    n->data=m;
    n->next=s;

    }

    else{
    while(n->next->data<m && n->next!=t)
    {
        n=n->next;
    }
    if(n->next==t)
    {
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    s->data=m;
    s->next=NULL;
    n->next=s;
    }
    else
    {
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    s->data=m;
    s->next=n->next;
    n->next=s;
    }
    }

}

int main()
{
    int a[6]={10,20,30,40,50,60};
    for(int i=0;i<6;i++)
    {
        head->data=a[i];

        if(i!=5)
        {
            head->next=(struct Node*)malloc(sizeof(struct Node));
            head=head->next;
        }
        else
        head->next=dokya;
        
    }
    head=dokya;

    printlist(head);

    printf("\n");

    insert(head,4);

    printlist(head);

    printf("\n");

    // rotate();
    // rotate();
    // rotate();
    // printlist(head);

    return 0;
}