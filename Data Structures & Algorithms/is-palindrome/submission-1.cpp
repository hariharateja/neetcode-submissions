class Solution {
public:
    bool isPalindrome(string s) {
        string t ="";
        for(char c : s){
            if(isalnum(c)){
                t+=c;
            }
        }
        int start = 0;
        int end = (int)t.length()-1;
        while(end>start){
            char c1 = tolower(t[start]);
            char c2 = tolower(t[end]);
            if(c1!=c2){
                return false;
            }
            end--;
            start++;
        }
        return true;
    }
};
