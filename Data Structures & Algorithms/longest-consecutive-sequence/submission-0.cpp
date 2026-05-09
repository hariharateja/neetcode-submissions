class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int l = nums.size();
        for(int i = 0 ; i < l ; i++){
            mp[nums[i]] = i;
        }
        int max_len = 0;
        for(int i = 0 ; i < l;i++){
            int start = 0;
            if(mp.count(nums[i]-1)){
                continue;
            }
            start = nums[i];
            int next = start+1;
            int len = 1;
            while(mp.count(next)){
                len++;
                next+=1;
            }
            max_len = max(len,max_len);
        }
        return max_len;
    }
};
