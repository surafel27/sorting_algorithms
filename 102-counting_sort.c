#include "sort.h"

/**
 * max_min - function dind max element from an array
 * @array: array to check
 * @size: the size of the array
 * Return: max
 */
int max_min(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - function sort by cointing the element
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, x, z, k;
	int *count, *newarray;

	k = max_min(array, size);
	if (array == NULL || size < 2)
		return;
	count = malloc(sizeof(int) * k + 1);
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] = count[array[i]] + 1;
	for (j = 1; j <= k; j++)
		count[j] = count[j] + count[j - 1];
	for (j = 1; j <= k; j++)
	{
		if (j == k)
		{
			printf("%i", count[j]);
			continue;
		}
		printf("%i, ", count[j]);
	}
	printf("\n");
	newarray = malloc(sizeof(int) * size);
	for (x = 0; x < size; x++)
	{
		newarray[count[array[x]] - 1] = array[x];
		count[array[x]]--;
	}
	for (z = 0; z < size; z++)
		array[z] = newarray[z];
	free(count);
	free(newarray);
}
