class Solution {
public:
    void backtrack(int open , int close , string& currentpath , vector<string>& res){
        if(open == 0 && close ==0){
            res.push_back(currentpath);
            return;
        }

        if(open>0){
            currentpath+='(';
            backtrack(open - 1, close, currentpath, res);
            currentpath.pop_back();
        }
        if(close>open){
            currentpath+=')';
            backtrack(open, close-1, currentpath, res);
            currentpath.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string currentPath = "";
        
        backtrack(n, n, currentPath, result);
        return result;
    }
};
