#include "sort.h"

/**
* swap - Swaps two integers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*
* Swaps the values of the two integers.
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* partition - Partitions an array using a pivot element
* @array: The array to be partitioned
* @low: The lowest index of the partition
* @high: The highest index of the partition
* @size: The size of the array
*
* Return: the index of the pivot element after partitioning.
*/
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j <= high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}

return (i);
}

/**
* lomuto_qsort - Recursively sorts an array using the Lomuto partition scheme
* @array: The array to be sorted
* @low: The lowest index of the array
* @high: The highest index of the array
* @size: The size of the array
*
* Sorts the array in place using the Quick sort algorithm
* with the Lomuto partition scheme.
*/
void lomuto_qsort(int *array, int low, int high, size_t size)
{
int pivot_index;

if (low < high)
{
pivot_index = partition(array, low, high, size);
lomuto_qsort(array, low, pivot_index - 1, size);
lomuto_qsort(array, pivot_index + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*
* Sorts the array in place using the Quick sort algorithm
* with the Lomuto partition scheme.
*/
void quick_sort(int *array, size_t size)
{
lomuto_qsort(array, 0, size - 1, size);
}
