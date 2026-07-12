class Solution {
public:
    void backtrack(int start , vector<int>& nums , int& target , int& sum, vector<int>& currentpath , vector<vector<int>>& res){
        if(target == sum){
            res.push_back(currentpath);
        }
        if(target < sum) return;
        for(int i = start ; i < nums.size() ; i++){
            currentpath.push_back(nums[i]);
            sum+=nums[i];
            backtrack(i,nums,target,sum,currentpath,res);
            sum-=nums[i];
            currentpath.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> currentpath;
        int sum = 0;
        backtrack(0,nums,target,sum,currentpath,res);
        return res;
    }
};
