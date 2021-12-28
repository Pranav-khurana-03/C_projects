#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct treenode
{
	int val;
	struct treenode *right;
	struct treenode *left;
};

struct qnode
{
	int level;
	struct treenode *ptr;
	struct qnode *next;
	struct qnode *prev;
};

void enqueue(struct qnode **rear, struct qnode **front, struct treenode *node, int level)
{
	struct qnode *to_add;
	to_add = (struct qnode *)malloc(sizeof(struct qnode));
	to_add->ptr = node;
	to_add->next = NULL;
	to_add->prev = NULL;
	to_add->level = level;
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

int dequeue(struct qnode **rear, struct qnode **front)
{
	if (!(*front))
	{
		return 1;
	}
	struct qnode *tmp = *front;
	if ((*front) == (*rear))
	{
		*front = *rear = NULL;
		return 1;
	}
	else
	{
		*front = (*front)->next;
	}
	free(tmp);
	return 0;
}

int add_node(struct treenode **root, int num)
{
	int direction = 0;
	struct treenode *to_add;
	to_add = (struct treenode *)malloc(sizeof(struct treenode));
	assert(to_add);
	to_add->val = num;
	to_add->left = to_add->right = NULL;
	if (!(*root))
	{
		*root = to_add;
		return 1;
	}
	struct treenode *tmp = *root;
	struct treenode *prev = NULL;
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

void inorder(struct treenode *root)
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

void preorder(struct treenode *root)

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

void breadth_first_search(struct treenode *root)
{
	int lvl = 0;
	int index = 0;
	if (!root)
		return;
	struct qnode *front = NULL;
	struct qnode *rear = NULL;
	printf("%d %d\n", root->val, lvl);
	enqueue(&rear, &front, root->left, lvl + 1);
	enqueue(&rear, &front, root->right, lvl + 1);
	while (rear)
	{
		lvl = front->level;
		printf("%d %d\n", front->ptr->val, lvl);
		if (front->ptr->left)
		{
			enqueue(&rear, &front, front->ptr->left, lvl + 1);
		}
		if (front->ptr->right)
		{
			enqueue(&rear, &front, front->ptr->right, lvl + 1);
		}
		dequeue(&rear, &front);
	}
}

void zigzag_traversal(struct treenode *root)
{
	int lvl = 0;
	int index = 0;
	if (!root)
		return;
	struct qnode *front = NULL;
	struct qnode *rear = NULL;
	printf("%d %d\n", root->val, lvl);
	enqueue(&rear, &front, root->left, lvl + 1);
	enqueue(&rear, &front, root->right, lvl + 1);
	while (rear)
	{
		struct qnode *tmp;
		lvl = rear->level;
		tmp = rear;
		while (tmp)
		{
			if (lvl % 2 == 0)
			{
				if (tmp->ptr->left)
				{
					enqueue(&rear, &front, tmp->ptr->left, lvl + 1);
				}
				if (tmp->ptr->right)
				{
					enqueue(&rear, &front, tmp->ptr->right, lvl + 1);
				}
			}
			else
			{
				if (tmp->ptr->right)
				{
					enqueue(&rear, &front, tmp->ptr->right, lvl + 1);
				}
				if (tmp->ptr->left)
				{
					enqueue(&rear, &front, tmp->ptr->left, lvl + 1);
				}
			}
			tmp = tmp->prev;
		}
		lvl = front->level;
		while (lvl == front->level)
		{
			printf("%d %d\n", front->ptr->val, front->level);
			if(dequeue(&rear, &front))
				return;
		}
	}
}

int main()
{
	int arr[1024];
	struct treenode *root = NULL;
	int num;
	scanf("%d", &num);
	while (num != -1)
	{
		add_node(&root, num);
		printf("Inorder: ");
		inorder(root);
		printf("\n");
		printf("Preorder: ");
		preorder(root);
		printf("\n");
		scanf("%d", &num);
	}
	printf("Level order: ");
	breadth_first_search(root);
	printf("\n");
	printf("Zigzag: ");
	zigzag_traversal(root);
	printf("\n");
}