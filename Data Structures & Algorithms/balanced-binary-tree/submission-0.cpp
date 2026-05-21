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
    int dfs(TreeNode* root , bool& t){
        if(!root) return 0;
        int left = dfs(root->left , t);
        int right = dfs(root->right , t);
        if(left == -1 || right == -1){
            t = false;
            return -1;
        }
        if(abs(left-right)>1){
            t = false;
            return -1;
        }
        return (1+max(left,right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool t = true;
        int n = dfs(root , t);
        return t;
    }
};
