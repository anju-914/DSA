// 167. Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Topics: Array, Two Pointers, Binary Search
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int n = numbers.size();
       int l = 0, r = n - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];

            if (curSum > target) {
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                return { l + 1, r + 1 };
            }
        }
        return {}; 
    }
};