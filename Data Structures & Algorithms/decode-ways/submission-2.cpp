#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        // dp[i] stores the number of ways to decode a string of length i
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // Empty string base foundation
        dp[1] = 1; // We already checked that s[0] != '0'

        for (int i = 2; i <= n; i++) {
            // Check 1-digit option (s[i-1] because string is 0-indexed)
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }

            // Check 2-digit option (s[i-2] and s[i-1] combined)
            int twoDigits = std::stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};