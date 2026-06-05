class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap stores elements as: {max_elevation_along_path, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Visited matrix to avoid processing a cell multiple times
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Push the starting cell (0, 0)
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        // Direction vectors for moving up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int max_time = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            // If we reached the bottom-right corner, return the answer
            if (r == n - 1 && c == n - 1) {
                return max_time;
            }
            
            // Explore all 4 adjacent neighbors
            for (int i = 0; i < 4; i++) {
                int newR = r + dx[i];
                int newC = c + dy[i];
                
                // Boundary check and visited check
                if (newR >= 0 && newR < n && newC >= 0 && newC < n && !visited[newR][newC]) {
                    visited[newR][newC] = true;
                    
                    // The bottleneck for the neighbor is the maximum of the current 
                    // path's bottleneck and the neighbor's own elevation.
                    int next_time = max(max_time, grid[newR][newC]);
                    
                    pq.push({next_time, newR, newC});
                }
            }
        }
        
        return 0;
    }
};