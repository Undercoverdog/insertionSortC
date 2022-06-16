#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int checkArray(int *pArray, int pLength)
{

    for (int i = 0; i < pLength; i++)
    {
        if (*(pArray + i) > *(pArray + i + 1))
        {
            return 0;
        }
    }

    return 1;
}

int selSort(int *pArray, int pLength)
{
    if (checkArray(pArray, pLength) == 1)
    {
        printf("Already sorted! \n");
        return 0;
    }
    for (int i = 1; i < pLength; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (*(pArray + i) < *(pArray + j))
            {
                swap(pArray + i, pArray + j);
            }
        }
    }
}

int fill(int *pArray, int pLength, int pMin, int pMax)
{
    srand(time(NULL));
    for (int i = 0; i < pLength; i++)
    {

        *(pArray + i) = rand() % ((pMax + 1) - pMin) + pMin;
    }
    return 0;
}

// prints first and last 3 fields of array
int printArr(int *pArray, int pLength)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(pArray + i));
    }
    printf(" ... ");
    for (int j = pLength - 3; j < pLength; j++)
    {
        printf("%d ", *(pArray + j));
    }
    printf("\n\n");
}
int main()
{
    srand(time(NULL));
    int nMax = 10000;
    int nMin = 1;
    int thisLength = rand() % ((nMax + 1) - nMin) + nMin;
    int arr[thisLength];
    fill(arr, thisLength, -100000000, 100000000);

    // after generating and filling random array arr[]
    int length = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, length);

    selSort(arr, length);

    printArr(arr, length);

    printf("\n");
    return 0;
}