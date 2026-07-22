// 1431. Kids With the Greatest Number of Candies
// Difficulty: Easy
// Topics: Array
// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int n=candies.size();
        vector<bool> ans(n,false);

        int maxCandy= *max_element(candies.begin(),candies.end());

     
        for(int i=0;i<n;i++)
        {
            int curMax=(candies[i]+extraCandies);
            if(curMax >= maxCandy)
                ans[i] = !ans[i];
        }
        return  ans; 
    }
};