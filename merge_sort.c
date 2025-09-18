#include <stdio.h>

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++, k++;
        }
        else
        {
            b[k] = arr[j];
            j++, k++;
        }
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++, k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i]=b[i];
    }
    
}

void mergesort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}
int main()
{
    int arr[] = {3, 45, 4, 7, 87, 24, 8, 65, 46, 55};
    int n = 10;

    printarr(arr, n);
    mergesort(arr, 0, 9);
    printarr(arr, n);
    return 0;
}