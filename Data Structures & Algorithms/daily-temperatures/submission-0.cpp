class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int l = temperatures.size();
        vector<int> ans(l,0);
        for(int i = l-1 ; i >=0 ;i --){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};
