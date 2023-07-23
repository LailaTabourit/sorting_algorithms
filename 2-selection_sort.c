#include "sort.h"
#include <stdio.h>


/**
* selection_sort - sorts an array of intgs in ascending order
* @array: The array
* @size: The size of the array
* Made by LAILO and MEGA
* Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t a, step, min_idx;
	int cmp;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (a = step + 1; a < size; a++)
		{
			if (array[a] < array[min_idx])
				min_idx = a;
		}

		if (min_idx != step)
		{
			cmp = array[step];
			array[step] = array[min_idx];
			array[min_idx] = cmp;
			print_array(array, size);
		}
	}
}
