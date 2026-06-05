class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n;j++){
                if(i!=j){
                    int xi = points[i][0];
                    int yi = points[i][1];
                    int xj = points[j][0];
                    int yj = points[j][1];
                    int cost = abs(xi-xj) + abs(yi-yj);
                    adj[i].push_back({j,cost});
                }
            }
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> visited(n,0);
        pq.push({0,0,-1});
        int total = 0;

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int curr = node[1];
            int cost = node[0];
            int parent = node[2];
            if(visited[curr]){
                continue;
            }
            visited[curr] = 1;
            total+=cost;
            for(auto neighbour : adj[curr]){
                if(!visited[neighbour.first]){
                    pq.push({neighbour.second,neighbour.first,curr});
                }
                
            }
        }
        return total;
    }
};
