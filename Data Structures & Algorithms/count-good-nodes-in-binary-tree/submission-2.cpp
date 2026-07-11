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
    int count = 0;
    void dfs(int max_val , TreeNode* root){
        if(!root) return;
        if(root->val>=max_val){
            count++;
            max_val = root->val;
        }
        dfs(max_val , root->left);
        dfs(max_val , root->right);
    }
    int goodNodes(TreeNode* root) {
        dfs(INT_MIN,root);
        return count;
    }
};
