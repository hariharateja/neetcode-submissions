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
    void dfs(TreeNode* root , int& max_val , int& count){
        if(!root) return;
        if(root->val >= max_val){
            max_val = root->val;
            count++;
        }
        int max_l = max_val;
        int max_r = max_val;
        dfs(root->left,max_l,count);
        dfs(root->right,max_r,count);
    }
    int goodNodes(TreeNode* root) {
        int max_val = INT_MIN;
        int count = 0;
        dfs(root , max_val,count);
        return count;
    }
};
