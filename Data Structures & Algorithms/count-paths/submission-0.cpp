class Solution {
public:
    int uniquePaths(int m, int n) {
        int total_moves = m + n - 2;
        
        int k = std::min(m - 1, n - 1); 
        
        long long result = 1;
        
        
        for (int i = 1; i <= k; ++i) {
            result = result * (total_moves - k + i) / i;
        }
        
        return result;
    }
};
