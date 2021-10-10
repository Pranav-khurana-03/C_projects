#include <stdio.h>
#include <stdlib.h>

int max_element_min_k_partitions(int *arr, int size, int k)
{
	if ((!(arr || k)) || (k > size))
	{
		exit(-1);
	}
	int i, j;
	int min = arr[0], max;
	for (i = 0; i < k; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	max = min;
	min = arr[i];
	for (i; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (((i+1) % k == 0)||(i==size-1))
		{
			if (min > max)
			{
				max = min;
			}
			min = arr[i+1];
		}
	}
	return max;
}

int main()
{
	int size, k;
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int) * size);
	int i;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	while (1)
	{
		printf("\nEnter k: ");
		scanf("%d", &k);
		printf("%d", max_element_min_k_partitions(arr, size, k));
	}
}