#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to search.
 * @size: The size of the array.
 * Return: The maximum value found.
 */
int get_max(int *array, size_t size);

/**
 * print_array - Prints the contents of an array.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(int *array, size_t size);

/**
 * radix_counting_sort - Performs a counting sort on the array
 *                       based on the digit represented by sig.
 * @array: The array to sort.
 * @size: The size of the array.
 * @sig: The significant digit to sort by.
 * @buff: The buffer to store the sorted results.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to search.
 * @size: The size of the array.
 * Return: The maximum value found.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * print_array - Prints the contents of an array.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * radix_counting_sort - Performs a counting sort on the array
 *                       based on the digit represented by sig.
 * @array: The array to sort.
 * @size: The size of the array.
 * @sig: The significant digit to sort by.
 * @buff: The buffer to store the sorted results.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (size - 1); (int)i >= 0; i--)
	{
		int digit = (array[i] / sig) % 10;
		buff[--count[digit]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the radix sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int *buff;
	int sig;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
