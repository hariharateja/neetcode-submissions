class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res; // Safety check

        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = m-1;
        int t = 0; 
        int b = n-1;

        // FIX 1: Change to <= so it doesn't stop early on the center element/line
        while((l <= r) && (t <= b)){
            
            // FIX 2: Change to <= so corners are included in the traversal
            for(int j = l ;  j <= r ; j++){
                res.push_back(matrix[t][j]);
            }
            t++; // Constrain the top boundary immediately

            for(int i = t ; i <= b ; i++){
                res.push_back(matrix[i][r]);
            }
            r--; // Constrain the right boundary immediately

            // FIX 3: Add checks to make sure boundaries haven't crossed mid-loop
            if (t <= b) {
                for(int j = r ; j >= l ; j--){
                    res.push_back(matrix[b][j]);
                }
                b--; // Constrain the bottom boundary immediately
            }

            if (l <= r) {
                for(int i = b ; i >= t ; i--){
                    res.push_back(matrix[i][l]);
                }
                l++; // Constrain the left boundary immediately
            }
        }
        return res;
    }
};