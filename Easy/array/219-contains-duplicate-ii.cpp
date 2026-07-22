// 219. Contains Duplicate II
// Difficulty: Easy
// Topics: Array, Hash Table, Sliding Window
// Link: https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mp;
        for(int i= 0;i<n;i++){
            if(mp.find(nums[i]) !=mp.end()&&abs(mp[nums[i]]-i) <=k){
                return true;
            }else{
                mp[nums[i]] =i;
            }
        }
        return false;
    }
};