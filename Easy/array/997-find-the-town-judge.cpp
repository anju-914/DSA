// 997. Find the Town Judge
// Difficulty: Easy
// Topics: Array, Hash Table, Graph Theory
// Link: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1), out(n + 1);
		for (auto a : trust) {
			++out[a[0]];
			++in[a[1]];
		}
		for (int i = 1; i <= n; ++i) {
			if (in[i] == n - 1 && out[i] == 0) return i;
		}
		return -1;
    }
};