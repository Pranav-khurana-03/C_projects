#include<stdio.h>

int median_sorted_arr(int* arr, int* arr2)
{
	
}

int main()
{
	int* arr, *arr2;
	int size, size2;
	printf("Enter sizes: ");
	scanf("%d %d", &size, &size2);
	arr = (int*)malloc(sizeof(int)*size);
	arr2 = (int*)malloc(sizeof(int)*size2);
	int i;
	printf("Enter elemnets for arr 1: ");
	for(i=0;i<size;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=0;i<size2;i++)
	{
		scanf("%d", &arr2[i]);
	}
}