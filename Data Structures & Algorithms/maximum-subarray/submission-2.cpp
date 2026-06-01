class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for(int num : nums){
            curr_sum = max((curr_sum+num) , num);
            max_sum = max(curr_sum , max_sum);
        }
        return max_sum;
    }
};
