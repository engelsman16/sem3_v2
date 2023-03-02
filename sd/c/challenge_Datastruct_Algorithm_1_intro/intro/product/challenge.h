#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <stdint.h>

int GetDifference(int *array, int size, int k, int *difference);

int FindSmallestNumberThatIsRepeatedKTimes(
    int *array, int size, int k, int *smallestNumber);

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_BubbleSort(
    int *array, int size, int k, int *difference);

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_MergeSort(
    int *array, int size, int k, int *difference);

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_SelectionSort(
    int *array, int size, int k, int *difference);

#endif
