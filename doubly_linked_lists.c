#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void linkprintnext(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" -nuber is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void linkprintprev(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" -nuber is:%d\n", ptr->data);
        ptr = ptr->prev;
    }
}

struct node *insertonend(struct node *n1, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = n1;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

int main()
{
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;

    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 1;
    n1->prev = NULL;
    n1->next = n2;

    n2->data = 2;
    n2->prev = n1;
    n2->next = n3;

    n3->data = 3;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 4;
    n4->prev = n3;
    n4->next = NULL;
    printf("->next link list\n");
    linkprintnext(n1);
    printf("->prev link list\n");
    linkprintprev(n4);
    printf("doubly link list add number\n");
    insertonend(n1,7);
    linkprintnext(n1);
    return 0;
}

































#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
 
    return 0;
}




































#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s ->arr = (int *)malloc(s->size *sizeof(int));

    s->arr[0] = 7;
    s->top++;

    if (isempty(s))
    {
        printf("the stack is empty");
    }
    else
    {
        printf("the stck is not empty");
    }
    return 0;
}