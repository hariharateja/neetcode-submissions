class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         int n = s.length();
        // dp[i] will be true if s[i...n-1] can be segmented into dictionary words
        std::vector<bool> dp(n + 1, false);
        
        // Base case: An empty trailing substring is always valid
        dp[n] = true;
        
        // Iterate backwards from the end of the string to the beginning
        for (int i = n - 1; i >= 0; --i) {
            for (const std::string& word : wordDict) {
                int wordLen = word.length();
                
                // Check if the word fits within the remaining string bounds
                // AND if the substring starting at i matches the dictionary word
                if (i + wordLen <= n && s.compare(i, wordLen, word) == 0) {
                    // dp[i] inherits the truth value of the remaining substring
                    dp[i] = dp[i + wordLen];
                }
                
                // Optimization: If we found a valid split for index i, 
                // we don't need to check the remaining words for this position
                if (dp[i]) {
                    break;
                }
            }
        }
        
        // dp[0] stores whether the entire string s can be segmented
        return dp[0];
    }
};
