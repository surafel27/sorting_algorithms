#include "sort.h"

/**
 * partition - fuction to make partition high and low
 * @array: array
 * @low: the starting of the array
 * @high: size - 1
 * @size: the size of the array
 * Return: the position of the pivot
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int tmp, pivot = array[high];
	ssize_t j, i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - recursion function
 * @array: array
 * @low: the starting of the array
 * @high: size - 1
 * @size: the size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t quick;

		quick = partition(array, low, high, size);
		quicksort(array, low, quick - 1, size);
		quicksort(array, quick + 1, high, size);
	}
}
/**
 * quick_sort - main fuction
 * @array: array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
