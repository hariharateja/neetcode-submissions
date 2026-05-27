#include <vector>

using namespace std;

class Solution {
private:
    int rows, cols;

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited, int previousHeight) {
        
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        // 2. If already visited by this ocean, stop to prevent infinite loops
        if (visited[r][c]) {
            return;
        }

        // 3. Since we are moving BACKWARDS (from ocean up into land), 
        // the next cell must be EQUAL OR HIGHER than the previous cell.
        if (heights[r][c] < previousHeight) {
            return;
        }

        // Mark as reachable by this ocean
        visited[r][c] = true;

        // Traverse all 4 directions
        dfs(r + 1, c, heights, visited, heights[r][c]); // Down
        dfs(r - 1, c, heights, visited, heights[r][c]); // Up
        dfs(r, c + 1, heights, visited, heights[r][c]); // Right
        dfs(r, c - 1, heights, visited, heights[r][c]); // Left
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;

        rows = heights.size();
        cols = heights[0].size();

        // Step 1: Create two separate visited trackers for each ocean
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Step 2: Kick off DFS from Ocean Boundaries
        // Loop through columns (Top row for Pacific, Bottom row for Atlantic)
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific, heights[0][c]);             // Pacific Top Row
            dfs(rows - 1, c, heights, atlantic, heights[rows - 1][c]); // Atlantic Bottom Row
        }

        // Loop through rows (Left column for Pacific, Right column for Atlantic)
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific, heights[r][0]);             // Pacific Left Col
            dfs(r, cols - 1, heights, atlantic, heights[r][cols - 1]); // Atlantic Right Col
        }

        // Step 3: Find the overlap where cells can reach BOTH oceans
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};