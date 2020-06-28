#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
int available=0;

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


int pop()
{
    if(!available)
    {
        printf("The Stack is empty..!!");return 0;
    }
    int m=1,n;
    struct Node* s=head;
    struct Node* t=head;

        while(m!=length(s))
        {
            head=head->next;
            m++;
        }
        m=1;
        n=head->data;
        head=t;

    if(head->next!=NULL)
    {

        while(m!=length(s)-1)
        {
            head=head->next;
            m++;
        }
        head->next=NULL;
        head=t;
    }

    available--;
    return n;
}



void brek()
{
    int m=1,n;
    struct Node* s=head;
    struct Node* t=head;

    printf(" %d ",length(head));
    
    head=head->next;
    printf(" %d ",length(head));
                
    head->next=NULL;
    head=t;
    printf(" %d ",length(head));  
              
}

void push (int p)
{
    available++;
    int m=1;
    struct Node* s=head;
    struct Node* t=head;
    

    if(head!=NULL)
    {
        t=head;
    while(m!=length(s))
    {
        head=head->next;m++;
    }

    head->next= (struct Node*)malloc(sizeof(struct Node));
    head=head->next;
    head->data=p;
    head->next=NULL;
    head=t;


    }
    else
    {
        head= (struct Node*)malloc(sizeof(struct Node));
        head->data=p;
        head->next=NULL;
    }
    

}
char c;
int main()
{

int q=0,f;


while(1)
{
    
    printf("\nPush ka Pop?? ");
    scanf("\n%c",&c);
    printf("You Entered %c \n",c);
    if(c=='u')
    {
        printf("kay push karu? ");
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
        printf("Nigh..");
    }
    
}

    return 0;
}