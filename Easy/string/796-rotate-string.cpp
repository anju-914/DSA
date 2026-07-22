// 796. Rotate String
// Difficulty: Easy
// Topics: String, String Matching
// Link: https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
       return s.size()==goal.size() && (s+s).find(goal)!=-1; 
    }
};