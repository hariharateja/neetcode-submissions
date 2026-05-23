class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int num : stones){
            pq.push(num);
        }
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x!=y){
                pq.push(x-y);
            }
        }
        return pq.size()==1 ? pq.top() : 0;
    }
};
