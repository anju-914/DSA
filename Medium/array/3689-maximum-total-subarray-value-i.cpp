// 3689. Maximum Total Subarray Value I
// Difficulty: Medium
// Topics: Array, Greedy
// Link: https://leetcode.com/problems/maximum-total-subarray-value-i/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        long long diff=maxi-mini;
        return k*diff;
    }
};