#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_balanced;

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int inorder(struct TreeNode* root, int depth)
{
    if(!root)
        return depth-1;
    int left = inorder(root->left, depth+1);
    int right = inorder(root->right, depth+1);
    if(abs(left-right)>1)
        is_balanced = false;
    if(left||right)
        return max(left, right);
    else
        return depth;
}


bool isBalanced(struct TreeNode* root){
    is_balanced = true;
    inorder(root, 0);
    return is_balanced;
}

int main()
{
    struct TreeNode* l1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l6 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l7 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    l1->val = 1;l2->val=2;l3->val=3;l4->val=4;l5->val=5;l6->val=6;l7->val=8;
    l1->left = l2;l1->right=l3;
    l2->left = l4;l2->right = l5;
    l4->left = l7;
    l3->left = l6;
    printf("%d", isBalanced(l1));
}