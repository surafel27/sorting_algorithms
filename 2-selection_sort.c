#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j, pos_j;
	int var, var2;
	for (i = 0; i < size; i++)
	{
		var2 = 0;
		var = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < var)
			{
				var = array[j];
				pos_j = j;
				var2 = 1;
			}
		}
		if (var2 == 1)
		{
			array[pos_j] = array[i];
			array[i] = var;
			print_array(array, size);
		}
	}
}
