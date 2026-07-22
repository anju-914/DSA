// 3620. Network Recovery Pathways
// Difficulty: Hard
// Topics: Array, Binary Search, Dynamic Programming, Graph Theory, Topological Sort, Heap (Priority Queue), Shortest Path
// Link: https://leetcode.com/problems/network-recovery-pathways/

bool check(int mid,vector<vector<pair<int,int>>> &adj,  vector<int> &topo, 
 vector<bool> &online, long long k, int n)
 {
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;


    for(auto node : topo)
    {
        if(node != 0 && node != n-1 && !online[node])
        continue;
        if(dist[node] == LLONG_MAX) continue;

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;


            if(wt < mid) continue;
            if(adjNode != n-1 && !online[adjNode])
            {
                continue;
            }

            dist[adjNode] = min(dist[adjNode] , wt + dist[node]);
        }
    }

    return dist[n-1] <= k;

 }


void dfs(int node, vector<vector<pair<int, int>>>& adj, stack<int>& st,
         vector<int>&vis) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        int adjNode = it.first;
        if (!vis[adjNode]) {
            dfs(adjNode, adj, st, vis);
        }
    }
    st.push(node);
}

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int maxEdge = 0;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v, cost});

             maxEdge = max(maxEdge, cost);
        }

        stack<int> st;
        vector<int>vis(n,0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, st, vis);
            }
        }

        vector<int>topo;

        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }

        int low = 0 ;
        int high = maxEdge;
        int ans = -1;

        while(low <= high )
        {
            int mid = low + (high - low)/2;

            if(check(mid , adj , topo , online ,k , n))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return ans;
 
    }
};