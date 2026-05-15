class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(m<n){
            return false;
        }
        vector<int> freq(26,0);
        vector<int> helper(26,0);
        for(int i = 0 ;i <s1.length();i++){
            freq[s1[i]-'a']++;
            helper[s2[i]-'a']++;
        }
        int l = 0;
        int k = s1.length();
        for(int r = k;r<s2.length();r++){
            if(freq == helper ){
                return true;
            }
            helper[s2[l]-'a']--;
            l++;
            helper[s2[r]-'a']++;
        }
        if(freq == helper){
            return true;
        }
        return false;
    }
};
