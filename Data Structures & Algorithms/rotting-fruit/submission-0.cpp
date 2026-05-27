class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int freshOranges = 0;
        for(int r= 0 ; r<rows ; r++){
            for(int c =0 ; c<cols;c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                } else if(grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0) return 0;
        int dr[] = {1 ,-1,0,0};
        int dc[] = {0 , 0 , 1,-1};
        int minutes = 0;
        while(!q.empty()){
            int level = q.size();
            bool rottedAnyThisLevel = false;
            for(int j = 0 ; j< level ;j++){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4 ;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr<0||nr>=rows||nc<0||nc>=cols||grid[nr][nc]==0||grid[nr][nc]==2){
                        continue;
                    }
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    freshOranges--; 
                    rottedAnyThisLevel = true;
                }
            }
            if(rottedAnyThisLevel) {
                minutes++;
            }
        }
        return (freshOranges == 0) ? minutes : -1;
    }
};
