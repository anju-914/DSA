// 1260. Shift 2D Grid
// Difficulty: Easy
// Topics: Array, Matrix, Simulation
// Link: https://leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>>temp(m,vector<int>(n,0));
      for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            int newVal = ((r*n +c)+k ) % (m*n);
            int newrow = newVal/n;
            int newcol = newVal%n;

            temp[newrow][newcol] = grid[r][c];
        }
      }
      return temp;  
    }
};