class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // FIX 1: Fixed the double brackets '<<' and initialized the outer vector size
        vector<vector<pair<int,int>>> adj(n+1); 
        vector<bool> visited(n+1,false);
        // FIX 2: Initialized path array with INT_MAX instead of -1 so min-comparisons work
        vector<int> path(n+1, INT_MAX); 
        
        for(auto vec : times){
            // FIX 3: Used 'vec' (the iterator) instead of the whole 'times' matrix
            adj[vec[0]].push_back({vec[1],vec[2]}); 
        }
        
        // FIX 4: Fixed '<<' brackets and changed to a min-heap using greater<>
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        path[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int curr_node = node.second;
            int curr_dist = node.first;
            
            // FIX 5: Skip processing if we already found a shorter path to this node
            if (curr_dist > path[curr_node]) continue;
            
            visited[curr_node] = true;
            
            // FIX 6: Loop through adj[curr_node] (neighbors of the current node), not the entire adj list
            for(auto neighbour : adj[curr_node]){
                // FIX 7: Standard Dijkstra relaxation condition (only update if the new path is shorter)
                if(!visited[neighbour.first] && path[curr_node] + neighbour.second < path[neighbour.first]){
                    // FIX 8: Fixed typo 'neightbour' to 'neighbour'
                    path[neighbour.first] = path[curr_node] + neighbour.second;
                    pq.push({path[neighbour.first], neighbour.first});
                }
            }
        }
        
        // FIX 9: Verify if any node was left unvisited
        for(int i = 1 ; i <= n ; i++){
            if(path[i] == INT_MAX){ // If a node's distance remains INT_MAX, it's unreachable
                return -1;
            }
        }
        
        // FIX 10: Changed upper_bound to max_element to find the maximum time taken in the path array
        return *max_element(path.begin() + 1, path.end());
    }
};