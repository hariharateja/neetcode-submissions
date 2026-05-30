class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0;
        int maxlength = 1;
        for(int i = 0; i<n;i++){
            dp[i][i] = true;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = 0 ; j <n ;j++){
                if(s[i]==s[j]){
                    if(j-i<3 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if (j - i + 1 > maxlength) {
                            maxlength = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxlength);
    }
};
