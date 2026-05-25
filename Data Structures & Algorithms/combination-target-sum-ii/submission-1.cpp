#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, vector<int>& currentpath, int& sum, vector<int>& nums, int target, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(currentpath);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // CRITICAL DUPLICATE SKIP:
            // If the current element is the same as the previous element *at the same level*, skip it.
            // i > start ensures we are allowed to pick the first occurrence of a number in this position.
            if (i > start && nums[i] == nums[i - 1]) {
                continue; 
            }

            currentpath.push_back(nums[i]);
            sum += nums[i];
            
            // i + 1 because each number can only be used once
            backtrack(i + 1, currentpath, sum, nums, target, res); 
            
            currentpath.pop_back();
            sum -= nums[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> currentpath;
        vector<vector<int>> res;
        int sum = 0;
        
        // 1. You MUST sort the array for the duplicate-skip logic to work
        std::sort(nums.begin(), nums.end());
        
        backtrack(0, currentpath, sum, nums, target, res);
        return res;
    }
};