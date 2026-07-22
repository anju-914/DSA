// 1833. Maximum Ice Cream Bars
// Difficulty: Medium
// Topics: Array, Greedy, Sorting, Counting Sort
// Link: https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (cost > coins) break;

            count++;
            coins -= cost;
        }

        return count;
    }
};