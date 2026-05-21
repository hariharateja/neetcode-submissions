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
    map<int,int> mp;
    int preindex = 0;
    TreeNode* solve(vector<int>& preorder , int left , int right){
        if(left > right)
            return nullptr;

        int rootVal = preorder[preindex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        root->left = solve(preorder, left, mid-1);
        root->right = solve(preorder, mid+1, right);

        return root;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return solve(preorder,0,inorder.size()-1);

    }
};
