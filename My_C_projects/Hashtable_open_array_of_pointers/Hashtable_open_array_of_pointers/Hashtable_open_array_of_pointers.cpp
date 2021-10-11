#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct node
{
	int roll;
	char name[100];
	struct node* ptr;
};

void hash_show(struct node** arr, int size)
{
	printf("Index\tRollno\tName\n\n");
	for (int i = 0;i < size;i++)
	{
		struct node* tmp = arr[i];
		/*Avoid printing empty buckets*/
		if (!arr[i]) 
			continue;
		printf("%d\t", i);
		while (tmp)
		{
			printf("%d\t", tmp->roll);
			printf("%s\t", tmp->name);
			tmp = tmp->ptr;
		}
		printf("\n");
	}
}

void hash_add(struct node**arr, int size, int num, char name[100])
{
	int index = num % size;
	struct node* to_add, *tmp, *prev;
	to_add = (struct node*)malloc(sizeof(struct node));
	assert(to_add);
	to_add->roll = num;
	strcpy_s(to_add->name, name);
	to_add->ptr = NULL;
	if (arr[index])
	{
		tmp = arr[index];
		prev = NULL;
		while ((tmp) && (num >(tmp->roll)))
		{
			prev = tmp;
			tmp = tmp->ptr;
		}
		to_add->ptr = tmp;
		if (!prev)
		{
			arr[index] = to_add;
		}
		else {
			prev->ptr = to_add;
		}
		return;
	}
	arr[index] = to_add;
}

void hash_delete(struct node**arr, int size, int num)
{
	int index = num % size;
	struct node* tmp, *prev;
	tmp = arr[index];
	prev = NULL;
	while ((tmp) && ((tmp->roll) <= num))
	{
		if ((tmp->roll) == num)
		{
			if (prev)
			{
				prev->ptr = tmp->ptr;
			}
			else
			{
				arr[index] = tmp->ptr;
			}
			free(tmp);
			return;
		}
		prev = tmp;
		tmp = tmp->ptr;
	}
	printf("Number not found!\n");
}

char* hash_find(struct node**arr, int size, int num)
{
	int index = num % size;
	struct node* tmp = arr[index];
	while ((tmp) && ((tmp->roll) <= num))
	{
		if ((tmp->roll) == num)
		{
			return tmp->name;
		}
		tmp = tmp->ptr;
	}
	return NULL;
}


int main()
{
	int size, do_what;
	printf("Enter size\n");
	scanf_s("%d", &size);
	struct node** arr;
	arr = (struct node**)malloc(sizeof(struct node*) * size);
	assert(arr);
	memset(arr, 0, sizeof(struct node*) * size);
	char name[100] = "Pranav";
	//Check why the string cannot be passed directly to the hash_add function and needs
	//to be stored in a variable
	while (true)
	{
		printf("To add: 1\nTo delete: 2\nTo find: 3\nTo display: 4\nTo exit: -1\n");
		scanf_s("%d", &do_what);
		int num;
		switch (do_what)
		{
		case 1:
			char name[100];
			memset(name, 0, 100);
			char garbage;
			printf("Enter roll no. and name\n");
			scanf_s("%d", &num);
			scanf_s("%c", &garbage, sizeof(garbage));
			scanf_s("%[^\n]%*c", name, sizeof(name));
			hash_add(arr, size, num, name);
			break;
		case 2:
			printf("Enter roll no.\n");
			scanf_s("%d", &num);
			hash_delete(arr, size, num);
			break;
		case 3:
			printf("Enter roll no.\n");
			scanf_s("%d", &num);
			char* name_ptr;
			name_ptr = hash_find(arr, size, num);
			if (!name_ptr)
			{
				printf("Number not found\n");
			}
			else
			{
				printf("%s\n", name_ptr);
			}
			break;
		case 4:
			hash_show(arr, size);
			break;
		case -1:
			exit(0);
		default:
			printf("Invalid number\n");
			scanf_s("%[^\n]%*c", name, sizeof(name));
			break;
		}
	}
}