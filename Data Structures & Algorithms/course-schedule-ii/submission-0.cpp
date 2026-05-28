#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order) {
        if (visited[node] == 1) return true;  // Cycle detected
        if (visited[node] == 2) return false; // Already processed
        
        visited[node] = 1; // Mark as visiting
        
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited, order)) {
                return true;
            }
        }
        
        visited[node] = 2; // Mark as fully visited
        
        // --- THE ONLY ADDITION ---
        // Since all dependencies of 'node' are now fully processed,
        // this node is safe to add to our finished sequence.
        order.push_back(node); 
        
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj[prereq].push_back(course);
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> order; // To store the topological order
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, adj, visited, order)) {
                    return {}; // Return empty array if a cycle exists
                }
            }
        }
        
        // Since nodes are pushed when they finish, the list is backwards.
        // Reverse it to get the correct chronological order.
        reverse(order.begin(), order.end());
        
        return order;
    }
};