class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;vector<int>a;
        for(char c:seq)a.push_back(c=='('?d++&1:--d&1);
        return a;
    }
};