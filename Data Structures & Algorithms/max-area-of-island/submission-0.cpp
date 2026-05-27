class Solution {
public:
    void dfs(vector<vector<int>>& grid , int r , int c , int rows , int cols , int& area){
        if(r<0 || r>=rows || c<0 || c >=cols || grid[r][c]==0){
            return;
        }
        grid[r][c] = 0;
        area++;
        dfs(grid , r+1 , c ,rows,cols,area);
        dfs(grid , r , c+1 ,rows ,cols,area);
        dfs(grid , r-1 , c , rows , cols , area);
        dfs(grid , r , c-1 ,rows , cols , area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int maxarea = 0;
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < cols ;c++){
                if(grid[r][c] == 1){
                    int area = 0 ;
                    dfs(grid , r , c , rows , cols , area);
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};
