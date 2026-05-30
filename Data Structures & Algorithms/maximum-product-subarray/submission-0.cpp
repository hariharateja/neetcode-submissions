#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // Use long long for tracking products to prevent intermediate integer overflow
        long long global_max = nums[0];
        long long current_max = nums[0];
        long long current_min = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            long long num = nums[i];
            
            // Store current_max before updating it
            long long temp_max = current_max;

            // Calculate the three possibilities for both max and min
            current_max = std::max({num, num * current_max, num * current_min});
            current_min = std::min({num, num * temp_max, num * current_min});

            // Update our global maximum result
            global_max = std::max(global_max, current_max);
        }

        return static_cast<int>(global_max);
    }
};