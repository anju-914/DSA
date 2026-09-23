class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int,int> mp;

        mp[0] = -1;

        int sum = 0 ;
        for(int i =0;i<n;i++){
            sum += nums[i];

            mp[sum] = i; //storing in map
        }
        if(sum<x)
        return -1;

        int remainingSum = sum -x;
        int longestSubarray = INT_MIN;
        
        sum = 0;
        for(int i =0 ; i<n; i++){
            sum += nums[i];
            int findSum = sum - remainingSum;

            if(mp.find(findSum) != mp.end()){
                int idx = mp[findSum];

                longestSubarray = max (longestSubarray,i-idx);
            }
        }

        return longestSubarray == INT_MIN ? -1 :n-longestSubarray;
    }
};