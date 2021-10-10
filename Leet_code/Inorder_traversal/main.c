#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *right;
	struct TreeNode *left;
} TreeNode;

int index_arr;

struct qnode
{
	int level;
	struct TreeNode *ptr;
	struct qnode *next;
	struct qnode *prev;
};

void enqueue(struct qnode **rear, struct qnode **front, struct TreeNode *TreeNode)
{
	struct qnode *to_add;
	to_add = (struct qnode *)malloc(sizeof(struct qnode));
	to_add->ptr = TreeNode;
	to_add->next = NULL;
	to_add->prev = NULL;
	if (!(*rear))
	{
		*front = to_add;
		*rear = to_add;
		return;
	}
	(*rear)->next = to_add;
	to_add->prev = *rear;
	*rear = to_add;
}

struct TreeNode *dequeue(struct qnode **rear, struct qnode **front)
{
	if (!(*front))
	{
		return NULL;
	}
	struct qnode *tmp = *front;
	if ((*front) == (*rear))
	{
		*front = *rear = NULL;
		return NULL;
	}
	else
	{
		*front = (*front)->next;
	}
	struct TreeNode *to_return = tmp->ptr;
	free(tmp);
	return to_return;
}

void add_node_level_order(struct TreeNode **root, int num)
{
	struct TreeNode *to_add = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	to_add->left = NULL;
	to_add->right = NULL;
	to_add->val = num;
	if (!(*root))
	{
		*root = to_add;
		return;
	}
	if (!((*root)->left))
	{
		(*root)->left = to_add;
		return;
	}
	if (!((*root)->right))
	{
		(*root)->right = to_add;
		return;
	}
	struct qnode *front = NULL;
	struct qnode *rear = NULL;
	enqueue(&rear, &front, (*root)->left);
	enqueue(&rear, &front, (*root)->right);
	while (1)
	{
		TreeNode *father = dequeue(&rear, &front);
		if (father->left)
		{
			enqueue(&rear, &front, father->left);
		}
		else
		{
			father->left = to_add;
			break;
		}
		if (father->right)
		{
			enqueue(&rear, &front, father->right);
		}
		else
		{
			father->right = to_add;
			break;
		}
	}
}

int *traverse_inorder(TreeNode *root, int *arr, int *size)
{
	if (!root)
	{
		return NULL;
	}
	traverse_inorder(root->left, arr, size);
	if (index_arr == (*size))
	{
		(*size)++;
		arr = realloc(arr, sizeof(int) * (*size));
	}
	arr[index_arr++] = root->val;
	traverse_inorder(root->right, arr, size);
	return arr;
}

int *inordertraversal(TreeNode *root, int *returnsize)
{
	index_arr = 0;
	int size = 1;
	int *arr = (int *)malloc(sizeof(int) * size);
	arr = traverse_inorder(root, arr, &size);
	*returnsize = size;
	return arr;
}

void inorder_print_traversal(TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder_print_traversal(root->left);
	printf("%d ", root->val);
	inorder_print_traversal(root->right);
}

int main()
{
	struct TreeNode *root = NULL;
	int n;
	scanf("%d", &n);
	int size;
	while (n != -1)
	{
		add_node_level_order(&root, n);
		inorder_print_traversal(root);
		printf("\n");
		scanf("%d", &n);
	}
	int *result = inordertraversal(root, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n%d", size);
}