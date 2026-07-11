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
    int k_smallest = 0;
    void dfs(TreeNode* root , int& count , int k){
        if(!root) return;
        dfs(root->left,count,k);
        count++;
        if(count==k){
            k_smallest = root->val;
        }
        dfs(root->right , count , k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        dfs(root,count,k);
        return k_smallest;
    }
};
