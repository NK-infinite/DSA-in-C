#include <stdio.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionsort(int *arr, int n)
{
    int minindex, temp;
    printf("the runing arr.....\n");
    for (int i = 0; i < n - 1; i++)
    {
        minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int main()
{
    int arr[] = {3, 45, 4, 7, 87, 24, 8, 65, 46, 55};
    int n = 10;

    printarr(arr, n);
    selectionsort(arr, n);
    printarr(arr, n);
    return 0;
}