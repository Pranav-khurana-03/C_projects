#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next; 
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (!head)
	{
		return head;
	}
	short int size = 0;
	struct ListNode* tmp = head, *tmp_head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (!(k % size))
	{
		return head;
	}
	int rotations = size - (k % size);
	tmp = head;
	for (size = 1; size < rotations; size++)
	{
		assert(tmp);
		tmp = tmp->next;
	}
	assert(tmp);
	tmp_head = tmp->next;
	tmp->next = NULL;
	tmp = tmp_head;
	assert(tmp_head);
	while (tmp_head->next)
	{
		tmp_head = tmp_head->next;
	}
	tmp_head->next = head;
	head = tmp;
	return head;
}


int main()
{
	int i = 0;
	struct ListNode* tmp, *prev = NULL, *head = NULL;
	scanf_s("%d", &i);
	while (i != -1)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (!tmp)
		{
			exit(-1);
		}
		tmp->val = i;
		tmp->next = NULL;
		if (!head)
		{
			head = tmp;
		}
		if (prev)
		{
			prev->next = tmp;
		}
		prev = tmp;
		scanf_s("%d", &i);
	}
	tmp = head;
	while (tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = rotateRight(head, 1);
	while (tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}