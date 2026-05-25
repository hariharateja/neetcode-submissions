class Solution {
public:
    void backtrack(int start , vector<int>& nums ,vector<int>&currentpath, vector<vector<int>>& res){
        res.push_back(currentpath);

        for(int i = start ; i <nums.size() ; i++){
            currentpath.push_back(nums[i]);

            backtrack(i+1,nums , currentpath , res);

            currentpath.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<std::vector<int>> result;
        vector<int> currentPath;
        backtrack(0, nums, currentPath, result);
        return result;
    }
};
