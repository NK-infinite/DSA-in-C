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

struct node *deletionfirst(struct node *hade)
{
    struct node *p = hade;
    hade = p->next;
    free(p);
    return hade;
}
struct node *deletionmid(struct node *hade, int index)
{
    struct node *p = hade;
    struct node *q = hade->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return hade;
}

struct node *deletionend(struct node *hade)
{
    struct node *p = hade;
    struct node *q = hade->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return hade;
}

struct node *deletionvalue(struct node *hade, int value)
{
    struct node *p = hade;
    struct node *q = hade->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return hade;
}

int main()
{
    struct node *hade;
    struct node *second;
    struct node *third;
    struct node *last;

    hade = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    hade->data = 10;
    hade->next = second;

    second->data = 4;
    second->next = third;

    third->data = 12;
    third->next = last;

    last->data = 14;
    last->next = NULL;

    printf("-print linkd\n");
    linkprint(hade);
    // printf("case 1:first link deletion\n");
    // hade = deletionfirst(hade);
    // linkprint(hade);

     printf("case 2:deletion betwen link list");
     hade = deletionmid(hade, 2);
     linkprint(hade);

    // printf("case 3:deletion at the end\n");
    // hade = deletionend(hade);
    // linkprint(hade);

}