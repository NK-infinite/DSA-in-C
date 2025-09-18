#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int Full(struct stack *ptr)
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

int empty(struct stack *ptr)
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

void puse(struct stack *ptr, int val)
{
    if (Full(ptr))
    {
        printf("\nstack is overflow do not puse the %d\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("\nstack is overflow do not puse the \n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek (struct stack* sp ,int i)
{
    int arryind = sp->top-i-1;
    if (arryind < 0)
    {
        printf("not valid");
    }
    else
    {
        return sp->arr[arryind];
    }

}
int top (struct stack *sp)
{
  return sp->arr[sp->top];
}

int bottom(struct stack *sp)
{
    return sp->arr[0];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("~you make a steck is succefully!\n");
    printf("%d\n", Full(sp));
    printf("%d\n", empty(sp));
    puse(sp, 4);
    puse(sp, 5);
    puse(sp, 6);
    puse(sp, 7);
    puse(sp, 8);
    printf("%d\n", Full(sp));
    printf("%d\n", empty(sp));

    printf("poped the number is:%d\n", pop(sp));

    for (int j = 0; j < sp->top+1 ; j++)
    {
        printf("the index number is %d and peek number is %d\n",j,peek(sp,j));
    }
             
    printf("the stacktop is:%d and stackbottom is:%d",top(sp),bottom(sp));
}