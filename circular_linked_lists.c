#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkprint(struct node *hade)
{
    struct node *ptr = hade;
    do
    {
        printf("nuber is:%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != hade);
}

struct node *insertonfirst(struct node *hade, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = hade->next;
    while (p->next != hade)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = hade;
    hade = ptr;
    return ptr;
}

struct node *insertonmid(struct node *hade, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = hade;
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    p->next=ptr;
    ptr->next = hade;
    hade=ptr;
}
int main()
{
    int a;
    int b;
    int c;
    struct node *hade;
    struct node *second;
    struct node *third;
    struct node *last;

    hade = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    hade->data = 1;
    hade->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = last;

    last->data = 4;
    last->next = hade;

    linkprint(hade);
    printf("\n");
    hade = insertonfirst(hade, 7);
    linkprint(hade);
    printf("\n");
    hade = insertonmid(hade, 15, 5);
    linkprint(hade);
    return 0;
}