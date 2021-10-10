#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

int add_node(struct node** root, int num)
{
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	to_add->left = NULL;
	to_add->right = NULL;
	if (!*root)
	{
		*root = to_add;
		return 1;
	}
	struct node* tmp = *root;
	struct node* prev = NULL;
	int direction;
	while (tmp)
	{
		if ((tmp->val) > num)
		{
			tmp = tmp->left;
			prev = tmp;
			direction = -1;
		}
		else if ((tmp->val) < num)
		{
			tmp = tmp->right;
			prev = tmp;
			direction = 1;
		}
		else
		{
			return 0;
		}
	}
	if (prev)
	{
		if (direction == 1)
		{
			prev->right = to_add;
		}
		else if (direction == -1)
		{
			prev->left = to_add;
		}
		return 1;
	}
	return 0;
}


int main()
{

}