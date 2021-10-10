#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


int prev;

bool validate(struct TreeNode* root){
    if(root->left){
        if(!validate(root->left))
            return false;
    }
    
    if(prev>root->val)
        return false;
    else
        prev = root->val;
    
    if(root->right){
        if(!validate(root->right))
            return false;
    }
    return true;
    
}

bool isValidBST(struct TreeNode* root){
    //prev = ;
    return validate(root);
}

int main()
{
    struct TreeNode* t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* t5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t1->val = 5;
    t2->val = 1;
    t3->val = 4;
    t4->val = 3;
    t5->val = 6;
    t1->left = t2;
    t1->right = t3;
    t2->left = t2->right = NULL;
    t3->left = t4;
    t3->right = t5;
    t4->left = t4->right = t5->right = t5->left = NULL;
    printf("%d", isValidBST(t1));
}