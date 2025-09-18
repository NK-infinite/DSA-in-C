Insertion Insertion #include <stdio.h>
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

struct node* searchingiter(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        root=root->left;
    }
    else
    {
        root= root->right;
    }
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

    struct node *n = searchingiter(p,16);
    if (n != NULL)
    {
        printf(" \n ~~%d~~ \n  ", n->data);
    }
    else
    {
        printf("the element is not found");
    }
}