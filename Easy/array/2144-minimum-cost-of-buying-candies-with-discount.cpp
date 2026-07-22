// 2144. Minimum Cost of Buying Candies With Discount
// Difficulty: Easy
// Topics: Array, Greedy, Sorting
// Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
       sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            sum += cost[i];
            if (i + 1 < cost.size()) sum += cost[i + 1];
        }
        return sum; 
    }
};