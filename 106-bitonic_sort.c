#include "sort.h"

/**
* _swap - function that swaps two elements
* @ar : array
* @e1 : first element
* @e2 : second element
* @ord : 1 in ascending order, 0 descending
* by: laila and mega
*/
void _swap(int ar, int e1, int e2, int ord)
{
	int tmp;

	if (ord == (ar[e1] > ar[e2]))
	{
		tmp = ar[e1];
		ar[e1] = ar[e2];
		ar[e2] = tmp;
	}
}
/**
 * _merge - function that sorts bitonic sequences recursively
 * in both orders
 * @ar: array
 * @low: first element
 * @nelement: number
 * @ord: 1 ascending order, 0 descending
 * by :laila and mega
 */
void _merge(int ar[], int low, int nelement, int ord)
{
	int midd, n;

	if (nelement > 1)
	{
		midd = nelement / 2;
		for (n = low; n < low + midd; n++)
			_swap(ar, n, n + midd, ord);
		_merge(ar, low, midd, ord);
		_merge(ar, low + midd, midd, ord);
	}
}
/**
 * bitonicsort - function that bitonic sorts algorithm
 * implementation
 * @arr: array
 * @low: first elmt
 * @nelemnt: number of elements
 * @order: 1 ascending order, 0 descending order
 * @size: array lenght
 * by : laila and mega
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		_merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - function  prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 * by : laila and mega
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
