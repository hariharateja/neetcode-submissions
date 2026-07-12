class Solution {
public:
    int max_ = 1e9;
    int f(int ind ,vector<int>& coins , int amount , vector<int>& dp){
        if(ind == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else{
                return max_;
            }
        }
        
        if(dp[ind] != -1) dp[ind];
        int nottake = f(ind-1, coins,amount,dp);
        int take = 1e9;
        if(amount>=coins[ind]){
            take = 1 + f(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(n);
        int total = f(n-1,coins,amount,dp);
        return total>=1e9?-1:total;
    }
};
