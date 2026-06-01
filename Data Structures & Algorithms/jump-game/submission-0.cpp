class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int target = nums.size() - 1;
        
        for (int i = 0; i <= target; i++) {
            // If the current index is unreachable, we are stuck
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest index we can reach
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can already reach or pass the last index, we're done!
            if (maxReach >= target) {
                return true;
            }
        }
        
        return false;
    }
};