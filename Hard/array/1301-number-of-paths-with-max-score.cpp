// 1301. Number of Paths with Max Score
// Difficulty: Hard
// Topics: Array, Dynamic Programming, Matrix
// Link: https://leetcode.com/problems/number-of-paths-with-max-score/

using ll = int32_t;
using vi = vector<ll>;
constexpr ll INF = 1e7;
class Solution {
    ll dp1[105][105];
    ll dp2[105][105][2000];
    ll getmaxscore(ll cx, ll cy, vector<string>& board){
        if(cx < 0 || cy < 0) return -INF;
        if(board[cx][cy] == 'X') return -INF;
        if(cx+cy==0) return 0;

        if(dp1[cx][cy] != -1) return dp1[cx][cy];
        //go left
        char ch = board[cx][cy];
        ll val = 0;
        if(isdigit(ch)) val = (ll)(ch-'0');
        ll lf = val + getmaxscore(cx-1, cy, board);
        ll up = val + getmaxscore(cx, cy-1, board);
        ll dia = val + getmaxscore(cx-1, cy-1, board);

        return dp1[cx][cy] = max(dia, max(lf, up));
    }

    ll getcnt(ll cx, ll cy, ll cscore, vector<string>& board){
        if(cx < 0 || cy < 0 || cscore < 0) return 0;
        if(board[cx][cy] == 'X') return 0;
        if(cx+cy == 0) return cscore == 0;

        if(dp2[cx][cy][cscore] != -1) return dp2[cx][cy][cscore];

        ll val = (board[cx][cy] == 'S')?0:board[cx][cy]-'0';

        long long lf = getcnt(cx-1, cy, cscore-val, board);
        long long up = getcnt(cx, cy-1, cscore-val, board);
        long long dia = getcnt(cx-1, cy-1, cscore-val, board);

        long long MOD = 1e9+7;
        long long ans = lf;
        ans = (ans + up)%MOD;
        ans = (ans + dia)%MOD;

        return dp2[cx][cy][cscore] = ans;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        ll n = board.size();
        memset(dp1, -1, sizeof(dp1));
        int maxscore = max((ll)0, getmaxscore(n-1, n-1, board));

        //cnt paths with maxscore
        memset(dp2, -1, sizeof(dp2));
        int cnt = getcnt(n-1, n-1, maxscore, board);
        
        return {maxscore, cnt};
    }
};