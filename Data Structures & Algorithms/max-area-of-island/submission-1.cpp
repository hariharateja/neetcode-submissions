class Solution {
public:
    int n = 0;
    int m = 0;
    
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0; // Mark the starting cell as visited immediately!
        int area = 1;   // Start area at 1 since we've counted the starting cell
        
        while (!q.empty()) {
            auto [curr_r, curr_c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = curr_r + dx[i];
                int nc = curr_c + dy[i];
                
                // Changed '0' to 0
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) {
                    continue;
                }
                
                grid[nr][nc] = 0; // Mark as visited right before pushing
                area++;
                q.push({nr, nc});
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxarea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Changed '1' to 1
                if (grid[i][j] == 1) {
                    maxarea = max(maxarea, bfs(grid, i, j));
                }
            }
        }
        return maxarea;
    }
};