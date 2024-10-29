#include "sort.h"

/**
  * bubble_sort - a func that sorts an array using the bubble sort
  * algorithm
  * Return: Void
  * @array: the array to be sorted
  * @size: the size of the array to be sorted
  */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
