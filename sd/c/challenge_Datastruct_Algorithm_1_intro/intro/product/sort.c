#include "sort.h"

int BubbleSort(int *array, int size)
{
    if (array == NULL || size <= 1)
    {
        return -1;
    }

    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

int MergeArray(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    CopyRemainingElements(array, L, &k, &i, n1);

    CopyRemainingElements(array, R, &k, &j, n2);

    return 0;
}

int MergeSort(int *array, int left, int right)
{
    if (array == NULL || left < 0 || right < 0)
    {
        return -1;
    }
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);

        MergeArray(array, left, mid, right);
    }

    return 0;
}

int CopyRemainingElements(int *array, int *tempArray, int *k, int *index, int n)
{
    if (array == NULL || tempArray == NULL || k == NULL || index == NULL || n <= 0)
    {
        return -1;
    }
    while ((*index) < n)
    {
        array[*k] = tempArray[*index];
        (*k)++;
        (*index)++;
    }

    return 0;
}

int SelectionSort(int *array, int size)
{
    if (array == NULL || size <= 1)
    {
        return -1;
    }

    int minIndex = 0;
    int temp = 0;

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }

    return 0;
}