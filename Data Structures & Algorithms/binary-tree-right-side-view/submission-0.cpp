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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            cout<<l<<"\n";
            for(int i = 0 ; i < l ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr){
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                    if(i==l-1)
                        res.push_back(curr->val);
                }
            }
        }
        return res;
    }
};
