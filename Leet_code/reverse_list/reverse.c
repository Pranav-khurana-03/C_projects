#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev, *cur, *next;
    prev = NULL;
    cur = head;
    next = cur->next;
    while(next)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    head = cur;
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
    l1 = reverseList(l1);
    while(l1)
    {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
}