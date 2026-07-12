class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v,w});
        }
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
        queue<vector<int>> q;
        q.push({0,src,-1});
        while(!q.empty()){
            auto flight = q.front();
            q.pop();
            int curr_cost = flight[0];
            int curr_node = flight[1];
            int steps = flight[2];
            if(steps>=k) continue;
            for(auto neighbours : adj[curr_node]){
                int next_node = neighbours.first;
                int w = neighbours.second;
                if(curr_cost + w < cost[next_node]){
                    cost[next_node] = curr_cost + w;
                    q.push({cost[next_node] , next_node , steps+1});
                }
            }
        }
        return cost[dst]==INT_MAX ? -1 : cost[dst];

    }
};
