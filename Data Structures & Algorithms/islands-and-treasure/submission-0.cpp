class Solution {
public:
    void dfs(vector<vector<int>>& grid , int r , int c , int rows , int cols ,int dist){
        if(r<0 || r>=rows || c<0 || c >=cols || grid[r][c] == -1){
            return;
        }
        
        if(dist > grid[r][c]) {
            return;
        }
        
        grid[r][c] = dist;
        
        dfs(grid , r+1,c,rows,cols,dist + 1);
        dfs(grid , r,c+1,rows,cols,dist + 1);
        dfs(grid , r-1,c,rows,cols,dist + 1);
        dfs(grid , r,c-1,rows,cols,dist +1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()){
            return; 
        }
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0;r<rows;r++){
            for(int c = 0 ; c<cols;c++){
                if(grid[r][c] == 0){
                    int dist = 0;
                    dfs(grid,r,c,rows,cols,dist);
                }
            }
        }
    }
};
