#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int cameras;

bool min_cams(struct TreeNode* root)
{
    if(!root)
        return true;
    if(!min_cams(root->left) || !min_cams(root->right))
    {
        cameras++;
        return true;
    }
    return false;
}

int minCameraCover(struct TreeNode* root){
    cameras = 0;
    min_cams(root);
    return cameras;
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
    struct TreeNode* l8 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l9 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l10 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l11 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    l1->val = 1;l2->val = 2;l3->val = 3;l4->val = 4; l5->val = 5; l6->val = 6; l7->val = 7; l8->val = 8; l9->val = 9; l10->val = 10;l11->val = 11;
    l1->left = l2; l1->right = l3;
    l2->left = l4; l2->right = l5;
    l3->left = l6; l3->right = l7;
    l4->left = l8; l4->right = l9;
    l5->left = l10; l5->right =l11;
    minCameraCover(l1);
}