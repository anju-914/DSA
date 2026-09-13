class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>pos1,pos2;

        for(int i = 0 ; i<n; i++){
            for(int j = 0; j<n; j++){
                if(img1[i][j]==1)pos1.push_back({i,j});
                if(img2[i][j]==1)pos2.push_back({i,j});
            }
        }

        map<pair<int,int>,int> freq;

        int maxi = 0;
        int x = pos1.size();
        int y = pos2.size();

        for(int i = 0; i<x;i++){
            for(int j = 0; j<y; j++){
                int a = pos1[i].first - pos2[j].first;
                int b = pos1[i].second - pos2[j].second;

                freq[{a,b}]++;
                maxi = max(maxi,freq[{a,b}]);
            }
        }

        return maxi;
    }
};