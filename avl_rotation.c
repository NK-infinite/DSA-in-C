#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int gethight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct node *creatnode(int data)
{
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getbalancefacto(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return gethight(n->left) - gethight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(gethight(y->right), gethight(y->left));
    x->height = max(gethight(x->right), gethight(x->left));

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(gethight(y->right), gethight(y->left));
    x->height = max(gethight(x->right), gethight(x->left));

    return y;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return (creatnode(data));
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    node->height = 1 + max(gethight(node->left), gethight(node->right));

    int bf = getbalancefacto(node);

    if (bf > 1 && data < node->left->data)
    {
       return rightrotate(node);
    }
    if (bf < -1 && data > node->right->data)
    {
       return leftrotate(node);
    }

    if (bf > 1 && data < node->left->data)
    {
        node->left = leftrotate(node);
       return rightrotate(node);
    }

    if (bf < -1 && data > node->right->data)
    {
        node->left = rightrotate(node);
       return leftrotate(node);
    }
    return node;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 3);

    preorder(root);
  
    return 0;
}
