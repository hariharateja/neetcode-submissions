class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        vector<vector<string>> res;
        for(string s: strs){
            vector<int> freq(26,0);
            for(char c: s){
                freq[c-'a']++;
            }
            mp[freq].push_back(s);
        }
        for(auto x : mp){
            res.push_back(x.second);
        }
        return res;
    }
};
