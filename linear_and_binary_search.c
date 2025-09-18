#include <stdio.h>

int linear(int array[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return 0;
        }
    }
    return -1;
}

int binary(int array[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        if (array[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(int);
    int element, lan;
    // printf("entar the element\n");
    // scanf("%d", &element);
    int serachindex1 = linear(array, size, element);
    //  printf("the element %d was found at index %d", element, serachindex1);
    int serachindex2 = binary(array, size, element);
    // printf("the element %d was found at index %d\n", element, serachindex2);

    printf("chois the searching type\n");
    scanf("%d", &lan);
    switch (lan)
    {
    case 1:
        printf("entar the element\n");
        scanf("%d", &element);
        serachindex1 = linear(array, size, element);
        printf("the element %d was found at index %d", element, serachindex1);
        break;
    case 2:
        printf("entar the element2\n");
        scanf("%d", &element);
        serachindex2 = binary(array, size, element);
        printf("the element %d was found at index %d", element, serachindex2);
        break;
    default:
        printf("No,this searching type not avlibal");
        break;
    }
}
