class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        map<int, int> m;
    multiset<int> sizes;
    vector<int> res;
    auto insert = [&](int i, int sz) { 
        sizes.insert(sz);
        return m.insert({i, sz}).first;
    };
    auto replace = [&](auto p, int new_sz) {
        sizes.erase(sizes.find(p->second));
        sizes.insert(new_sz);
        p->second = new_sz;
    };
    auto erase = [&](auto p) {
        sizes.erase(sizes.find(p->second));
        m.erase(p);
    };    
    auto p = end(m);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i - 1] != s[i])
            p = m.insert({i, 1}).first;
        else
            ++p->second;
    }
    for (auto [i, size] : m)
        sizes.insert(size);
    for (int j = 0; j < queryCharacters.size(); ++j) {
        char ch = queryCharacters[j];
        int i = queryIndices[j];
        if (ch != s[i]) {   
            s[i] = ch;
            auto p = m.lower_bound(i);
            if (i > 0 && (p == end(m) || p->first > i)) { // break left
                p = insert(i, prev(p)->second - (i - prev(p)->first));
                replace(prev(p), i - prev(p)->first);
            }      
            if (p->second > 1) { // break right
                insert(i + 1, p->second - 1);
                replace(p, 1);
            }
            if (i < s.size() - 1 && ch == s[i + 1]) { // join right
                replace(p, next(p)->second + 1);
                erase(next(p));
            }
            if (i > 0 && s[i - 1] == ch) { // join left
                replace(prev(p), prev(p)->second + p->second);
                erase(p);
            }                
        }
        res.push_back(*rbegin(sizes));
    };
    return res;
    }
};