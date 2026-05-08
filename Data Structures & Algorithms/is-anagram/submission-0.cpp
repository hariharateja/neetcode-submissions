class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_l = s.length();
        int t_l = t.length();
        if(s_l !=t_l){
            return false;
        }
        map<int,int> cnt;
        for(int i = 0 ;i < s_l;i++){
            int c = s[i]-'a';
            cnt[c]++;
        }
        for(int i = 0 ;i < t_l;i++){
            int c = t[i]-'a';
            cnt[c]--;
        }
        for(auto x :cnt){
            if(x.second != 0)
                return false;
        }
        return true;

    }
};
