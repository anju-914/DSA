// 153. Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Topics: Array, Binary Search
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
    }
};