class Solution {
public:
    void backtrack(int start , vector<int>& currentpath ,vector<int>& nums,vector<vector<int>>& res){
        res.push_back(currentpath);
        for(int i = start ; i < nums.size() ; i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            currentpath.push_back(nums[i]);
            backtrack(i+1,currentpath,nums,res);
            currentpath.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> currentpath;
        vector<vector<int>> res;
        int start = 0 ; 
        sort(nums.begin(), nums.end());
        backtrack(start , currentpath , nums , res);
        return res;
    }
};
