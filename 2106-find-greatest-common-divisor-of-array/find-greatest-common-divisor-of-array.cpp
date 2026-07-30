class Solution {
public:
    int findGCD(vector<int>& nums) {
       int smallNum = *min_element(nums.begin(), nums.end());
        int largeNum = *max_element(nums.begin(), nums.end());

        int ans = gcd(smallNum, largeNum);
        return ans; 
    }
};