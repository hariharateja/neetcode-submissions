class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 0;
        for(int i = 0 ; i < n ; i++){
            m = max(m,piles[i]);
        }
        int left = 1;
        int right = m;
        int mid;
        while(left<right){
            mid = (left+right)/2;
            int time = 0;
            for(int pile : piles){
                if(pile%mid == 0){
                    time += pile/mid;
                }
                else{
                    time += pile/mid;
                    time++;
                }
            }
            if(time <= h){
                right = mid;
            }
            else if(time > h){
                left = mid+1;
            }
        }
        return left;
    }
};
