#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "challenge.h"
#include "input.h"

#include "realtime.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }
    char selectedAssignment = atoi(argv[1]);

    int size = 0;
    GetSize(&size);
    int array[size];
    GetArray(array, size);
    int repeat = 0;
    GetRepeat(&repeat);

    // TODO: parse data from stdin as explained in part 0 in the challenge document
    // (obviously: parsing data is another responsibility than commandline UI stuff,
    //  so parsing data should happen in another file!)

    if (selectedAssignment == 1)
    {
        int smallestNumber = 0;
        double startTime = getRealTime();
        FindSmallestNumberThatIsRepeatedKTimes(array, size, repeat, &smallestNumber);
        double endTime = getRealTime();
        printf("Time: %f\n", endTime - startTime);
        printf("%d\n", smallestNumber);
    }
    else if (selectedAssignment == 2)
    {
        int difference = 0;
        double startTime = getRealTime();
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_BubbleSort(array, size, repeat, &difference);
        double endTime = getRealTime();
        printf("Time: %f\n", endTime - startTime);
        printf("Difference highlow: %d\n", difference);
    }
    else if (selectedAssignment == 3)
    {
        int difference = 0;
        double startTime = getRealTime();
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_MergeSort(array, size, repeat, &difference);
        double endTime = getRealTime();
        printf("Time: %f\n", endTime - startTime);
        printf("Difference highlow: %d\n", difference);
    }
    else if (selectedAssignment == 4)
    {
        int difference = 0;
        double startTime = getRealTime();
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_SelectionSort(array, size, repeat, &difference);
        double endTime = getRealTime();
        printf("Time: %f\n", endTime - startTime);
        printf("Difference highlow: %d\n", difference);
    }
    else
    {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }

    return 0;
}
