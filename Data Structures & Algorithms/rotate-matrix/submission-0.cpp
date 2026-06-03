class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = n/2;
        int l = 0;
        int r = n-1;
        int t = 0;
        int b = n-1;
        while((l<r) && (t<b)){
            int temp;
            for(int i = 0 ; i < r-l ;i++){
                temp = matrix[t][l+i];
                matrix[t][l+i] = matrix[b-i][l];
                matrix[b-i][l] = matrix[b][r-i];
                matrix[b][r-i] = matrix[t+i][r];
                matrix[t+i][r] = temp;
            }
            l++;
            r--;
            t++;
            b--;

        }
    }
};
