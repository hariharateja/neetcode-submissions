class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        // FIX 1: Change to store pairs {destination, cost}
        vector<vector<pair<int, int>>> adj(n); 
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<vector<int>> Q;
        dist[src] = 0;
        Q.push({src, 0, -1});
        
        // FIX 2: Added missing while loop condition
        while(!Q.empty()) { 
            auto vec = Q.front();
            Q.pop();
            int u = vec[0];
            int cost = vec[1];
            int steps = vec[2];
            
            // FIX 3: If we have already taken k stops, we cannot move to any more neighbors
            if (steps >= k) continue; 
            
            for(auto neighbour : adj[u]){
                int v = neighbour.first;
                int cost2 = neighbour.second;
                
                // If this path to 'v' is cheaper than what we found previously, grab it
                if (cost + cost2 < dist[v]) {
                    dist[v] = cost + cost2;
                    Q.push({v, dist[v], steps + 1});
                }
            }
        }
        
        // If dst is unreachable, return -1 per problem description
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};