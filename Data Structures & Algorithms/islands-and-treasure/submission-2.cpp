class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()){
            return; 
        }
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Find all treasures ('0') and push them into the queue as our starting points
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Direction arrays for traveling Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 2: Expand outward from all treasures simultaneously (Layer by Layer)
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // If the neighbor is out of bounds, a wall (-1), or already visited (distance is smaller/filled), skip
                // We only process if the cell is an empty land (often represented by a huge number like 2147483647)
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 2147483647) {
                    continue;
                }

                // The shortest distance to this neighbor is the current cell's distance + 1
                grid[nr][nc] = grid[r][c] + 1;
                
                // Push neighbor to the queue to expand its ripple next
                q.push({nr, nc});
            }
        }
    }
};
