#include <stdio.h>
#include <stdlib.h>

struct dequeue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct dequeue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct dequeue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueueR(struct dequeue *q, int val)
{
    if (isfull(q))
    {
        printf("the dequeue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("the enqueue element is:%d\n",val);
    }
}
void enqueueF(struct dequeue *q, int val)
{
    if (isfull(q))
    {
        printf("the dequeue is full");
    }
    else
    {
        q->arr[q->f] = val;
        q->f--;
        printf("the enqueue element is:%d\n", val);
    }
}

int dequeueR (struct dequeue *q)
{    int element;
    if (isempty(q))
    {
        printf("the queue is empty");
    }
    else
    {
        element=q->arr[q->r];
        q->r--;
        // printf("the delete element is %d",);
    }
    return element;
}

int dequeueF (struct dequeue *q)
{    int element;
    if (isempty(q))
    {
        printf("the queue is empty");
    }
    else
    {
        q->f++;
        element=q->arr[q->f];
        // printf("the delete element is %d",);
    }
    return element;
}

int main()
{
    struct dequeue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueR(&q, 15);
    enqueueR(&q, 16);
    enqueueF(&q, 10);
    enqueueF(&q, 12);

    printf("\n");

    printf("thr delete element is %d\n",dequeueR(&q));
    printf("thr delete element is %d\n",dequeueF(&q));
    
    
    return 0;
}