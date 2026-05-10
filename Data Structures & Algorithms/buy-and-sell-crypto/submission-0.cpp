class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0 ; 
       int min_buy = 0;
       min_buy = prices[0];
       int n = prices.size();
       for(int i = 0 ; i < n ; i++){
            min_buy = min(prices[i],min_buy);
            profit = max(profit, prices[i]-min_buy);
       } 
       return profit;
    }
};
