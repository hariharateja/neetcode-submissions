class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> indices;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m ;j++){
                if(matrix[i][j] == 0){
                    indices.push_back({i,j});
                }
            }
        }
        for(auto index : indices){
            int r = index.first;
            int c = index.second;
            for(int i = 0 ; i < n ;i++){
                matrix[i][c] = 0;
            }
            for(int j = 0; j<m;j++){
                matrix[r][j] = 0;
            }
        }

    }
};
