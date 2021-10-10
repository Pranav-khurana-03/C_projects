#include<stdio.h>
#include<stdlib.h>

int i = 0;

struct node {
	int up;
	int down;
	struct node* ptr;
};

void push(struct node** head, int up, int down)
{
	struct node* item = (struct node*)malloc(sizeof(struct node));
	if (item)
	{
		item->down = down;
		item->up = up;
		if ((*head))
		{
			item->ptr = (*head);

		}
		else
		{
			item->ptr = NULL;
		}
	}
	(*head) = item;
}

struct node* pop(struct node** head)
{
	struct node* q = (*head);
	(*head) = (*head)->ptr;
	return q;
}

void quick_sort_recursive(int arr[], int down, int up)
{
	i++;
	if ((up == down) || (down > up))
	{
		return;
	}
	int ini_up = up;
	int ini_down = down;
	int num = arr[down];
	int to_put = down;
	int temp;
	while (down < up)
	{
		down++;
		while (arr[down] < num)
		{
			down++;
		}
		while (arr[up] > num)
		{
			up--;
		}
		if (down < up)
		{
			temp = arr[up];
			arr[up] = arr[down];
			arr[down] = temp;
		}
	}
	temp = arr[to_put];
	arr[to_put] = arr[up];
	arr[up] = temp;
	int up1 = ini_up;
	int down1 = up + 1;
	int up2 = up - 1;
	int down2 = ini_down;
	quick_sort_recursive(arr, down1, up1);
	quick_sort_recursive(arr, down2, up2);
}


void quick_sort(int arr[], int down_user, int up_user)
{
	if (up_user == down_user)
	{
		return;
	}
	struct node* head = NULL;
	push(&head, up_user, down_user);

	while (head)
	{
		struct node* up_down;
		up_down = pop(&head);
		int up = up_down->up;
		int down = up_down->down;
		int ini_up = up;
		int ini_down = down;
		int num = arr[down];
		int to_put = down;
		int temp;
		while (down < up)
		{
			down++;
			while (arr[down] < num)
			{
				down++;
			}
			while (arr[up] > num)
			{
				up--;
			}
			if (down < up)
			{
				temp = arr[up];
				arr[up] = arr[down];
				arr[down] = temp;
			}
		}
		temp = arr[to_put];
		arr[to_put] = arr[up];
		arr[up] = temp;
		int up1 = ini_up;
		int down1 = up + 1;
		int up2 = up - 1;
		int down2 = ini_down;
		if (down1 < up1)
			push(&head, up1, down1);
		if (down2 < up2)
			push(&head, up2, down2);
	}
}
int main()
{
	int* arr;
	int size;
	printf("Enter number of elements\n");
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int) * size);
	printf("Enter numbers:\n");
	if (arr)
	{
		for (int i = 0;i < size;i++)
		{
			scanf("%d", &arr[i]);
		}
	}
	//7, 9, 12, 25, 27, 31, 86, 92
	quick_sort(arr, 0, size-1);
	int index = 0;
	if (arr)
	{
		while(index<size)
		{
			printf("%d ", arr[index]);
			index++;
		}
	}
}