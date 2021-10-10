#include<stdio.h>
#include<stdlib.h>

typedef struct HeapNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}heapnode;

typedef struct qnode
{
    struct TreeNode* ptr;
    struct qnode* next;
}qnode;

qnode* head = NULL, *tail = NULL;
heapnode* root = NULL;

void add_heapnode(int num)
{
    heapnode* to_add = (heapnode*)malloc(sizeof(heapnode));
    to_add->val = num;
    to_add->right = NULL;
    to_add->left = NULL;
    heapnode* tmp = root;
    //if()
}


void enqueue(heapnode* val)
{
    qnode* to_add = (qnode*)malloc(sizeof(qnode));
    to_add->ptr = val;
    to_add->next = NULL;
    if(!tail)
    {
        tail = to_add;
        head = to_add;
        return;
    }
    tail->next = to_add;
}

void dequeue()
{
    if(!head){
        return;
    }
    qnode* tmp = head;
    head = head->next;
    free(tmp);
}

void show_tree()
{
    if(!root){
        return;
    }
    printf("%d", root->val);
    heapnode* tmp = root;
    while(tmp->left || tmp->right)
    {
        if(tmp->left){
            enqueue(tmp->left);
        }
        if(tmp->right){
            enqueue(tmp->right);
        }
        tmp = head->ptr;
        printf("%d ", tmp->val);
    }
}


int main()
{

}