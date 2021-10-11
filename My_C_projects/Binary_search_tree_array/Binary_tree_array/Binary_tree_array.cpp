#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>


void show_tree(int* arr, int size)
{
	int i;
	for (i = 0;i < size;i++)
	{
		if (arr[i])
		{
			printf("arr[%d] = %d ", i, arr[i]);
		}
	}
	printf("\n");
}
/*
* 0
* 12
* 3456
* 789101112
*/

int find_index(int* arr, int num, int size)
{
	int index = 0;
	while (arr[index])
	{
		if (arr[index] > num)
			index = index * 2 + 1;
		else if (arr[index] < num)
			index = index * 2 + 2;
		else
		{
			printf("Duplicate!\n");
			return -1;
		}
		if (index > size)
		{
			printf("No space!\n");
			return -1;
		}
	}
	return index;
}

int find_num(int* arr, int size, int num)
{
	int index = 0;
	while ((arr[index]) && (index > size))
	{
		if (arr[index] > num)
			index = index * 2 + 1;
		else if (arr[index] < num)
			index = index * 2 + 2;
		if (arr[index] == num)
		{
			return 1;
		}
	}
	return 0;
}


void delete_num(int* arr, int num, int size)
{
	int index = 0;
	while (index < size)
	{
		if (arr[index] > num)
			index = index * 2 + 1;
		else if (arr[index] < num)
			index = index * 2 + 2;
		if (arr[index] == num)
		{
			arr[index] = 0;
			return;
		}
	}
	printf("Number not found\n");
}

int main()
{
	int size;
	printf("Enter the size\n");
	scanf_s("%d", &size);
	int* arr;
	arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	memset(arr, 0, size*sizeof(int));
	int index = 0;
	int do_what, duplicate = 0;
	//What is the guarantee that the new variable defined will have the same address as the previous one
	while (1)
	{
		printf("To add: 1\nTo delete: 2\nTo find: 3\nTo print: 4\nTo exit: -1\n");
		scanf_s("%d", &do_what);
		int num;
		switch (do_what)
		{
		case 1:
		{
			printf("Enter number: ");
			scanf_s("%d", &num);
			int index = find_index(arr, num, size);
			if (index >= 0)
			{
				arr[index] = num;
			}
			break;
		}
		case 2:
		{
			printf("Enter number: ");
			scanf_s("%d", &num);
			break;
		}
		case 3:
		{
			printf("Enter a number: ");
			scanf_s("%d", &num);
			if (find_num(arr, size, num))
			{
				printf("Found!\n");
			}
			else
			{
				printf("Not found!\n");
			}
			break;
		}
		case 4:
		{
			show_tree(arr, size);
			break;
		}
		case -1:
		{
			exit(0);
		}
		default:
		{
			break;
		}
		}
	}
}