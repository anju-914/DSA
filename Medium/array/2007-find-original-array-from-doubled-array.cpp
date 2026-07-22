// 2007. Find Original Array From Doubled Array
// Difficulty: Medium
// Topics: Array, Hash Table, Greedy, Sorting
// Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) {
            return {};
        }
        sort(changed.begin(), changed.end());
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[changed[i]]++;
        }
        for (int &num : changed){ 
        int twice = 2*num;
          if (mp[num] == 0) continue;
          if (mp.find(twice)==mp.end() || mp[twice] == 0){
           return {};
          }
          ans.push_back(num);
          mp[num]--;
          mp[twice]--;
        }
        return ans;
    }
};