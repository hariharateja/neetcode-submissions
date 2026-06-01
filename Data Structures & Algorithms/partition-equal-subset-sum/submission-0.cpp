class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        
        // If the total sum is odd, it cannot be split into two equal integer subsets
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        int n = nums.size();
        
        // dp[j] will store whether a sum of j can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible
        
        // Process each number
        for (int num : nums) {
            // Traverse backwards to prevent using the same number multiple times
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }
        
        return dp[target];
    }
};