#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int min_depth;

void inorder(struct TreeNode* root, int depth)
{
    bool child = false;
    depth++;
    if(root->left)
    {
        child = true;
        inorder(root->left, depth);
    }
    if(root->right)
    {
        child = true;
        inorder(root->right, depth);
    }
    if((!child) && depth<min_depth)
        min_depth = depth;
}


int minDepth(struct TreeNode* root){
    min_depth = 0;
    inorder(root, 0);
    return min_depth;
}

int main()
{
    struct TreeNode* t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->right = t2;
    t2->right = t3;
    t3->right = t4;
    t4->right = t5;
    t1->val = 1;
    t2->val = 2;
    t3->val = 3;
    t4->val = 4;
    t5->val = 5;
    t1->left = t2->left = t3->left = t4->left = t5->left = NULL;
    printf("%d", minDepth(t1));
}