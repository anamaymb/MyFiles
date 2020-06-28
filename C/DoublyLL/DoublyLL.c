#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
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

void printlistu(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->prev;
    }
}


void left()
{
    if(head->prev==NULL)
    printf("There's nothing LEFT..!!");
    else{
    head=head->prev;printf("%d",head->data);}
}

void right()
{
    if(head->next==NULL)
    printf("Thats not right..!!");
    else{
    head=head->next;printf("%d",head->data);}
}

int main()
{
    int a[6]={1,2,3,4,5,6};
    
    head->data=a[0];
    head->prev=NULL;

    for(int i=0;i<5;i++)
    {
        head->next=(struct Node*)malloc(sizeof(struct Node));
        
        struct Node* s=head;

        head=head->next;
        
        head->data=a[i+1];

        head->prev=s;
                
    }


    head->next=NULL;


    

    head=dokya;

    printlist(head);

    printf("\n");

    printf("You are at : %d \n", head->data);
    printf("Enter 'a' or 'd' for traverse ('e' to exit)\n");

    char c;
    while(1)
    {
        scanf("%c",&c);
        if(c=='a')
        {
            left();
        }
        else if(c=='d')
        {
            right();
        }
        else if(c=='e')
        {
            break;
        }
    }


    

    return 0;
}