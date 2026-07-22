// 1020. Number of Enclaves
// Difficulty: Medium
// Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Link: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        int cnt = 0;

        // single traversal
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 1){

                    // boundary → BFS source
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        q.push({i,j});
                        grid[i][j] = '#';
                    }
                    else{
                        // count only internal land
                        cnt++;
                    }
                }
            }
        }

        // BFS
        auto bfs = [&]() {
            while(!q.empty()){
                auto [i,j] = q.front();
                q.pop();

                for(auto [dx,dy] : dir){
                    int x = i + dx;
                    int y = j + dy;

                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                        grid[x][y] = '#';
                        cnt--; // removing internal land
                        q.push({x,y});
                    }
                }
            }
        };

        bfs();

        return cnt;
    }
};