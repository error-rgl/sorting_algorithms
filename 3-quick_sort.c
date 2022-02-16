#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using quick sort implements the Lomuto
 * partition scheme to choose pivot.
 * @array: array of integers to sort
 * @size: size of array to sort.
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	quick_sorting(array, size, array, size);
}

/**
 * quick_sorting - sorts array with quick sort,
 * prints after every switch
 * @array: array or subarray to sort
 * @size: size of array to sort
 * @full_array: full array for printing
 * @full_size: size of full array for printing
 */

void quick_sorting(int *array, size_t size, int *full_array, size_t full_size)
{
	size_t i = 0, pivot = size - 1, position = 0;
	int temp = 0;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < pivot; i++)
	{
		if (array[i] < array[pivot] && i == position)
			position++;
		else if (array[i] < array[pivot] && i != position)
		{
			temp = array[i];
			array[i] = array[position];
			array[position] = temp;
			position++;
			print_array(full_array, full_size);
		}
	}
	if (array[pivot] != array[position])
	{
		temp = array[pivot];
		array[pivot] = array[position];
		array[position] = temp;
		print_array(full_array, full_size);
	}

	/* left side */
	quick_sorting(array, position, full_array, full_size);
	/* right side */
	position += 1;
	quick_sorting(&array[position], size - position, full_array, full_size);
}
