class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int> mp;
      vector<int> res;
      int l = nums.size();
      for(int i=0;i<l;i++){
        if(mp.count(nums[i])){
            res.push_back(mp[nums[i]]);
            res.push_back(i);
            return res;
        }
        else{
            mp[target-nums[i]]=i;
        }
      }  
      return res;
    }
};
