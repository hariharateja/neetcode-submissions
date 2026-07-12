class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto flight : times){
            int u = flight[0];
            int v = flight[1];
            int t = flight[2];
            adj[u].push_back({v,t});
        }
        vector<int> visited(n+1,0);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int curr_distance = node.first;
            int curr_node = node.second;
            visited[curr_node] = 1;
            if(curr_distance > distance[curr_node]) continue;
            for(auto neighbours : adj[curr_node]){
                int n_node = neighbours.first;
                int w = neighbours.second;
                if(!visited[n_node] && w + curr_distance < distance[n_node]){
                    distance[n_node] = w + curr_distance;
                    pq.push({distance[n_node],n_node});
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(distance[i] == INT_MAX){ // If a node's distance remains INT_MAX, it's unreachable
                return -1;
            }
        }
        return *max_element(distance.begin() + 1, distance.end());
    }
};
