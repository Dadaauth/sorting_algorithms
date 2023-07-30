#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
int sorted(int *array, size_t size);
/**
 * quick_sort - sorts an array of integers using
 * the quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of @array
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot, i, j, jj, temp;
	int *rightArr, *leftArr;
	int rightSize, leftSize;

	if (size < 2)
		return;
	if (size == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}
	if (sorted(array, size) == 0)
		return;

	pivot = size - 1;
	i = 0;
	j = size - 2;
	jj = j;
	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[pivot])
		{
			for (j = jj; j >= i; j--)
			{
				if (array[j] < array[pivot])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					break;
				}
			}
			if (j < i)
			{
				temp = array[i];
				array[i] = array[pivot];
				array[pivot] = temp;
				pivot = i;
				break;
			}
			jj = j;
		}
	}



	/**
	 * Initialize the right side of the array
	 * and the left side of the array
	 */
	rightSize = size / 2;
	leftSize = size - rightSize;
	rightArr = malloc(sizeof(int) * rightSize);
	leftArr = malloc(sizeof(int) * leftSize);
	j = leftSize;
	for (i = 0; i < (size_t)rightSize; i++)
	{
		rightArr[i] = array[j];
		j++;
	}
	for (i = 0; i < (size_t)leftSize; i++)
	{
		leftArr[i] = array[i];
	}
	/*
	 * end of initialization
	 * */



	/* recursive sorting */
	quick_sort(rightArr, rightSize);
	quick_sort(leftArr, leftSize);


	/* merge right side and left side
	 * together to the whole array */
	j = 0;
	for (i = 0; i < size; i++)
	{

		if (i < (size_t)leftSize)
			array[i] = leftArr[i];
		else
		{
			array[i] = rightArr[j];
			j++;
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
