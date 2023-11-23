#include "sort.h"

/**
* locate_min - Locates the minimum value from the current index in the array
* @array: The array to be searched
* @index: The starting index of the search
* @size: The size of the array
* Return: The index of the minimum value if found,
* or the same given index if it's already the minimum
*/
int locate_min(int *array, int index, size_t size)
{
int min_value = array[index];
int min_index = index;
int i;

for (i = index; i < (int)size; i++)
{
if (array[i] < min_value)
{
min_value = array[i];
min_index = i;
}
}

if (min_index == index)
return (-1);

return (min_index);
}

/**
* selection_sort - Implements the Selection Sort algorithm
* @array: The array to be sorted (type int *)
* @size: The size of the given array
*/
void selection_sort(int *array, size_t size)
{
int i, min_index, temp;

for (i = 0; i < (int)size; i++)
{
min_index = locate_min(array, i, size);

if (min_index != -1)
{
temp = array[i];
array[i] = array[min_index];
array[min_index] = temp;
print_array(array, size);
}
}
}
