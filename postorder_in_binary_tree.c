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
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *p = createnode(10);
    struct node *p1 = createnode(8);
    struct node *p2 = createnode(13);
    struct node *p3 = createnode(6);
    struct node *p4 = createnode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    printf("\n");
    printf("postorder (left->right->root) => ");
    postorder(p);
    printf("\n\n");
    return 0;
}