#include "sort.h"

/**
 * print_merg - function print the left and right and merg
 * @array: array to print
 * @start: start of the array
 * @end: end of the array
 * @side: which size it is
 */
void print_merg(int *array, size_t start, size_t end, char *side)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i == end - 1)
		{
			printf("%d\n", array[i]);
			continue;
		}
		printf("%d, ", array[i]);
	}
}
/**
 * topdown - function divid the array in to sub array
 * @array: array to be divided
 * @start: the starting of the array
 * @end: end of the array
 * @newarray: new array to dump sorted
 * Return: void
 */
void topdown(int *array, size_t start, size_t end, int *newarray)
{
	size_t i, j, k, mid;

	mid = (start + end) / 2;
	if (end - start <= 1)
		return;
	topdown(array, start, mid, newarray);
	topdown(array, mid, end, newarray);
	printf("Merging...\n");
	print_merg(array, start, mid, "left");
	print_merg(array, mid, end, "right");
	k = start;
	j = mid;
	for (i = start; i < end; i++)
	{
		if (k < mid && (j >= end || array[k] <= array[j]))
		{
			newarray[i] = array[k];
			k = k + 1;
		}
		else
		{
			newarray[i] = array[j];
			j = j + 1;
		}
	}
	print_merg(newarray, start, end, "Done");
	for (i = start; i < end; i++)
	{
		array[i] = newarray[i];
	}
}

/**
 * merge_sort - fuction sort element by divid an conquer
 * @array: array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *newarray;

	if (array == NULL || size < 2)
		return;
	newarray = malloc(sizeof(int) * size);
	if (newarray == NULL)
		return;
	topdown(array, 0, size, newarray);
	free(newarray);
}
