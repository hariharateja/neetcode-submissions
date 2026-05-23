class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create a min-heap that stores: pair<distance, point_coordinates>
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            
            // Push the distance and the point together
            pq.push({dist, points[i]});
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            // The top element is guaranteed to be the closest remaining point
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};