class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l = nums.size();
        for(int i = 0;i<l;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x : mp) {
            pq.push({x.second, x.first});
        }
        vector<int> ans;

        while(k--) {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }
};
