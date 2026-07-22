// 3534. Path Existence Queries in a Graph II
// Difficulty: Hard
// Topics: Array, Two Pointers, Binary Search, Dynamic Programming, Greedy, Bit Manipulation, Graph Theory, Sorting
// Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>>jumps(n, vector<int>(18, -1));
        unordered_map<int,int>mp;
        vector<pair<int,int>>v(n);
        for(int a=0;a<n;a++)v[a] = {nums[a], a};
        sort(v.begin(), v.end());
        int idx=0;
        for(int a=1;a<n;a++){
            while(idx<n && v[a].first-v[idx].first>maxDiff)idx++;
            if(v[idx].first + maxDiff >= v[a].first)
                jumps[a][0] = idx;
            mp[v[a].second]=a;
        }
        for(int b=1;b<=17;b++){
            for(int a=0;a<n;a++){
                if(jumps[a][b-1]!=-1 && jumps[a][b-1]!=jumps[jumps[a][b-1]][b-1])
                jumps[a][b] = jumps[jumps[a][b-1]][b-1];
            }
        }
        vector<int>ans;
        for(auto it:queries){
            int cnt=0;
            int idx1=mp[it[0]], idx2 = mp[it[1]];
            if(idx1>idx2)swap(idx1, idx2);
            if(idx1==idx2){ans.push_back(0);continue;}
            int maxJ=-1;
            // cout<<idx2<<" "<<idx1<<endl;
            for(int a=17;a>=0;a--){
                if(jumps[idx2][a]!=-1 && jumps[idx2][a] > idx1){
                    cnt+=(1<<(a));
                    // cout<<idx2<<" "<<jumps[idx2][a]<<" "<<a<<endl;
                    idx2 = jumps[idx2][a];
                } 
            }
            // cout<<"F "<<idx2<<" "<<idx1<<" "<<cnt<<" "<<jumps[idx2][0]<<endl;
            if(jumps[idx2][0] <= idx1){cnt++;ans.push_back(cnt);}
            else ans.push_back(-1);
        }
        return ans;
    }
};