class Solution {
public:
    bool hasCycle(int node ,vector<vector<int>>& adj , vector<int>& visited){
        if (visited[node] == 1) return true;
        if (visited[node] == 2) return false;
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited)) {
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj[prereq].push_back(course);
        }
        
        // Step 2: Initialize tracking states for all courses (0 = unvisited)
        vector<int> visited(numCourses, 0);
        // Step 3: Run DFS check for every single course
        for (int i = 0; i < numCourses; i++) {
                if (hasCycle(i, adj, visited)) {
                    return false; // Found a cycle, can't finish all courses
                }
        }
        
        return true; // No cycles found anywhere!
    }
};
