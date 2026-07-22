// 974. Subarray Sums Divisible by K
// Difficulty: Medium
// Topics: Array, Hash Table, Prefix Sum
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) {
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};