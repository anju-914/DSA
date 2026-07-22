// 3612. Process String with Special Operations I
// Difficulty: Medium
// Topics: String, Simulation
// Link: https://leetcode.com/problems/process-string-with-special-operations-i/

class Solution {
public:
    string processStr(string s) {
      string ans = "";
        for(int i=0; i< s.size() ;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
            }else if(s[i] == '*' && !ans.empty()){
                ans.erase(ans.size()-1,1);
            }else if(s[i] == '#'){
                ans += ans;
            }else if(s[i] == '%'){
                reverse(ans.begin(), ans.end());
            }
            cout<<ans<<" ";
        }

        return ans; 
    }
};