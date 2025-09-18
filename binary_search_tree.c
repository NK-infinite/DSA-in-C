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
    n ->data=data;
    n->left = NULL;
    n->right = NULL;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int isbst(struct node* root)
{
   static struct node * prev=NULL;

   if (root!=NULL)
   {
     return 0;
   }
   if (prev!=NULL && root->data <= prev->data)
   {
    return 0;
   }
    
    prev = root;
    return isbst(root->left);
}

int main()
{
    struct node *p = createnode(16);
    struct node *p1 = createnode(15);
    struct node *p2 = createnode(22);
    struct node *p3 = createnode(12);
    struct node *p4 = createnode(23);
    

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    printf("%d",isbst(p));
}