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
    int max_sum;
    int getMaxGain(TreeNode* node){
        if (node == nullptr) {
            return 0;
        }

        // Step 2: Recurse on children. 
        // If a child returns a negative sum, discard it by clamping to 0.
        int left_gain = std::max(getMaxGain(node->left), 0);
        int right_gain = std::max(getMaxGain(node->right), 0);

        // Step 3: Calculate the path sum if this node acts as the "turnaround" point
        int current_path_sum = node->val + left_gain + right_gain;
        
        // Update our global max tracking
        max_sum = std::max(max_sum, current_path_sum);

        // Step 4: Return the maximum single branch contribution to the parent
        return node->val + std::max(left_gain, right_gain);
    }
    
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        getMaxGain(root);
        
        return max_sum;
    }
};
