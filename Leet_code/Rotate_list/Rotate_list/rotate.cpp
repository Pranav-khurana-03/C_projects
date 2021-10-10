#include<iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* ref = head;
    struct ListNode* mv = head;
    for(int i = 0;i<=k;i++)
    {
        if(!ref)
        {
            k = k%i;
            i = 0;
            ref = head;
            continue;
        }
        ref = ref->next;
    }
    if(!ref || ref==head)
    {
        return head;
    }
    while(ref->next)
    {
        mv = mv->next;
        ref = ref->next;
    }
    struct ListNode* tmp = mv->next;
    mv->next = NULL;
    ref->next = head;
    head  = tmp;
    return head;
}
int main()
{
	ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* l3 = (ListNode*)malloc(sizeof(ListNode));
	l1->val = 1;
	//l2->val = 2;
	//l3->val = 2;
	l1->next = NULL;
	//l2->next = NULL;
	//l3->next = NULL;
	ListNode* tmp = rotateRight(l1, 0);
	while(tmp)
	{
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
}