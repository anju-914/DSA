// 1846. Maximum Element After Decreasing and Rearranging
// Difficulty: Medium
// Topics: Array, Greedy, Sorting
// Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {

            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();  
    }
};