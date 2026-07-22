// 560. Subarray Sum Equals K
// Difficulty: Medium
// Topics: Array, Hash Table, Prefix Sum
// Link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int result =0;
        int cumSum = 0;
        mp.insert({0,1});

        for(int i =0 ; i<nums.size(); i++ ){
            cumSum +=nums[i];

            if(mp.find(cumSum - k) != mp.end()){
                result += mp[cumSum-k];
            }
            mp[cumSum]++;
        }
        return result;
    }
};