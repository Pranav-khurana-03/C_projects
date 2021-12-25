#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

void add_node(struct ListNode** head, int num)
{
	struct ListNode* to_add = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(to_add);
	to_add->val = num;
	to_add->next = NULL;
	if (!(*head))
	{
		*head = to_add;
		return;
	}
	struct ListNode* tmp;
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = to_add;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//int sum = 0;
	short int carry = 0;
	struct ListNode* tmp, * prev, * head;
	tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(tmp);
	tmp->val = ((l2->val) + (l1->val));
	if ((tmp->val) > 9)
	{
		carry = tmp->val / 10;
		tmp->val = tmp->val % 10;
	}
	tmp->next = NULL;
	prev = tmp;
	head = tmp;
	l1 = l1->next;
	l2 = l2->next;
	while ((l1) && (l2))
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		assert(tmp);
		tmp->val = ((l2->val) + (l1->val)) + carry;
		carry = 0;
		if ((tmp->val) > 9)
		{
			carry = (tmp->val) / 10;
			tmp->val = (tmp->val) % 10;
		}
		tmp->next = NULL;
		prev->next = tmp;
		prev = tmp;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		assert(tmp);
		tmp->val = l1->val + carry;
		carry = 0;
		if ((tmp->val) > 9)
		{
			carry = (tmp->val) / 10;
			tmp->val = (tmp->val) % 10;
		}
		tmp->next = NULL;
		prev->next = tmp;
		prev = tmp;
		l1 = l1->next;
	}
	while (l2)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		assert(tmp);
		tmp->val = l2->val + carry;
		carry = 0;
		if ((tmp->val) > 9)
		{
			carry = (tmp->val) / 10;
			tmp->val = (tmp->val) % 10;
		}
		tmp->next = NULL;
		prev->next = tmp;
		prev = tmp;
		l2 = l2->next;
	}
	if (carry)
	{
		tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		assert(tmp);
		tmp->val = carry;
		tmp->next = NULL;
		prev->next = tmp;
	}
	return head;
}


int main()
{
	struct ListNode* head1 = NULL;
	struct ListNode* head2 = NULL;
	int num = 0;
	printf("For list 1: \n");
	scanf("%d", &num);
	while (num != -1)
	{
		add_node(&head1, num);
		scanf("%d", &num);
	}
	printf("For list 2: \n");

	scanf("%d", &num);
	while (num != -1)
	{
		add_node(&head2, num);
		scanf("%d", &num);
	}
	printf("\n");
	struct ListNode* result = addTwoNumbers(head1, head2);
	while (result)
	{
		printf("%d ", result->val);
		result = result->next;
	}

}
