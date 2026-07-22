// 2515. Shortest Distance to Target String in a Circular Array
// Difficulty: Easy
// Topics: Array, String
// Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int i = 0; i <= n >> 1; i++)
            if (words[(startIndex + i) % n] == target |
                words[(startIndex - i + n) % n] == target)
                return i;
                
        return -1;
    }
};