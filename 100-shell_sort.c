#include "sort.h"

/**
 * shell_sort - function used to sort using Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, int size)
{
	int gap = 1, i, tmp;
	int j;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j = j - gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}

}
