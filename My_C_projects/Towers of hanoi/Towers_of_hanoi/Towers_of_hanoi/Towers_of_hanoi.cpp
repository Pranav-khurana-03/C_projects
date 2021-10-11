#include<stdio.h>
#include<stdlib.h>
#define TOWER1 1
#define TOWER2 2
#define TOWER3 3

struct node
{
	int num;
	struct node* ptr;
};


int size_of_stack(struct node*head)
{
	int size = 0;
	while (head)
	{
		head = head->ptr;
		size++;
	}
	return size;
}

struct node* choose_stack(struct node*head, struct node*head1, struct node*head2, struct node* head3)
{
	if (head == head1)
	{
		if ((size_of_stack(head) % 2) == 0)
		{
			return head2;
		}
		else
		{
			return head3;
		}
	}
	else if (head == head2)
	{
		if ((size_of_stack(head) % 2) == 0)
		{
			return head1;
		}
		else
		{
			return head3;
		}
	}
	else
	{
		if ((size_of_stack(head) % 2) == 0)
		{
			return head1;
		}
		else
		{
			return head2;
		}
	}

}


void push(struct node** head, int data)
{
	struct node* item;
	item = (struct node*)malloc(sizeof(struct node));
	if (item)
	{
		item->num = data;
		item->ptr = NULL;
		if (*head)
		{
			item->ptr = (*head);
		}
		(*head) = item;
	}
}

void move_disc(struct node** src, struct node **aux, struct node** dest)
{
	if (!(*aux))
	{

	}
}

int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	int to_proceed = 1, temp;
	int i;
	while (to_proceed)
	{
		scanf_s("%d", &temp);
		push(&head1, temp);
		printf("To stop enter 0\n");
		scanf_s("%d", &to_proceed);
	}
	int size = size_of_stack(head1);
	printf("size is %d\n", size);
	struct node* temp_node = head1;
	while(temp_node)
	{
		printf("%d ", temp_node->num);
		temp_node = temp_node->ptr;
	}

}