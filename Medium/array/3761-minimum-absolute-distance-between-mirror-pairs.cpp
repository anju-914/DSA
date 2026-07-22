// 3761. Minimum Absolute Distance Between Mirror Pairs
// Difficulty: Medium
// Topics: Array, Hash Table, Math
// Link: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
       int res = 100000, i = 0;
        unordered_map<int, int> seen;

        for (int& n : nums) {
            int r;
            if (seen.count(n))
                res = min(res, i - seen[n]);

            for (r = 0; n; n /= 10)
                r = r * 10 + (n % 10);

            seen[r] = i++;
        }

        return -(res == 100000) | res; 
    }
};