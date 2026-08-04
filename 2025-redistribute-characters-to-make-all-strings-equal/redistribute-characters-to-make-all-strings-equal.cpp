class Solution {
public:
    bool makeEqual(vector<string>& words) {
         int len= words.size();
        unordered_map<char,int> mp;
        for(int i=0;i<words.size();i++)
        {
            for(auto j: words[i])
            {
                mp[j]++;
            }
        }
        for(auto i: mp)
        {
            if( i.second % len != 0 )
            {
                return false;
            }
        }
        return true;
    }
};