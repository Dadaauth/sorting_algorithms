#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int sorted(int *array, size_t size);
/**
 * bubble_sort - sorts an array of integers using the bubble
 * sort algorithm
 *
 * @array: the array of integers to sort
 * @size: the size of @array
 */
void bubble_sort(int *array, size_t size)
{
	int temp, one, two;
	size_t j;

	if (array ==  NULL)
		return;
	if (size < 2)
	{
		return;
	}
	while (sorted(array, size) == -1)
	{
		for (j = 1; j < size; j++)
		{
			one = j - 1;
			two = j;
			if (array[one] > array[two])
			{
				temp = array[one];
				array[one] = array[two];
				array[two] = temp;
				print_array(array, size);
			}
			if (sorted(array, size) == 0)
				break;
		}
	}
}
/**
 * sorted - checks if an array of integers is sorted
 *
 * @array: the array to check
 * @size: the size of @array
 *
 * Return: -1 if unsorted, 0 if otherwise
 */
int sorted(int *array, size_t size)
{
	int one, two;
	size_t i;

	for (i = 1; i < size; i++)
	{
		one = i - 1;
		two = i;
		if (array[one] > array[two])
			return (-1);
	}
	return (0);
}
