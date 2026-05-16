class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> minright(n,0);
        vector<int> minleft(n,0);
        stack<int> right;
        for(int i = n-1;i>=0;i--){
            while(!right.empty() && heights[right.top()]>=heights[i]){
                right.pop();
            }
            if(right.empty()){
                minright[i] = n;
            }
            else{
                minright[i] = right.top();
            }
            right.push(i);
        }
        stack<int> left;
        for(int i = 0;i<n;i++){
            while(!left.empty() && heights[left.top()]>=heights[i]){
                left.pop();
            }
            if(left.empty()){
                minleft[i] = -1;
            }
            else{
                minleft[i] = left.top();
            }
            left.push(i);
        }
        int max_area = 0;
        for(int i = 0 ; i < n ;i++){
            int area = (minright[i] - minleft[i]-1)*heights[i];
            max_area = max(max_area , area);
        }
        return max_area;
    }
};
