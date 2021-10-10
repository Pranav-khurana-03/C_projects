#include<bits/stdc++.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//check if code works fine without global variable
int maximum_sum;

int max_path_sum(struct TreeNode* root)
{
    int left_sum = 0, right_sum = 0;
    int sum_to_return = 0;
    if(root->left){
        left_sum = max_path_sum(root->left);
    }
    if(root->right){
        right_sum = max_path_sum(root->right);
    }
    if((root->val + left_sum + right_sum) > maximum_sum)
        maximum_sum = root->val + left_sum + right_sum;
    if(right_sum>left_sum){
        sum_to_return = right_sum + root->val;
    }
    else{
        sum_to_return = root->val+left_sum;
    }
    if(sum_to_return<0)
        return 0;
    else
        return sum_to_return;
}


int maxPathSum(struct TreeNode* root){
    maximum_sum = 0;
    max_path_sum(root);
    return maximum_sum;
}