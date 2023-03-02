#include "input.h"

int GetSize(int *size)
{
    if (size == NULL)
    {
        return -1;
    }

    if (scanf("%i", size) != 1)
    {
        return -1;
    }

    return 1;
}
int GetArray(int *array, int size)
{
    if (array == NULL || size <= 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (scanf("%i", &array[i]) != 1)
        {
            return -1;
        }
    }

    return 1;
}
int GetRepeat(int *k)
{
    return GetSize(k);
}