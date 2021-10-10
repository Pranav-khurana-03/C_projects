#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* prev;
int max_sum;



int validate_and_get_sum(struct TreeNode* root, bool* is_valid)
{
    if(!root)
        return 0;
    bool valid = true;
    int left = validate_and_get_sum(root->left, &valid);
    if(!valid)
        *is_valid = false;
        
    if(!prev)
        prev = root;
    else if(prev->val >= root->val)
        *is_valid = false;
    
    prev = root;
    int right = validate_and_get_sum(root->right, &valid);
    if(!valid)
        *is_valid = false;
    if(!*is_valid)
        return 0;
    int sum = root->val + left + right;
    if(sum>max_sum)
        max_sum = sum;
    return sum;
}



int maxSumBST(struct TreeNode* root){
    prev = NULL;
    max_sum = INT_MIN;
    bool is_valid = true;
    validate_and_get_sum(root, &is_valid);
    return max_sum;
}

int main()
{
    struct TreeNode* l1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* l4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    l1->left = l2; l1->val = 4;
    l2->left = l3; l2->val = 3;
    l2->right = l4; l3->val = 1;
    l4->val = 2;
    printf("%d", maxSumBST(l1));
}