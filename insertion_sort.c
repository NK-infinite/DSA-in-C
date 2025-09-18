#include <stdio.h>
#include <stdlib.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
  
    }
}

int main()
{
    int arr[] = {1, 125, 34, 25, 67, 35, 89, 56, 12, 54};
    int n = 10;
    printf("the befor sorting:-");
    printarr(arr, n);
    insertionsort(arr, n);
    printf("\nthe aftar sorting:-");
    printarr(arr, n);
}