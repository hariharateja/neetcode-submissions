#include <vector>

using namespace std;

class Solution {
public:
    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            // If the neighbor is not visited, recursively check it
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, node, adj, visited)) {
                    return true;
                }
            }
            // If neighbor IS visited and it's NOT the immediate parent, we found a cycle!
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
    bool hascycle(int node , int parent ,vector<vector<int>>&adj , vector<bool>& visited){
        visited[node] = true;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(hascycle(neighbour, node,adj,visited)){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: A valid tree must have exactly n - 1 edges
        if (edges.size() != n - 1) {
            return false;
        }
        
        // Build the undirected adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Because it's undirected
        }
        
        vector<bool> visited(n, false);
        
        // Condition 2: Check for cycles starting from node 0
        // We pass -1 as the parent of the starting node
        if (hasCycle(0, -1, adj, visited)) {
            return false;
        }
        
        // Condition 3: Check connectivity (ensure all nodes were reached)
        for (bool v : visited) {
            if (!v) return false; 
        }
        
        return true;
    }
};