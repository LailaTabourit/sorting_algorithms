#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending
* order using the Counting sort algorithm
* @array: pointer to array
* @size: size of the array
* Made by LAILO and MEGA
**/

void counting_sort(int *array, size_t size)
{
	int m, j, *count_array, *aux;
	size_t a;

	if (!array || size < 2)
		return;
	m = array[0];
	for (a = 0; a < size; a++)
	{
		if (array[a] > m)
			m = array[a];
	}
	count_array = calloc((m + 1), sizeof(int));
	for (a = 0; a < size; a++)
	{
		count_array[array[a]]++;
	}
	for (j = 1; j < m; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, m + 1);
	aux = malloc(sizeof(int) * size);
	for (a = 0; a < size; a++)
	{
		count_array[array[a]]--;
		aux[count_array[array[a]]] = array[a];
	}
	for (a = 0; a < size; a++)
	{
		array[a] = aux[a];
	}
	free(aux);
	free(count_array);
}
