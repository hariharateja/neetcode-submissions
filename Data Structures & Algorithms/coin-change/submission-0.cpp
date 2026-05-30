class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = amount + 1;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INF));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1 ; j <= amount ;j++){
                int exclude = dp[i - 1][j];
                int include = INF;
                if (coins[i - 1] <= j) {
                    include = 1 + dp[i][j - coins[i - 1]]; // Note: staying on row 'i' to reuse it!
                }
                dp[i][j] = std::min(exclude, include);
                
            }
        }
        return dp[n][amount] > amount ? -1 : dp[n][amount];
    }
};
