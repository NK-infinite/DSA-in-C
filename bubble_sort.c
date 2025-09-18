#include<stdio.h>
#include<stdlib.h>

void printarr (int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubblesort(int *arr, int n)
{
    int temp;
    int issort = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("the pass number:%d\n", i);
        issort = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issort = 0;
            }
        }
        if (issort)
        {
            return 0;
        }
    }
}

int main()
{
    int arr[] = {1, 125, 34, 25, 67, 35, 89, 56, 12, 54};
    int n = 10;
    printf("the befor sorting:-");
    printarr(arr, n);
    bubblesort(arr, n);
    printf("the aftar sorting:-");
    printarr(arr, n);
    return 0;
}