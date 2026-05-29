class Solution {
public:
    int findroot(int node , vector<int>& parent){
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findroot(parent[node], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        iota(parent.begin(), parent.end(), 0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            int rootu = findroot(u , parent);
            int rootv = findroot(v, parent);
            if(rootu == rootv){
                return edge;
            }
            parent[rootu] = rootv;
        }
        return {};
    }
};
