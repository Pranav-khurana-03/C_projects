#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int ancestor = 0;
int status = 0;

struct node {
	int val;
	struct node* left;
	struct node* right;
};

int add_node(node** root, int num)
{
	static int direction = 0;
	if (!*root)
	{
		node* to_add;
		to_add = (node*)malloc(sizeof(node));
		assert(to_add);
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
	else if (direction == 2)
	{
		if (add_node((&(tmp->right)), num))
		{
			return 1;
		}
	}
	return 0;
}

void inorder(node* root)
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

struct node* find_kth_ancestor(struct node*root, int node, int ancest)
{
	if (!root)
	{
		return NULL;
	}
	if (node > root->val)
	{
		if (root->right)
		{
			struct node* ancestor_to_return = find_kth_ancestor(root->right, node, ancest);
			if (ancestor_to_return)
			{
				return ancestor_to_return;
			}
			else
			{
				if (ancestor == ancest)
				{
					return root;
				}
				ancestor++;
				return NULL;
			}
		}
		else
		{
			status = 1;
			return NULL;
		}
	}
	else if (node < root->val)
	{
		if (root->left)
		{
			struct node* ancestor_to_return = find_kth_ancestor(root->left, node, ancest);
			if (ancestor_to_return)
			{
				return ancestor_to_return;
			}
			else
			{
				if (ancestor == ancest)
				{
					return root;
				}
				ancestor++;
				return NULL;
			}
		}
		else
		{
			status = 1;
			return NULL;
		}
	}
	else
	{
		if (ancestor == ancest)
		{
			return root;
		}
		ancestor++;
		return NULL;
	}
}


int main()
{
	struct node* root = NULL;
	while (1)
	{
		int num;
		scanf_s("%d", &num);
		if (num == -1)
		{
			break;
		}
		add_node(&root, num);
	}
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	while (1)
	{
		int num;
		printf("Enter number: ");
		scanf_s("%d", &num);
		int ancestor_main;
		printf("Enter ancestor: ");
		scanf_s("%d", &ancestor_main);
		ancestor = 0;
		struct node* ptr_ancest = find_kth_ancestor(root, num, ancestor_main);
		status = 0;
		if ((ptr_ancest)&&(!status))
		{
			printf("%d ", ptr_ancest->val);
		}
		else if(status)
		{
			printf("Not found!\n");
		}
		else
		{
			printf("No Ancestor\n");
		}
		printf("\n");
	}
}