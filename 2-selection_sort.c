#include "sort.h"


/**
  * selection_sort - a func that sorts an array using the
  * selection sort algorithm
  * Return: void
  * @array: the array to be sorted
  * @size: the size of @array
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_number = 0;
	int temp = 0;

	for (i = 0; i < size; i++)
	{
		min_number = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_number])
			{
				min_number = j;
			}
		}
		if (min_number != i)
		{
			temp = array[i];
			array[i] = array[min_number];
			array[min_number] = temp;
			print_array(array, size);
		}
	}
}
