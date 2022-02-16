#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: array size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp, index, status;
	size_t i, k;

	for (i = 0; i < size - 1; i++)
	{
		status = 0;
		index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[index])
			{
				index = k;
				status = 1;
			}

		}
		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		if (status == 1)
			print_array(array, size);
	}
}
