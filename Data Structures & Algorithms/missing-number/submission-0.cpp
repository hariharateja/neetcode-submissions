class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int final = 0;
        for(int i = 0 ; i <= nums.size() ;i++){
            final = final^i;
        }
        int n_final = 0;
        for(int num :nums){
            n_final = n_final^num;
        }
        return final^n_final;
    }
};
