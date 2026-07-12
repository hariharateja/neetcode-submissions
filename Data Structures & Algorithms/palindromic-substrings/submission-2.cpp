class Solution {
public:
    int countway(string& s , int left , int right){
        int count = 0;
        while(left>=0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int total = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int count1 = countway(s,i,i);
            int count2 = countway(s,i,i+1);
            total = total + count1 + count2;
        }
        return total;
    }
};
