class Solution {
public:
    bool ispalindrome(string& s , int start , int end){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void backtrack(int start , string& s ,vector<string>& currentpath,vector<vector<string>>& res){
        if (start == s.length()) {
            res.push_back(currentpath);
            return;
        }
        for(int i = start ; i < s.length() ; i++){
            if (ispalindrome(s, start, i)) {
                std::string substring = s.substr(start, i - start + 1);
                currentpath.push_back(substring);
                backtrack(i + 1, s, currentpath, res);
                currentpath.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currentPath;
        backtrack(0, s, currentPath, res);
        return res;
    }
};
