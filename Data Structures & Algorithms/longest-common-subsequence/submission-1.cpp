class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Create a 2D DP table initialized with 0
        // Size is (m + 1) x (n + 1) to handle empty string base cases
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // Build the table from the bottom up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match, add 1 to the previous diagonal state
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Characters don't match, take the max of skipping from text1 or text2
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The bottom-right corner contains the length of the LCS
        return dp[m][n];
    }
};
