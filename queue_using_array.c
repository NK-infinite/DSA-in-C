#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}


void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
         printf("enqueue element is:%d\n",val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 300;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 16);
    enqueue(&q, 04);
    enqueue(&q, 2006);

    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));
    printf("the deletion element is:%d\n", dequeue(&q));
   
    enqueue(&q, 4);
    enqueue(&q, 88);
    enqueue(&q, 45);
 
    // if (isempty(&q))
    // {
    //     printf("the queue is empty\n");
    // }
    // if (isfull(&q))
    // {
    //     printf("the queue is full");
    // }
    // return 0;
}