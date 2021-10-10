#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
	int val;
	struct node* ptr;
};

void add_node(struct node** root, int num)
{
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	assert(to_add);
	to_add->val = num;
	to_add->ptr = NULL;
	if (!(*root))
	{
		*root = to_add;
		return;
	}
	struct node* tmp;
	tmp = *root;
	while (tmp->ptr)
	{
		tmp = tmp->ptr;
	}
	tmp->ptr = to_add;
}

void show_linklist(struct node* root)
{
	while (root)
	{
		printf("%d ", root->val);
		root = root->ptr;
	}
	printf("\n");
}

void show_linklist_reverse(struct node*root)
{
	if (!root)
	{
		return;
	}
	show_linklist_reverse(root->ptr);
	printf("%d ", root->val);
}

int main()
{
	int num;
	scanf_s("%d", &num);
	struct node* root = NULL;
	while (num != -1)
	{
		add_node(&root, num);
		scanf_s("%d", &num);
	}
	show_linklist(root);
	show_linklist_reverse(root);
}