#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array to sort
 * @size: array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, k;

	if (sizeof(array) == 0 || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (k = 0; k < size - 1  - i; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
