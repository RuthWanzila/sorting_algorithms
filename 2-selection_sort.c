#include "sort.h"
#include <stdio.h>

/**
* locate_min - Locates the minimum value from the current index in the array
* @array: The array to be searched
* @index: Starting index of the search
* @size: The size of the array
* Return: The index of the minimum value if found,
 * or the same given index if the index is the minimum
*/
int locate_min(int *array, int index, size_t size)
{
int min, idx_min;
int i;

min = array[index];
idx_min = index;
for (i = index; i < (int)size; i++)
{
if (array[i] < min)
{
min = array[i];
idx_min = i;
}
}
if (idx_min == index)
return (-1);
return (idx_min);
}

/**
* selection_sort - Implementation of the Selection Sort algorithm
* @array: Array to sort (type int *)
* @size: The size of the given array
*/
void selection_sort(int *array, size_t size)
{
int i;
int min, tmp;

for (i = 0; i < (int)size; i++)
{
min = locate_min(array, i, size);
if (min != -1)
{
tmp = array[i];
array[i] = array[min];
array[min] = tmp;

/* Print the array */
printf("%d", array[0]);
for (i = 1; i < (int)size; i++)
printf(", %d", array[i]);
printf("\n");
}
}
}
