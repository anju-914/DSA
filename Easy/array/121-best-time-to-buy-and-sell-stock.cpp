// 121. Best Time to Buy and Sell Stock
// Difficulty: Easy
// Topics: Array, Dynamic Programming
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit =0;
       int n = prices.size();
       int currentPrice = prices[0];

       for(int i=0;i<n;i++){
        currentPrice = min(prices[i] , currentPrice);

        int profit = prices[i] - currentPrice;

        maxProfit = max(profit, maxProfit);
       } 
       return maxProfit;
    }
};