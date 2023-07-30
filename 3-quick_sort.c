#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * swap - swaps two elements in an array
 * @array: the array to work on;
 * @i: index i;
 * @j: index j;
 * @size: the size of @array
 */
void swap(int *array, int i, int j, int size)
{
	int temp = array[i];

	if (i == j)
		return;
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}
/**
 * partition - partition function for QuickSort
 * @array: the array to work on
 * @low: low
 * @high: high
 * @size: the size of the whole array
 * Return: an integer;
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}
/**
 * quick_sort - sorts an array of integers using
 * the quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	struct StackFrame *stack = malloc(sizeof(struct StackFrame) * size);
	int top = -1, low, high, pivot;

	stack[++top].low = 0;
	stack[top].high = size - 1;

	while (top >= 0)
	{
		low = stack[top].low;
		high = stack[top--].high;
		pivot = partition(array, low, high, size);
		if (pivot - 1 > low)
		{
			stack[++top].low = low;
			stack[top].high = pivot - 1;
		}
		if (pivot + 1 < high)
		{
			stack[++top].low = pivot + 1;
			stack[top].high = high;
		}
	}
}
