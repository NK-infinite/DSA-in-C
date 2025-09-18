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
        printf("nuber is:%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertonfirst(struct node *hade, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = hade;
    ptr->data = data;
    return ptr;
}

struct node *insertonend(struct node *hade, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = hade;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return hade;
}

struct node *insertonnode(struct node *hade, struct node *povnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = povnode->next;
    povnode->next = ptr;

    return hade;
}
struct node *insertonindex(struct node *hade, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = hade;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

int main()
{
    struct node *hade;
    struct node *second;
    struct node *last;
    struct node *last1;

    hade = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    hade->data = 16;
    hade->next = second;

    second->data = 4;
    second->next = last;

    last->data = 2006;
    last->next = NULL;

    printf("print linkd\n");
    linkprint(hade);
    printf("case 1 :insert of the beginnarg\n");
    hade = insertonfirst(hade, 7);
    linkprint(hade);
    printf("case 2 :insert in betwen\n");
    hade = insertonindex(hade, 7, 3);
    linkprint(hade);
    printf("case 3 :insert at the end\n");
    hade = insertonend(hade, 7);
    linkprint(hade);
    printf("case 4 :insert aftear node\n");
    hade = insertonnode(hade, second, 7);
    linkprint(hade);

    return 0;
}