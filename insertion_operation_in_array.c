#include<stdio.h>

void display(int array[],int n)
{   //traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d,",array[i]);
    }
    printf("\n");
}

int insertion(int array[],int size ,int element,int capacity,int index)
{  // insertion
    if (size>=capacity)
    {
        return -1;
    }
    
    for (int i = size-1; i >= index; i--)
    {
        array[i+1]=array[i];
    }
     array[index]=element;
}
int main()
{
    int array[100]={16,04,200,06};
    int size=4,element=7,index=3;
    display(array,size);
    insertion(array,size,element,100,index);
    size+=1;
    display(array,size);
}
