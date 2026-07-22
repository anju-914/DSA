// 3532. Path Existence Queries in a Graph I
// Difficulty: Medium
// Topics: Array, Hash Table, Binary Search, Union-Find, Graph Theory
// Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>ccomp(n,0);
        int curr=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                curr++;

            }
            ccomp[i]=curr;
        }
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            if(ccomp[queries[i][0]]==ccomp[queries[i][1]])ans[i]=true;
            
        }

        return ans;
        
    }
};