// 1288. Remove Covered Intervals
// Difficulty: Medium
// Topics: Array, Sorting
// Link: https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int bache = 0;

        for (int i = 0; i < n; ++i) {
            bool coveredHai = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                // kya interval j, interval i ko cover karti hai?
                // j covers i  =>  j.start <= i.start  aur  i.end <= j.end
                if (intervals[j][0] <= intervals[i][0] &&
                    intervals[i][1] <= intervals[j][1]) {
                    coveredHai = true;
                    break;
                }
            }
            if (!coveredHai) ++bache;
        }
        return bache;
    }
};