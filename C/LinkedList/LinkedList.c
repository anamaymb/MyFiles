#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
void printList(struct Node* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
}

void delnode(struct Node* n,int m)
{
    int i=1;
    struct Node* s;
    while(i!=(m-1))
    {
        n=n->next;
        i++;
    }
    s=n;
    s=s->next;
    s=s->next;
    n->next=s;

}
void insert(struct Node* n,int m,int d)
{
    int i=1;
    struct Node* s=(struct Node*)malloc(sizeof(struct Node));
    while(i!=(m-1))
    {
        n=n->next;
        i++;
    }
    s->next=n->next;
    n->next=s;
    s->data=d;

}

int get(struct Node* n, int m)
{
    int i=1;
    while (i!=m){
    n=n->next;i++;}
    return n->data;
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


int getfromend(struct Node* n, int m)
{
    int i=1;m=length(n)+1-m;
    while (i!=m){
    n=n->next;i++;}
    return n->data;
}


int main() 
{ 
    
    int a[5]={11,23,75,99,23};

    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); 
      
    struct Node* dokya = head;
    head->data = 10;
    head->next=(struct Node*)malloc(sizeof(struct Node));

    for(int i=0;i<5;i++)
    {

        head=head->next;
        head->data = a[i];
        head->next=(struct Node*)malloc(sizeof(struct Node));
        if(i==4)
        head->next=NULL;
    }

    delnode(dokya,2);

    insert(dokya,4,100);

    printList(dokya); 
  
    printf("\n The %dth element is %d. \n ",3,get(dokya,3));

    printf("The %dth element from end is %d. \n ",3,getfromend(dokya,3));
    
    printf("The length of the list is %d",length(dokya));
    return 0; 
}