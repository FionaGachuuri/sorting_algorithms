#include "sort.h"

/**
  *swap -function that swaps two elements in an array
  *@a: first element to swap
  *@b: second integer to swap
  */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
  *partitions -partitions  the array using Lomuto scheme
  *@array: array of integers
  *@low: starting index of the partition to sort
  *@high: ending index of the partition to sort
  *@size: size of the array
  *
  *Return: final partition index
  */

int partitions(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
  *quicksort -function that recursively sorts an array using quicksort
  *@array: The array of integers.
  *@low: Starting index of the partition to sort.
  *@high: The ending index of the partition to sort.
  *@size: The size of the array.
  */

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partitions(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
  *quick_sort -sorts an integers array using the quicksort algorithm.
  *@array: array of integers.
  *@size: size of the array.
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
