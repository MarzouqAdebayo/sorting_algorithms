#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, innerMinIdx, temp;

	for (i = 0; i < size; i++)
	{
		innerMinIdx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[innerMinIdx])
				innerMinIdx = j;
		}
		if (innerMinIdx != i)
		{
			temp = array[i];
			array[i] = array[innerMinIdx];
			array[innerMinIdx] = temp;
			print_array(array, size);
		}
	}
}
