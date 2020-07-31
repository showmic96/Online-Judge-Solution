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
    int f(TreeNode* p , TreeNode* q){
        if(p==NULL&&q==NULL)return 1;
        if(p==NULL&&q!=NULL)return 0;
        if(p!=NULL&&q==NULL)return 0;
        if(p->val!=q->val)return 0;
        int val = 1;
        if(p->left!=NULL){
            if(q->left==NULL)return 0;
            val = min(val, f(p->left , q->left));
        }
        else{
            if(q->left!=NULL)return 0;
        }
        if(p->right!=NULL){
            if(q->right==NULL)return 0;
            val = min(val, f(p->right , q->right));
        }
        else{
            if(q->right!=NULL)return 0;
        }
        return val;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p , q);
    }
};
