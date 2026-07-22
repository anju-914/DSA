// 2553. Separate the Digits in an Array
// Difficulty: Easy
// Topics: Array, Simulation
// Link: https://leetcode.com/problems/separate-the-digits-in-an-array/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {

            string s = to_string(num);

            for (char ch : s) {

                result.push_back(ch - '0');
            }
        }

        return result;
    }
};