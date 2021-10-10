#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* make_string(char name[100])
{
	int len = strlen(name);
	char* string = (char*)malloc(sizeof(char) * (len+1));
	if (!string)
	{
		exit(-1);
	}
	strcpy_s(string, strlen(string), name);
	return string;
}

struct node
{
	int num;
	char *name;
};

void hash_show(struct node* arr, int size)
{
	printf("Index\tRollno\tName\n\n");
	for (int i = 0;i < size;i++)
	{
		if (!arr[i].num)
			continue;
		printf("%d\t%d\t%s\n", i, arr[i].num, arr[i].name);
	}
}

int re_hash(int index, int size)
{
	return (index + 1) % size;
}

void hash_insert(struct node* arr, int num, int size, char name[100])
{
	int index = num % size;
	int ini_index = index;
	while (arr[index].num>0)
	{
		if ((arr[index].num) == num)
		{
			printf("Duplicate!\n");
			return;
		}
		index = re_hash(index, size);
		if (index == ini_index)
		{
			printf("Table full!\n");
			return;
		}
	}
	arr[index].num = num;
	arr[index].name = make_string(name);
	return;
}


char* hash_find(struct node* arr, int num, int size)
{
	int index = num % size;
	int ini_index = index;
	do 
	{
		if (arr[index].num == num)
		{
			break;
		}
		index = re_hash(index, size);
	} while ((arr[index].num) && (index != ini_index));
	return arr[index].name;
}

void hash_delete(struct node* arr, int num, int size)
{
	int index = num % size;
	int ini_index = index;
	/* Use hash_find instead of redoing the same thing here*/
	do
	{
		if ((arr[index].num) == num)
		{
			arr[index].num = -1;
			arr[index].name = NULL;
			return;
		}
		index = re_hash(index, size);
	} while ((arr[index].num) && (index != ini_index));
	printf("Number not found\n");
}


int main()
{
	int size = 10, do_what;
	struct node arr[10];
	memset(arr, 0, sizeof(struct node)*10);
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
			hash_insert(arr, num, size, name);
			break;
		case 2:
			printf("Enter roll no.\n");
			scanf_s("%d", &num);
			hash_delete(arr, num, size);
			break;
		case 3:
			printf("Enter roll no.\n");
			scanf_s("%d", &num);
			char* name_ptr;
			name_ptr = hash_find(arr, num, size);
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