#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swp, tmp;
	for (i = size; i > 0; i--)
	{
		swp = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swp = 1;
				print_array(array, size);
			}
		}
		if (swp == 0)
			break;
	}
}
