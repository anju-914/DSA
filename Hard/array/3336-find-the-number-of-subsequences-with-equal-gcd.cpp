// 3336. Find the Number of Subsequences With Equal GCD
// Difficulty: Hard
// Topics: Array, Math, Dynamic Programming, Number Theory
// Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[201][201][201];

    int solve(int idx, int gcd1, int gcd2, vector<int>& nums) {

        if(idx == nums.size())
            return gcd1 != 0 && gcd1 == gcd2;

        if(dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2];

        long long ans = 0;

        // Skip current element
        ans += solve(idx + 1, gcd1, gcd2, nums);

        // Put current element into seq1
        ans += solve(idx + 1, gcd(gcd1, nums[idx]), gcd2, nums);

        // Put current element into seq2
        ans += solve(idx + 1, gcd1, gcd(gcd2, nums[idx]), nums);

        return dp[idx][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};