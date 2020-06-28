#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = (struct Node*)malloc(sizeof(struct Node));
struct Node* dokya=head;
struct Node* temp=NULL;


void printlist(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
}


void reverse(struct Node* n)
{

    while(n!=NULL)
    {
        if(temp==NULL)
        {
            temp=(struct Node*)malloc(sizeof(struct Node));
            temp->next=NULL;
        }
        else
        {
        struct Node* s=(struct Node*)malloc(sizeof(struct Node));
        s->next = temp;
        temp=s;
        }
        temp->data=n->data;
        n=n->next;

    }
    head=temp;
}


int main()
{

    int a[6]={1,2,3,4,5,6};
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


    printlist(head);
    reverse(head);


    printf("\n");
    printlist(head);




    return 0;
}