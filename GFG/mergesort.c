#include<stdio.h>
#include<stdlib.h>


int * merge(int *arr1, int* arr2, int size1, int size2)
{
	int* result = (int*)malloc(sizeof(int)*(size1 + size2));
	int j, i, index = 0;
	for(i = 0, j = 0; (i<size1 && j<size2);index++)
	{
		if(arr1[i]>arr2[j])
		{
			result[index] = arr2[j];
			j++;
		}
		else
		{
			result[index] = arr1[i];
			i++;
		}
	}
	while(j<size2)
	{
		result[index++] = arr2[j++];
	}
	while(i<size1)
	{
		result[index++] = arr1[i++];
	}
	return result;
}


int* mergesort(int* arr, int size)
{
	if(size==1)
		return arr;
	int*new_arr_1 = (int*)malloc(sizeof(int)* (int)(size/2));
	int*new_arr_2 = (int*)malloc(sizeof(int)* (int)(size - size/2));
	int i;
	for(i = 0; i<size/2; i++)
	{
		new_arr_1[i] = arr[i];
	}
	int index = 0;
	for(i;i<size;i++)
	{
		new_arr_2[index++] = arr[i];
	}
	new_arr_1 = mergesort(new_arr_1, size/2);
	new_arr_2 = mergesort(new_arr_2, (size - size/2));
	int* result = merge(new_arr_1, new_arr_2, size/2, size - size/2);
	return result;
}


int main()
{
	int arr[] = {2, 4, 8, 10, 3, 4};
	int* res = mergesort(arr,6);
	for(int i = 0; i<6;i++)
	{
		printf("%d", res[i]);
	}
}
