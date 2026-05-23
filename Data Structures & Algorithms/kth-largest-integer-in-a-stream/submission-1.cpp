class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;

        int i = 0;

        while (i < nums.size()) {

            if (pq.size() < K) {
                pq.push(nums[i]);
            }
            else {
                int kth = pq.top();

                if (nums[i] > kth) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }

            i++;
        }
    }
    
    int add(int val) {
        if (pq.size() < K) {
            pq.push(val);
        }
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};
