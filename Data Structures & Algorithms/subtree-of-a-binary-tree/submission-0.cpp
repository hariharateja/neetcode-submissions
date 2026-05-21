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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(!p && q){
            return false;
        }
        if(p && !q){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right, q->right);
        return left&right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root && subRoot){
            return false;
        }
        if(root && !subRoot){
            return false;
        }
        if(isSameTree(root,subRoot)){
            return true;
        }
        else if(isSubtree(root->left,subRoot)){
            return true;
        }
        else if(isSubtree(root->right,subRoot)){
            return true;
        }
        else{
            return false;
        }
        return false;
    }
};
