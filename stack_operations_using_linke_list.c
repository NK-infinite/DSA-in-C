#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkprint(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("the nuber is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int emply(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(struct node **top)
{
    if (emply(*top))
    {
        printf("the stack is overflow\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

struct node *push(struct node *top, int x)
{
    if (full(top))
    {
        printf("the stack is overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int main()
{
    struct node *top = NULL;
    top = push(top, 2006);
    top = push(top, 4);
    top = push(top, 16);
    linkprint(top);
    int number = pop(&top);
    printf("the pop number is:%d\n", number);
    return 0;
}