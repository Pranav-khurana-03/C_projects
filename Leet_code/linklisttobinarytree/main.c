#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int size;
int cur_size;


void insert_node(struct TreeNode** root, struct ListNode* num)
{
    cur_size++;
    struct TreeNode* to_add = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    to_add->val = num->val;
    to_add->left = to_add->right = NULL;
    if(!(*root)){
        *root = to_add;
        return;
    }
    struct TreeNode* tmp = *root;
    while(tmp)
    {
        if(tmp->val > to_add->val){
            if(!tmp->left){
                tmp->left = to_add;
                return;
            }
            else
                tmp = tmp->left;
        }
        else if(tmp->val < to_add->val){
            if(!tmp->right){
                tmp->right = to_add;
                return;
            }
            else
                tmp = tmp->right;
        }
    }
    
}

void middleNode(struct ListNode* head, struct ListNode* tail, struct TreeNode** root){
    if(size==cur_size)
        return;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;
    while((ptr2!=tail)&&(ptr2->next!=tail))
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    insert_node(root, ptr1);
    if(head!=ptr1)
        middleNode(head, ptr1, root);
    if(ptr1!=tail)
        middleNode(ptr1, tail, root);
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    struct TreeNode* root = NULL;
    struct ListNode* tmp = head;
    int i;
    while(tmp){
        tmp = tmp->next;
        i++;
    }
    size = i;
    cur_size = 0;
    middleNode(head, NULL, &root);
    return root;
}

void inorder(struct TreeNode* root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;l1->next = l2;
    l2->next = l3; l2->val = 2;
    l3->val = 3; l3->next = NULL;
    struct TreeNode* root = sortedListToBST(l1);
    inorder(root);
}