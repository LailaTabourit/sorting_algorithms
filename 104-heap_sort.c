#include "sort.h"

/**
* check_tree - swiftdown check
* @array: pointer to array
* @size: size of the pointer
* @size_init: original size of the array
* @i: index as a root of the tree
* Made by LAILO and MEGA
**/

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int m, branch1, branch2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	branch1 = array[br1];
	branch2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((br1 == size - 1) && branch1 > array[i]))
	{
		m = array[i];
		array[i] = branch1;
		array[br1] = m;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		m = array[i];
		array[i] = branch2;
		array[br2] = m;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}

/**
* heap_sort - sorts an array of integers
* in ascending order using the Heap
* sort algorithm
* @array: pointer to array
* @size: size of the pointer
* Made by LAILO and MEGA
**/

void heap_sort(int *array, size_t size)
{
	size_t a, size_init = size;
	int m;

	if (!array)
		return;
	for (a = 0; a < size / 2 ; a++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - a);
	}
	for (a = 0; a < size_init - 1; a++)
	{
		m = array[0];
		array[0] = array[size - 1 - a];
		array[size - 1 - a] = m;
		print_array(array, size_init);
		check_tree(array, size_init, size - a - 1, 0);
	}
}
