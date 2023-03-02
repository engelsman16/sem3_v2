#include <string.h>

#include "challenge.h"
#include "sort.h"
#include "input.h"
#include "unity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
  // This is run before EACH test
}

void tearDown(void)
{
  // This is run after EACH test
}

// input.c tests

void test_get_size_invalid_input(void)
{
  int size = 0;

  TEST_ASSERT_EQUAL(-1, GetSize(NULL));
  TEST_ASSERT_EQUAL(0, size);
}

void test_get_array_invalid_input(void)
{
  int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(-1, GetArray(NULL, arraySize));
  TEST_ASSERT_EQUAL(0, array[0]);
  TEST_ASSERT_EQUAL(0, array[1]);
  TEST_ASSERT_EQUAL(0, array[2]);
  TEST_ASSERT_EQUAL(0, array[3]);
  TEST_ASSERT_EQUAL(0, array[4]);
  TEST_ASSERT_EQUAL(0, array[5]);
  TEST_ASSERT_EQUAL(0, array[6]);
  TEST_ASSERT_EQUAL(0, array[7]);
  TEST_ASSERT_EQUAL(0, array[8]);
  TEST_ASSERT_EQUAL(0, array[9]);

  TEST_ASSERT_EQUAL(-1, GetArray(array, 0));
  TEST_ASSERT_EQUAL(0, array[0]);
  TEST_ASSERT_EQUAL(0, array[1]);
  TEST_ASSERT_EQUAL(0, array[2]);
  TEST_ASSERT_EQUAL(0, array[3]);
  TEST_ASSERT_EQUAL(0, array[4]);
  TEST_ASSERT_EQUAL(0, array[5]);
  TEST_ASSERT_EQUAL(0, array[6]);
  TEST_ASSERT_EQUAL(0, array[7]);
  TEST_ASSERT_EQUAL(0, array[8]);
  TEST_ASSERT_EQUAL(0, array[9]);
}

void test_get_repeat_invalid_input(void)
{
  int k = 0;

  TEST_ASSERT_EQUAL(-1, GetRepeat(NULL));
  TEST_ASSERT_EQUAL(0, k);
}

// sort.c tests
void test_bubble_sort(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(0, BubbleSort(array, arraySize));
  TEST_ASSERT_EQUAL(1, array[0]);
  TEST_ASSERT_EQUAL(2, array[1]);
  TEST_ASSERT_EQUAL(3, array[2]);
  TEST_ASSERT_EQUAL(4, array[3]);
  TEST_ASSERT_EQUAL(5, array[4]);
  TEST_ASSERT_EQUAL(6, array[5]);
  TEST_ASSERT_EQUAL(7, array[6]);
  TEST_ASSERT_EQUAL(8, array[7]);
  TEST_ASSERT_EQUAL(9, array[8]);
  TEST_ASSERT_EQUAL(10, array[9]);
}

void test_bubble_sort_invalid_input(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(-1, BubbleSort(NULL, arraySize));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);

  TEST_ASSERT_EQUAL(-1, BubbleSort(array, 0));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);
}

void test_merge_sort(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(0, MergeSort(array, 0, arraySize - 1));
  TEST_ASSERT_EQUAL(1, array[0]);
  TEST_ASSERT_EQUAL(2, array[1]);
  TEST_ASSERT_EQUAL(3, array[2]);
  TEST_ASSERT_EQUAL(4, array[3]);
  TEST_ASSERT_EQUAL(5, array[4]);
  TEST_ASSERT_EQUAL(6, array[5]);
  TEST_ASSERT_EQUAL(7, array[6]);
  TEST_ASSERT_EQUAL(8, array[7]);
  TEST_ASSERT_EQUAL(9, array[8]);
  TEST_ASSERT_EQUAL(10, array[9]);
}

void test_merge_sort_invalid_input(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(-1, MergeSort(NULL, 0, arraySize - 1));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);

  TEST_ASSERT_EQUAL(-1, MergeSort(array, -1, arraySize - 1));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);
}

void test_selection_sort(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(0, SelectionSort(array, arraySize));
  TEST_ASSERT_EQUAL(1, array[0]);
  TEST_ASSERT_EQUAL(2, array[1]);
  TEST_ASSERT_EQUAL(3, array[2]);
  TEST_ASSERT_EQUAL(4, array[3]);
  TEST_ASSERT_EQUAL(5, array[4]);
  TEST_ASSERT_EQUAL(6, array[5]);
  TEST_ASSERT_EQUAL(7, array[6]);
  TEST_ASSERT_EQUAL(8, array[7]);
  TEST_ASSERT_EQUAL(9, array[8]);
  TEST_ASSERT_EQUAL(10, array[9]);
}

