#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* prev = NULL, *cur = head, *next;
    for(int i = 1; i<left;i++)
    {
        prev = cur;
        cur = cur->next;
        next = cur;
    }
    for(int i = 0; i<=right-left; i++)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
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
    l1 = reverseBetween(l1, 2, 4);
    while(l1)
    {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
}