#ifndef SORT_H
#define SORT_H

#include <stdio.h>

int BubbleSort(int *array, int size);
// O (n2)

int MergeArray(int *array, int left, int mid, int right);

int MergeSort(int *array, int left, int right);
// O(n log n)

int SelectionSort(int *array, int size);
// O(n2)

int CopyRemainingElements(int *array, int *tempArray, int *k, int *index, int n);

#endif
