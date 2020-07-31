/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root , int now = 0) {
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL){
            if(now==1)return root->val;
            return 0;
        }
        else if(root->left==NULL)return sumOfLeftLeaves(root->right);
        else if(root->right==NULL)return sumOfLeftLeaves(root->left, 1);
        else return sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right);
    }
};
