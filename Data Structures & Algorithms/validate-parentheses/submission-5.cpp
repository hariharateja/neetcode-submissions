class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()==1){
            return false;
        }
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(c == ')' || c== '}' || c == ']'){
                if(st.size()==0){
                    return false;
                }
                char t = st.top();
                if(t == '(' && c == ')'){
                    st.pop();
                }
                else if(t == '{' && c == '}'){
                    st.pop();
                }
                else if(t == '[' && c == ']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }
};
