
class Solution {
private:
    void backtrack(std::vector<int>& nums, std::vector<int>& currentPath, std::vector<bool>& visited, std::vector<std::vector<int>>& result) {
        if (currentPath.size() == nums.size()) {
            result.push_back(currentPath);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            currentPath.push_back(nums[i]);

            backtrack(nums, currentPath, visited, result);
            currentPath.pop_back();
            visited[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPath;
        std::vector<bool> visited(nums.size(), false); 
        
        backtrack(nums, currentPath, visited, result);
        return result;
    }
};