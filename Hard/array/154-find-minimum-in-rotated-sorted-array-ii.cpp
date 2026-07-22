// 154. Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// Topics: Array, Binary Search
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r) {

            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r]) {
                r = mid;
            }
            else if(nums[mid] > nums[r]) {
                l = mid + 1;
            }
            // duplicates
            else {
                r--;
            }
        }

        return nums[l];
    }
};