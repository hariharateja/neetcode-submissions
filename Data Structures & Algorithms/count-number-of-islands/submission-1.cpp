class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        // Direction arrays to easily compute adjacent offsets (Down, Up, Right, Left)
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islandCount++;
                    
                    // Trigger BFS
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = '0'; // Sink it immediately upon pushing

                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        // Check all 4 potential neighbors
                        for (int i = 0; i < 4; i++) {
                            int nr = currR + dr[i];
                            int nc = currC + dc[i];

                            // Check bounds and if it is land
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                grid[nr][nc] = '0'; // Sink it to prevent duplicate queuing
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }
};