void test_selection_sort_invalid_input(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arraySize = sizeof(array) / sizeof(array[0]);

  TEST_ASSERT_EQUAL(-1, SelectionSort(NULL, arraySize));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);

  TEST_ASSERT_EQUAL(-1, SelectionSort(array, 0));
  TEST_ASSERT_EQUAL(10, array[0]);
  TEST_ASSERT_EQUAL(9, array[1]);
  TEST_ASSERT_EQUAL(8, array[2]);
  TEST_ASSERT_EQUAL(7, array[3]);
  TEST_ASSERT_EQUAL(6, array[4]);
  TEST_ASSERT_EQUAL(5, array[5]);
  TEST_ASSERT_EQUAL(4, array[6]);
  TEST_ASSERT_EQUAL(3, array[7]);
  TEST_ASSERT_EQUAL(2, array[8]);
  TEST_ASSERT_EQUAL(1, array[9]);
}

void test_find_smallest_number_for_number_of_wanted_occurences(void)
{
  int array[] = {10, 10, 2, 2, 1, 1, 1, 4, 5, 4};
  int arraySize = sizeof(array) / sizeof(array[0]);
  int K = 2;
  int smallestNumber = 0;

  TEST_ASSERT_EQUAL(0, FindSmallestNumberThatIsRepeatedKTimes(
                           array, arraySize, K, &smallestNumber));

  TEST_ASSERT_EQUAL(2, smallestNumber);
}

void test_find_smallest_number_for_number_of_wanted_occurences_invalid_input(void)
{
  int array[] = {10, 10, 2, 2, 1, 1, 1, 4, 5, 4};
  int arraySize = sizeof(array) / sizeof(array[0]);
  int K = 2;
  int smallestNumber = 0;

  TEST_ASSERT_EQUAL(-1, FindSmallestNumberThatIsRepeatedKTimes(
                            NULL, arraySize, K, &smallestNumber));
  TEST_ASSERT_EQUAL(-1, FindSmallestNumberThatIsRepeatedKTimes(
                            array, 0, K, &smallestNumber));
  TEST_ASSERT_EQUAL(-1, FindSmallestNumberThatIsRepeatedKTimes(
                            array, arraySize, 0, &smallestNumber));
  TEST_ASSERT_EQUAL(-1, FindSmallestNumberThatIsRepeatedKTimes(
                            array, arraySize, K, NULL));
}

void test_get_difference(void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arraySize = sizeof(array) / sizeof(array[0]);
  int K = 2;
  int difference = 0;

  TEST_ASSERT_EQUAL(0, GetDifference(array, arraySize, K, &difference));

  TEST_ASSERT_EQUAL(16, difference);
}

void test_get_difference_invalid_input(void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arraySize = sizeof(array) / sizeof(array[0]);
  int K = 2;
  int difference = 0;

  TEST_ASSERT_EQUAL(-1, GetDifference(NULL, arraySize, K, &difference));
  TEST_ASSERT_EQUAL(-1, GetDifference(array, 0, K, &difference));
  TEST_ASSERT_EQUAL(-1, GetDifference(array, arraySize, 0, &difference));
  TEST_ASSERT_EQUAL(-1, GetDifference(array, arraySize, K, NULL));
}

int main(int argc, char *argv[])
{
  UnityBegin();

  MY_RUN_TEST(test_find_smallest_number_for_number_of_wanted_occurences);
  MY_RUN_TEST(test_find_smallest_number_for_number_of_wanted_occurences_invalid_input);

  MY_RUN_TEST(test_get_size_invalid_input);
  MY_RUN_TEST(test_get_array_invalid_input);
  MY_RUN_TEST(test_get_repeat_invalid_input);

  MY_RUN_TEST(test_bubble_sort);
  MY_RUN_TEST(test_bubble_sort_invalid_input);
  MY_RUN_TEST(test_merge_sort);
  MY_RUN_TEST(test_merge_sort_invalid_input);
  MY_RUN_TEST(test_selection_sort);
  MY_RUN_TEST(test_selection_sort_invalid_input);

  MY_RUN_TEST(test_get_difference);
  MY_RUN_TEST(test_get_difference_invalid_input);

  return UnityEnd();
}
