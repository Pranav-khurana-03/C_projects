#include<stdio.h>
#include<stdlib.h>

void rotate(int* arr, int digits, int ub)
{
	int temp = arr[digits-1];
	for (int i = digits-1; i >=ub; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[ub] = temp;
}

void print_arr(int* arr, int digits)
{
	for (int i = 0;i < digits;i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

void combinations_create(int *arr, int size)
{
static int i = 0;
		int repeat;
		if (i == (size - 1))
		{
			print_arr(arr, size);
			i--;
			return;
		}
		for (repeat = i;repeat < size;repeat++)
		{
			i++;
			combinations_create(arr, size);
			rotate(arr, size, i);
		}
		i--;
	}

int main()
{
	int size;
	printf("Enter number of digits: ");
	scanf("%d", &size);
	int* arr, i;
	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
	{
		return 0;
	}
	for (i = 0;i < size;i++)
	{
		scanf("%d", &arr[i]);
	}

	combinations_create(arr, size);
}