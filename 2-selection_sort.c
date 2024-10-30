#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			swap_ints(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
