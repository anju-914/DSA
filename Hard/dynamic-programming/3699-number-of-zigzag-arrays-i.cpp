// 3699. Number of ZigZag Arrays I
// Difficulty: Hard
// Topics: Dynamic Programming, Prefix Sum
// Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/

const int N=2003;
const int mod=1e9+7;
int dp[N][N][2];
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {  
        // 1<=i<=n
        // l<=k<=r
        // dp[i][k][0]=pref[1][r]-pref[1][k];
        // dp[i][k][1]=pref[0][k-1]-pref[0][l-1];
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>pref(2,vector<int>(r+1));
        vector<vector<int>>curr(2,vector<int>(r+1));
        for(int i=1;i<=n;i++){
            for(int k=l;k<=r;k++){
                if(i==1){
                    dp[i][k][0]=dp[i][k][1]=1;
                }else{
                    dp[i][k][0]=(pref[1][r]-pref[1][k]+mod)%mod;
                    dp[i][k][1]=(pref[0][k-1]-pref[0][l-1]+mod)%mod;
                }
                curr[0][k]=(curr[0][k-1]+dp[i][k][0])%mod;
                curr[1][k]=(curr[1][k-1]+dp[i][k][1])%mod;
            }
            swap(pref,curr);
            curr.assign(2,vector<int>(r+1,0));
        }
        return (pref[0][r]+pref[1][r])%mod;
    }
};