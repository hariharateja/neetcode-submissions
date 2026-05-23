class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0;
        priority_queue<int , vector<int> , greater<int>> pq;
        while (i < nums.size()) {

            if (pq.size() < k) {
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
        return pq.top();
    }
};
