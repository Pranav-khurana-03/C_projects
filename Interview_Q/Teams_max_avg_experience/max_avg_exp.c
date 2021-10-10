#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

struct qnode{
	struct node* ptr;
	struct qnode* next;
};

struct node_to_return
{
	double sum;
	int nodes;
};



void enqueue(struct qnode **rear, struct qnode **front, struct node *treenode)
{
	struct qnode *to_add;
	to_add = (struct qnode *)malloc(sizeof(struct qnode));
	to_add->ptr = treenode;
	to_add->next = NULL;
	if (!(*rear))
	{
		*front = to_add;
		*rear = to_add;
		return;
	}
	(*rear)->next = to_add;
	*rear = to_add;
}

void add_node_level_order(struct node** root, int num)
{
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	to_add->left = NULL;
	to_add->right = NULL;
	to_add->val = num;
	if(!(*root))
	{
		*root = to_add;
		return;
	}
	if(!((*root)->left))
	{
		(*root)->left = to_add;
		return;
	}
	if(!((*root)->right))
	{
		(*root)->right = to_add;
		return;
	}
	struct qnode* front = NULL;
	struct qnode* rear = NULL;
	enqueue(&rear, &front, (*root)->left);
	enqueue(&rear, &front, (*root)->right);
	while(1)
	{
		struct node* father = dequeue(&rear, &front);
		if(father->left)
		{
			enqueue(&rear, &front, father->left);
		}
		else
		{
			father->left = to_add;
			break;
		}
		if(father->right)
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

double avg = 0;

struct node_to_return* inorder_traversal_avg_exp(struct node* root)
{
	double sum = 0;
	int nodes=0;
	struct node_to_return* ptr;
	if(!root)
	{
		return NULL;
	}
	nodes++;
	if(root->left)
	{
		ptr = inorder_traversal_avg_exp(root->left);
		sum += ptr->sum;
		nodes+= ptr->nodes;
	}
	if(root->right)
	{
		ptr = inorder_traversal_avg_exp(root->right);
		sum += ptr->sum;
		nodes+=ptr->nodes ;
	}
	sum += root->val;
	printf("Pos:%d\t\tSum: %f\t\tNodes: %d\t\tAvg: %f\n", root->val, sum, nodes, sum/nodes);
	if((sum/nodes)>avg)
	{
		avg = sum/nodes;
	}
	ptr = (struct node_to_return*)malloc(sizeof(struct node_to_return));
	ptr->nodes = nodes;
	ptr->sum = sum;
	return ptr;
}

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	if(root->left)
	{
		inorder(root->left);
	}
	printf("%d ", root->val);
	if(root->right)
	{
		inorder(root->right);
	}
}

int main()
{
	struct node* root = NULL;
	int num;
	scanf("%d", &num);
	while(num!=-1)
	{
		add_node_level_order(&root, num);
		inorder(root);
		printf("\n");
		scanf("%d", &num);
	}
	inorder_traversal_avg_exp(root);
	printf("%f", avg);
}