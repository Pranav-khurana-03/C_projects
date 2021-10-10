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
	int direction = 0;
	struct node* to_add;
	to_add = (struct node*)malloc(sizeof(struct node));
	assert(to_add);
	to_add->val = num;
	to_add->left = to_add->right = NULL;
	if (!(*root))
	{
		*root = to_add;
		return 1;
	}
	struct node* tmp = *root;
	struct node* prev = NULL;
	while (tmp)
	{
		if (tmp->val < num)
		{
			prev = tmp;
			tmp = tmp->right;
			direction = 1;
		}
		else if (tmp->val > num)
		{
			prev = tmp;
			tmp = tmp->left;
			direction = -1;
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
		else
		{
			prev->left = to_add;
		}
		return 1;
	}
	return 0;
}

void preorder(node* root)
{
	if (!root)
	{
		return;
	}
	printf("%d ", root->val);
	if (root->left)
	{
		preorder(root->left);
	}
	if (root->right)
	{
		preorder(root->right);
	}
}

void inorder_traversal(struct node* root)
{
	if (!root)
	{
		return;
	}
	if (root->left)
	{
		inorder_traversal(root->left);
	}
	printf("%d ", root->val);
	if (root->right)
	{
		inorder_traversal(root->right);
	}
}

int count = 1;

int inorder_smallest_num(struct node* root, int k)
{
	if (!root)
	{		
		return -1;
	}
	if (root->left)
	{
		int num_to_return = inorder_smallest_num(root->left, k);
		if (num_to_return != -1)
		{
			return num_to_return;
		}
	}
	if (count == k)
	{
		return root->val;
	}
	else
	{
		count++;
	}
	if (root->right)
	{
		int num_to_return = inorder_smallest_num(root->right, k);
		if (num_to_return != -1)
		{
			return num_to_return;
		}
	}
	return -1;
}


int main()
{
	struct node* root = NULL;
	int num;
	scanf_s("%d", &num);
	while (num!=-1)
	{
		add_node(&root, num);
		printf("\n");
		scanf_s("%d", &num);
	}
	preorder(root);
	printf("\n");
	inorder_traversal(root);
	printf("\n");
	num = 0;
	scanf_s("%d", &num);
	while (num != -1)
	{
		count = 1;
		printf("%d\n", inorder_smallest_num(root, num));
		scanf_s("%d", &num);
	}
}