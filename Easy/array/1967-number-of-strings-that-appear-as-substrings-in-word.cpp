// 1967. Number of Strings That Appear as Substrings in Word
// Difficulty: Easy
// Topics: Array, String
// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
      int count = 0;

        for (string &pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;  
    }
};