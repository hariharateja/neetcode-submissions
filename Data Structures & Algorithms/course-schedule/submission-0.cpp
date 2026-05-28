#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
        // If we hit a node currently being visited, a cycle exists!
        if (visited[node] == 1) return true;
        // If it's already fully processed, no need to check again
        if (visited[node] == 2) return false;
        
        // Mark the current node as "visiting"
        visited[node] = 1;
        
        // Traverse all the courses that depend on this prerequisite
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited)) {
                return true;
            }
        }
        
        // Mark the node as fully processed
        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list
        // adj[b] will hold a list of all courses 'a' that require course 'b'
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
            if (visited[i] == 0) {
                if (hasCycle(i, adj, visited)) {
                    return false; // Found a cycle, can't finish all courses
                }
            }
        }
        
        return true; // No cycles found anywhere!
    }
};