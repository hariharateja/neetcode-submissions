class Solution {
public:

    string encode(vector<string>& strs) {
        string en = "";
        for(string s : strs){
            for(char c: s){
                en+=c;
            }
            en+='\n';
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> dec;
        string temp = "";
        for(char c : s){
            if(c=='\n'){
                dec.push_back(temp);
                temp="";
                continue;
            }
            temp+=c;
            
        }
        return dec;
    }
};
