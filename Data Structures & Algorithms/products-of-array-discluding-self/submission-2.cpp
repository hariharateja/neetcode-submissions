class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> prefix(l,0);
        vector<int> suffix(l,0);
        prefix[0] = 1;
        suffix[l-1] = 1;
        for(int i = 1;i<l;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i = l-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int> res;
        for(int i = 0 ; i < l ; i++){
            res.push_back(prefix[i]*suffix[i]);
        }
        return res;
    }
};
