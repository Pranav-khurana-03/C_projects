#include<stdio.h>
#include<stdlib.h>


struct ListNode{
	int val;
	struct ListNode* next;
};

void add_node(struct ListNode** head, int num)
{
	struct ListNode* to_add = (struct ListNode*)malloc(sizeof(struct ListNode));
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

struct ListNode* mergeTwoLists_old(struct ListNode* l1, struct ListNode* l2){
    if(!l1)
    {
        return l2;
    }
    if(!l2)
    {
        return l1;
    }
    struct ListNode* ini_l2 = l2;
    while(l1)
    {
        if((l1->val)<(ini_l2->val))
        {
            struct ListNode*tmp = l1;
            l1 = l1->next;
            tmp->next = ini_l2;
			ini_l2 = tmp;
            l2 = tmp;
            continue;
        }
        while(l2->next)
        {
            if((l2->next->val)>(l1->val))
            {
                break;
            }
            l2 = l2->next;
        }
        struct ListNode*tmp1 = l2->next;
        struct ListNode*tmp2 = l1->next;
        l2->next = l1;
        l1->next = tmp1;
        l1 = tmp2;
    }
    return ini_l2;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    struct ListNode* tmp, *prev = NULL;
    /*if(l1->val > l2->val)
    {
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }*/
    tmp = l1;
    while(l2 && tmp)
    {
        if(tmp->val >= l2->val)
        {
            struct ListNode* t;
            if(!prev)
            {
                t = l1;;
                l1 = l2;
                l2 = l2->next;
                l1->next = t;
                tmp = l1;
            }
            else
            {
                t = l2->next;;
                prev->next = l2;
                l2->next = tmp;
                l2 = t;
                prev = prev->next;
            }
            //prev = tmp;
            continue;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if(!tmp->next)
        tmp->next = l2;
    return l1;
}


int main()
{
	struct ListNode* head1 = NULL;
	struct ListNode* head2 = NULL;
	int i;
	printf("List1: ");
	scanf("%d", &i);
	while (i!=0)
	{
		add_node(&head1, i);
		scanf("%d", &i);
	}
	printf("List2: ");
	scanf("%d", &i);
	while (i!=0)
	{
		add_node(&head2, i);
		scanf("%d", &i);
	}
	struct ListNode*tmp = head1;
	while(tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = head2;
	while(tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = mergeTwoLists(head1, head2);
	while(tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}