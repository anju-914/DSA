// 2784. Check if Array is Good
// Difficulty: Easy
// Topics: Array, Hash Table, Sorting
// Link: https://leetcode.com/problems/check-if-array-is-good/

class Solution {
public:
    bool isGood(vector<int>& nums) {
       int n = nums.size() - 1;
        bitset<201> seen;
        bool dup = 0;

        for (auto& num : nums) {
            if (num > n) return false;

            if (seen.test(num)) {
                if (num < n || dup) return false;
                dup |= 1;
                continue;
            }

            seen.set(num);
        }

        return true; 
    }
};