#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct node {
	int val;
	struct node* ptr;
};

void show_linklist(struct node** root_list, int size)
{
	int i;
	struct node* root;
	for (i = 0;i < size;i++)
	{
		root = root_list[i];
		while (root)
		{
			printf("%d ", root->val);
			root = root->ptr;
		}
		printf("\n");
	}
}

void add_node_sorted_order(struct node** root, struct node* to_add)
{
	if(!*root)
	{
		*root = to_add;
		return;
	}
	int num = to_add->val;
	struct node* tmp = *root;
	if ((tmp->val) > num)
	{
		*root = to_add;
		to_add->ptr = tmp;
		return;
	}
	while (tmp->ptr)
	{
		if ((tmp->ptr->val) > num)
		{
			to_add->ptr = tmp->ptr;
			break;
		}
		tmp = tmp->ptr;
	}
	tmp->ptr = to_add;
}

struct node* find_smallest_node(struct node**root_list, int size, int*index)
{
	struct node* smallest = NULL;
	for (int i = 1;i < size;i++)
	{
		if (root_list[i])
		{
			if (smallest)
			{
				if ((root_list[i]->val) <= smallest->val)
				{
					smallest = root_list[i];
					*index = i;
				}
			}
			else
			{
				smallest = root_list[i];
				*index = i;

			}

		}
	}
	return smallest;
}

struct node* merge_k_lists(struct node**lists, int listsSize)
{
	int to_break = 0;
	int i;
	int index;
	if (listsSize == 1)
	{
		return lists[1];
	}
	while (1)
	{
		for (i = 1;i <listsSize;i++)
		{
			struct node* node_ptr = find_smallest_node(lists, listsSize, &index);
			if (!node_ptr)
			{
				to_break = 1;
				break;
			}
			lists[index] = lists[index]->ptr;
			node_ptr->ptr = NULL;
			add_node_sorted_order(&lists[0], node_ptr);

		}
		if (to_break)
		{
			break;
		}
	}
	return lists[0];
}


int main()
{
	struct node** list_arr;
	int size, i;
	scanf("%d", &size);
	list_arr = (struct node**)malloc(sizeof(struct node*));
	assert(list_arr);
	memset(list_arr, 0, (sizeof(struct node*) * size));
	for (i = 0;i < size;i++)
	{
		int tmp;
		printf("Enter numbers for list %d: ", i + 1);
		scanf("%d", &tmp);
		while (tmp != -1)
		{
			struct node* to_add = (struct node*)malloc(sizeof(struct node));
			assert(to_add);
			to_add->ptr = NULL;
			to_add->val = tmp;
			add_node_sorted_order(&list_arr[i], to_add);
			scanf("%d", &tmp);
		}
	}
	show_linklist(list_arr, size);
	struct node* head = merge_k_lists(list_arr, size);
	struct node* tmp = head;
	while (tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->ptr;
	}
	printf("\n");
}
