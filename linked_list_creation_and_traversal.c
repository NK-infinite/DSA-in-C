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
}
int main()
{
    int a, b, c;
    struct node *hade;
    struct node *second;
    struct node *last;
  
    printf("entar the number(a=hade,b=second,c=last)\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    hade = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    hade->data = a;
    hade->next = second;

    second->data = b;
    second->next = last;

    last->data = c;
    last->next = NULL;

    linkprint(hade);
    return 0;
}
