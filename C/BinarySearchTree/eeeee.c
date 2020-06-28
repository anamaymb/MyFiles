#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* head=(struct Node*)malloc(sizeof(struct Node));
struct Node* dokya=head;

int main()
{
    int a[5]={7,16,8,18,13};

    head->data=11;
    head->left=NULL;
    head->right=NULL;
    for(int i=0;i<5;i++)
    {

        head=dokya;

        while(head->left!=NULL && head->right!=NULL)
        {
        if(head->data>a[i])
        head=head->left;

        else if(head->data<a[i])
        head=head->right;
            
        }

        if(head->data>a[i])
        {
            head->left=(struct Node*)malloc(sizeof(struct Node));
            head=head->left;head->data=a[i];head->left=NULL;head->right=NULL;
        }
        if(head->data<a[i])
        {
            head->right=(struct Node*)malloc(sizeof(struct Node));
            head=head->right;head->data=a[i];head->right=NULL;head->left=NULL;
        }


    }

    head=dokya;
    
    printf("%d\n",head->left->right->data);
    printf("%d\n",head->left->data);
    printf("%d\n",head->right->data);
    printf("%d\n",head->right->left->data);
    printf("%d\n",head->right->right->data);

    return 0;
}