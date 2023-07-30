#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 * using the selection sort algorithm
 *
 * @array: the array to sort
 * @size: number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, idx;
	int smallest, print = -1;

	for (j = 0; j < size; j++)
	{
		smallest = array[j];
		idx = j;
		print = -1;
		for (i = j + 1; i < size; i++)
		{
			if (smallest > array[i])
			{
				smallest = array[i];
				idx = i;
				print = 0;
			}
		}
		temp = array[j];
		array[j] = smallest;
		array[idx] = temp;
		if (print == 0)
			print_array(array, size);
	}
}
