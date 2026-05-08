class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;
        int l = nums.size();
        for(int i = 0;i<l;i++){
            if(!mp.count(nums[i])){
                mp[nums[i]] = i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};