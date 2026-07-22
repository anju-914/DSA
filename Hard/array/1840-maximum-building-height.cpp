// 1840. Maximum Building Height
// Difficulty: Hard
// Topics: Array, Math, Sorting
// Link: https://leetcode.com/problems/maximum-building-height/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
    
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1}); 
        
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        for (int i = 1; i < m; i++) {
            int id_diff = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], 
                                    restrictions[i-1][1] + id_diff);
        }
        
        for (int i = m - 2; i >= 0; i--) {
            int id_diff = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], 
                                    restrictions[i+1][1] + id_diff);
        }
        
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int id1 = restrictions[i-1][0];
            int h1  = restrictions[i-1][1];
            int id2 = restrictions[i][0];
            int h2  = restrictions[i][1];
            
            // Max height between id1 and id2:
            // Go up from both sides, peak = (h1 + h2 + gap) / 2
            int gap = id2 - id1;
            int peak = (h1 + h2 + gap) / 2;
            
            ans = max(ans, peak);
        }
        
        return ans;
    }
};