#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->r)
    {
        return 1;
    }
    return 0;
}

int isempty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue *q, int val)
{
    if (isfull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("enqueue element is:%d\n", val);
    }
}

int dequeue(struct circularqueue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularqueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 16);
    enqueue(&q, 04);
    enqueue(&q, 2006);

    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));
    
    printf("\n");
    
    enqueue(&q, 1984);
    enqueue(&q, 1975);
    enqueue(&q, 2006);

    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));

    // if (isempty(&q))
    // {
    //     printf("the queue is empty\n");
    // }
    // if (isfull(&q))
    // {
    //     printf("the queue is full");
    //}
    return 0;
}