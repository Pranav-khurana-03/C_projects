#include<stdio.h>
#include<stdlib.h>

//Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* swapNodes(struct ListNode* head, int k){
    if(!(head && head->next))
        return head;
    struct ListNode* tmp, *k_head, *k_tail;
    tmp = head;
    for(int i = 0; i<(k-1) ;i++)
    {
        tmp = tmp->next;
    }
    k_head = tmp;
    k_tail = head;
	tmp = tmp->next;
    while(tmp->next->next)
    {
        tmp = tmp->next;
        k_tail = k_tail->next;
    }
    if(k==1)
    {
        while(k_tail->next->next)
        {
            k_tail = k_tail->next;
        }
        k_tail->next->next = head;
        head = k_tail->next;
        k_tail->next = NULL;
    }
    else
    {
        struct ListNode* swap = k_tail->next;
        struct ListNode* swap2 = k_tail->next->next;
        k_tail->next = k_head->next;
        k_head->next = swap;
        swap->next = k_tail->next->next;
        k_tail->next->next = swap2;
    }
    return head;
}


int main()
{
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 1;
	l2->val = 2;
	l3->val = 3;
	l4->val = 4;
	l5->val = 5;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = NULL;
	l1 = swapNodes(l1, 2);
	while(l1)
	{
		printf("%d ", l1->val);
		l1 = l1->next;
	}
}