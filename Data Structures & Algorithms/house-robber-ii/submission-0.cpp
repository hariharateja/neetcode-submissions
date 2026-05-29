#include <vector>
#include <algorithm>

class Solution {
private:
    // This is the standard House Robber helper for a straight line of houses
    int robLinear(const std::vector<int>& nums, int start, int end) {
        int prev2 = 0; // Represents dp[i-2]
        int prev1 = 0; // Represents dp[i-1]
        
        for (int i = start; i <= end; ++i) {
            int current = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }

public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 1) return nums[0];
        if (n == 2) return std::max(nums[0], nums[1]);
        
        // Scenario A: Rob from house 0 to n-2 (Skip the last house)
        int opt1 = robLinear(nums, 0, n - 2);
        
        // Scenario B: Rob from house 1 to n-1 (Skip the first house)
        int opt2 = robLinear(nums, 1, n - 1);
        
        // Return the maximum of both choices
        return std::max(opt1, opt2);
    }
};