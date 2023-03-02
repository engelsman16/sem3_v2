#include "challenge.h"

#include "sort.h"

#include <stdio.h>
#include <stdbool.h>

int GetDifference(int *array, int size, int k, int *difference)
{
    if (array == NULL || size <= 1 || size < k || k < 1 || difference == NULL)
    {
        return -1;
    }
    int min = 0;
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        min += array[i];
        max += array[size - 1 - i];
    }

    *difference = max - min;
    return 0;
}

int FindSmallestNumberThatIsRepeatedKTimes(
    int *array, int size, int k, int *smallestNumber)
{
    if (array == NULL || size <= 0 || k <= 0 || k > size || smallestNumber == NULL)
    {
        return -1;
    }

    int count = 0;
    int smallest = INT32_MAX;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        if (count == k && array[i] < smallest)
        {
            smallest = array[i];
            found = true;
        }
    }
    if (found)
    {
        *smallestNumber = smallest;
        return 0;
    }
    return -1;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_BubbleSort(
    int *array, int size, int k, int *difference)
{
    if (array == NULL || size <= 1 || size < k || k < 1 || difference == NULL)
    {
        return -1;
    }

    BubbleSort(array, size);
    GetDifference(array, size, k, difference);
    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_MergeSort(
    int *array, int size, int k, int *difference)
{
    if (array == NULL || size <= 1 || size < k || k < 1 || difference == NULL)
    {
        return -1;
    }

    MergeSort(array, 0, size - 1);
    GetDifference(array, size, k, difference);
    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_SelectionSort(
    int *array, int size, int k, int *difference)
{
    if (array == NULL || size <= 1 || size < k || k < 1 || difference == NULL)
    {
        return -1;
    }

    SelectionSort(array, size);
    GetDifference(array, size, k, difference);
    return 0;
}