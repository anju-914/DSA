// 1665. Minimum Initial Energy to Finish Tasks
// Difficulty: Hard
// Topics: Array, Greedy, Sorting
// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

constexpr int M=1e4;
int Sum[M]={0};
class Solution {
public:
       static int minimumEffort(vector<vector<int>>& tasks) {
        const int n=tasks.size();
        int dMin=M, dMax=0;
        for(const auto& t: tasks){
            const int a=t[0], d=t[1]-a;
            Sum[d]+=a;
            dMin=min(dMin, d);
            dMax=max(dMax, d);
        }
        int energy=0;
        for(int d=dMin; d<=dMax; d++){
            if (Sum[d]==0) continue;
            energy=max(energy+Sum[d], Sum[d]+d);
        }
        // reset for the next testcase
        memset(Sum+dMin, 0, (dMax+1-dMin)*sizeof(int));
        return energy; 
    }
};