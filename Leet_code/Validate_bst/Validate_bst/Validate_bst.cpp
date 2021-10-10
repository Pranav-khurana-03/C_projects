#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int prev = -2147483648;
bool extent = false;
struct node
{
	int val;
	struct node* left;
	struct node* right;
};

int inorder_check(struct node*);


int add_node(node** ini_root, int num)
{
	static int i = 0;
	struct node* root = *ini_root;
	node* to_add;
	to_add = (node*)malloc(sizeof(node));
	assert(to_add);
	to_add->left = NULL;
	to_add->right = NULL;
	to_add->val = num;
	if (!root)
	{
		if (!to_add)
		{
			exit(-1);
		}
		*ini_root = to_add;
		return 1;
	}
	while (1)
	{
		if (!root->right)
		{
			root->right = to_add;
			break;
		}
		else if (!root->left)
		{
			root->left = to_add;
			break;
		}
		else
		{
			if ((i % 2) == 0)
			{
				root = root->left;
			}
			else
			{
				root = root->right;
			}
			i++;
		}
	}
	return 1;
}

bool isValidBST(struct node* root) {
	extent = false;
	prev = -2147483648;
	if (inorder_check(root))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void inorder(struct node* root)
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

int inorder_check(struct node* root)
{
	if (!root)
	{
		return 1;
	}
	if (root->left)
	{
		if (!inorder_check(root->left))
		{
			return 0;
		}
	}
	if ((root->val) <= prev)
	{
		if ((prev == -2147483648) && (!extent))
		{
			extent = true;
		}
		else
		{
			return 0;
		}
	}
	prev = root->val;
	if (root->right)
	{
		if (!inorder_check(root->right))
		{
			return 0;
		}
	}
	return 1;
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
	int prev = -2147483648;
	printf("%d", prev);
	int num;
	scanf_s("%d", &num);
	while (1)
	{
		struct node* root = NULL;
		while (num != -1)
		{
			add_node(&root, num);
			scanf_s("%d", &num);
		}
		printf("Inorder: ");inorder(root);printf("\n");
		printf("Postorder: ");postorder(root);printf("\n");
		printf("Preorder: ");preorder(root);printf("\n");
		printf("%d", isValidBST(root));
		printf("\n");
		scanf_s("%d", &num);
	}
}