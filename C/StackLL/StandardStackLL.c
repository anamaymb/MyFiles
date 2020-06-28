#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head=NULL;
int available=0;


void printlist(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
}

void preappend(int a)
{
    struct Node* s=(struct Node*)malloc(sizeof(struct Node));
    s->next=head;
    s->data=a;
    head=s;
}

void push(int a)
{
    available++;
    struct Node* s=head;
    if(head==NULL)
    {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data=a;
        head->next=NULL;
    }
    else
    {
        preappend(a);
    }
}

int pop()
{
    if(available==0)
    {
        printf("Nothing left in the stack");return 0; 
    }
    int a=head->data;
    head=head->next;
    available--;
    return a;
}

int main()
{
char c;
int f;
while(1)
{
    
    printf("\nPush Or Pop?? (u/o) ");
    scanf("\n%c",&c);
    
    if(c=='u')
    {
        printf("What to Push? ");
        scanf("%d",&f);
        push(f);
        printlist(head);
        c='u';
    }
    else if(c=='o')
    {
        printf("%d",pop());
    }
    else if(c=='e')
    {
        printf("Quitting ...");
        printlist(head);
        break;
    }
    else
    {
        printf(" Invalid ..!!");
    }
    
}

    return 0;
}