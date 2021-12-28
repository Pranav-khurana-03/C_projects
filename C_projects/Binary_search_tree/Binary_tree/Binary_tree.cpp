#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

int add_node(node**root, int num)
{
	static int direction = 0;
	if (!*root)
	{
		node* to_add;
		to_add = (node*)malloc(sizeof(node));
		if (!to_add)
		{
			exit(-1);
		}
		to_add->val = num;
		to_add->left = to_add->right = NULL;
		*root = to_add;

		return 1;
	}
	node* tmp = *root;
	if (((*root)->val) > num)
	{
		direction = 1;
	}
	else if (((*root)->val) < num)
	{
		direction = 2;
	}
	else
	{
		return 0;
	}
	if (direction == 1)
	{
		if (add_node((&(tmp->left)), num))
		{
			return 1;
		}
	}
	else if(direction ==2)
	{
		if (add_node((&(tmp->right)), num))
		{
			return 1;
		}
	}
	return 0;
}

struct node* find_node(node* root, int num)
{
	if (!root)
	{
		return NULL;
	}
	if ((root->val) > num)
	{
		root = root->left;
	}
	else if ((root->val) < num)
	{
		root = root->right;
	}
	else
	{
		return root;
	}
	if (find_node(root, num))
	{
		return NULL;
	}
	return NULL;
}

int delete_node(node**ini_root, int node)
{
	struct node* root = *ini_root, *father = NULL;
	if (!root)
	{
		return 0;
	}
	int direction = 0, deleted = 0;
	while (root)
	{
		if ((root->val) < node)
		{
			father = root;
			root = root->right;
			direction = 1;
		}
		else if ((root->val) > node)
		{
			father = root;
			root = root->left;
			direction = -1;
		}
		else
		{
			if (!father)
			{
				*ini_root = NULL;
			}
			if ((root->left) && (root->right))
			{
				struct node* tmp = root->right, *prev = NULL;
				int node_present = 0;
				while (tmp->left)
				{
					prev = tmp;
					tmp = tmp->left;
					node_present = 1;
				}
				if (direction == 1)
				{
					father->right = tmp;
				}
				else if (direction == -1)
				{
					father->left = tmp;
				}
				else
				{
					*ini_root = tmp;
				}
				tmp->left = root->left;
				if (node_present)
				{
					prev->left = tmp->right;
					tmp->right = root->right;
				}
				free(root);
				root = NULL;
			}
			else if (root->left)
			{
				if (direction == 1)
				{
					father->right = root->left;
				}
				else if (direction == -1)
				{
					father->left = root->left;
				}
				else
				{
					*ini_root = root->left;
				}
				free(root);
				root = NULL;
			}
			else if (root->right)
			{
				if (direction == 1)
				{
					father->right = root->right;
				}
				else if (direction == -1)
				{
					father->left = root->right;
				}
				else
				{
					*ini_root = root->right;
				}
				free(root);
				root = NULL;
			}
			else
			{
				if (direction == 1)
				{
					father->right = NULL;
				}
				else if (direction == -1)
				{
					father->left = NULL;
				}
				free(root);
				root = NULL;
			}
			deleted = 1;
		}

	}
	if (deleted)
	{
		return 1;
	}
	return 0;
}

void inorder(node*root)
{
	if (!root)
	{
		return;
	}
	if (root->left)
	{
		inorder(root->left);
	}
	printf("%d ", root->val);
	if (root->right)
	{
		inorder(root->right);
	}
}

void postorder(node* root)
{
	if (!root)
	{
		return;
	}
	if (root->left)
	{
		postorder(root->left);
	}
	if (root->right)
	{
		postorder(root->right);
	}
	printf("%d ", root->val);
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

int main()
{
	node* root = NULL;
	int do_what;
	int i = 0;
	scanf_s("%d", &i);
	while (i != -1)
	{
		if (!add_node(&root, i))
		{
			printf("Duplicate!!\n");
		}
		scanf_s("%d", &i);
	}
	while (1)
	{
		printf("To add: 1\nTo find: 2\nTo delete: 3\nTo print: 4\nTo exit: -1\n");
		scanf_s("%d", &do_what);
		int num;
		switch (do_what)
		{
		case 1:
		{
			printf("Enter a number: ");
			scanf_s("%d", &num);
			if (!add_node(&root, num))
			{
				printf("Duplicate\n");
			}
			break;
		}
		case 2:
		{
			printf("Enter a number: ");
			scanf_s("%d", &num);
			if (find_node(root, num))
			{
				printf("Found\n");
			}
			else
			{
				printf("Not found\n");
			}
			break;
		}
		case 3:
		{
			printf("Enter a number: ");
			scanf_s("%d", &num);
			if (delete_node(&root, num))
			{
				printf("Deleted!!!\n");
			}
			else
			{
				printf("Not found!!!\n");
			}
			break;
		}
		case 4:
		{
			int i = 1;
			while (i)
			{
				i = 0;
				printf("Preorder: 1\nPostorder: 2\nInorder: 3\n");
				scanf_s("%d", &num);
				switch (num)
				{
				case 1:
				{
					preorder(root);
					printf("\n");
					break;
				}
				case 2:
				{
					postorder(root);
					printf("\n");
					break;
				}
				case 3:
				{
					inorder(root);
					printf("\n");
					break;
				}
				default:
					i = 1;
				}
			}
			break;
		}
		case -1:
		{
			exit(0);
			break;
		}
		default:
			break;
		}
	}
}