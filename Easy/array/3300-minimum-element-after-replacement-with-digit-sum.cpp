// 3300. Minimum Element After Replacement With Digit Sum
// Difficulty: Easy
// Topics: Array, Math
// Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = 36;
        for (auto& x : nums)
            res = min(res, integral(x) - integral(x - 1));
        return res;
    }

    int integral(int n) {
        return ((n * (n + 1)) >> 1) -
                (9 * (seg(n, 10) + seg(n, 100) +
                seg(n, 1000) + seg(n, 10000)));
    }

    int seg(int n, int k) {
        auto [q, r] = div(n, k);
        return k * ((q * (q - 1)) >> 1) + q * (r + 1);
    
    }
};