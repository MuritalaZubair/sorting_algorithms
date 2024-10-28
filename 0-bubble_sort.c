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
 * bubble_sort - Sort an array of integers in ascending order using Bubble Sort.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
	swapped = false;

	for (j = 0; j < size - 1 - i; j++)
	{
	if (array[j] > array[j + 1])
	{
	swap_ints(&array[j], &array[j + 1]);
	print_array(array, size);
	swapped = true;
	}
	}

	if (!swapped)
	break;
	}
}
