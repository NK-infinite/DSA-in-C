#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{

    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
};

int main()
{
    /*
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 8;
    p->left = NULL;
    p->right = NULL;

    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 8;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 8;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;
*/
    struct node *p=createnode(16);
    struct node *p1=createnode(04); 
    struct node *p2=createnode(2006); 
    struct node *p3=createnode(2006); 
    struct node *p4=createnode(2006); 
   
   
    p->left = p1;
    p->right = p2;
    p1->left =p3;
    p1->right= p4;
    
    return 0;
}