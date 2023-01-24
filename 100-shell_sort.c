#include "sort.h"

/**
 * shell_sort - function used to sort using Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, tmp;
	size_t j;

	while (gap < size)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; j >= 1; i = i - gap)
			{
				if (array[i + gap] > array[i])
				{
					break;
				}
				else
				{
					tmp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = tmp;
					print_array(array, size);
				}
			}
		}
		gap = gap * 3 + 1;
	}
	gap = gap / 3;
}
