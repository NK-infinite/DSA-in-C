#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;

void linkprint(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("nuber is:%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("the queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
    // printf("the enqueue element is:%d\n", val);
}
int dequeue()
{
    int val = -1;
    struct node *ptr = f;

    if (f == NULL)
    {
        printf("the queue is empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
    // printf("the enqueue element is:%d\n", val);
}

int main()
{

    enqueue(16);
    enqueue(04);
    enqueue(2006);
    linkprint(f);
    printf("the dequeue element is:%d\n", dequeue());
    return 0;
}