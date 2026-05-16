class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int i , j = 0;
        int right = n*m-1;
        int mid = 0;
        while(left<=right){
            mid = (left+right)/2;
            i = mid/m;
            j = mid%m;
            if(target == matrix[i][j]){
                return true;
            }
            else if(target > matrix[i][j]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};
