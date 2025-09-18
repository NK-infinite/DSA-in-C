#include<stdio.h>

void display(int array[],int n)
{   //traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d,",array[i]);
    }
    printf("\n");
}

void deletion(int array[],int size ,int index)
{  // deletion

    
    for (int i = index; i <size-1; i++)
    {
        array[i]=array[i+1];
    }
     
     }
int main()
{
    int array[100]={16,7,04,2006};
    int size=4,element=7,index=1;
    display(array,size);
    deletion(array,size,index);
    size-=1;
    display(array,size);
}
