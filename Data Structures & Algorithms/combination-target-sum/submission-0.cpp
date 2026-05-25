class Solution {
public:
    void backtrack(int start , vector<int>& currentpath , int& sum , vector<int>& nums , int target ,vector<vector<int>>& res){
        if(sum == target){
            res.push_back(currentpath);
            return;
        }
        else if(sum > target){
            return;
        }
        for( int i = start ; i <nums.size() ; i++){
            currentpath.push_back(nums[i]);
            sum+=nums[i];
            backtrack(i,currentpath,sum,nums,target,res);
            currentpath.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currentpath;
        vector<vector<int>> res;
        int sum = 0;
        backtrack(0,currentpath,sum,nums,target,res);
        return res;
    }
};
