class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> count, used;
        for (char &c : s) count[c]++;
        stack<char> st;
        for (char &c : s) {
            if (used[c]) {
                count[c]--;
                continue;
            }
            if (st.empty()) st.push(c);
            else {
                while(!st.empty() && c < st.top() && count[st.top()]) {
                    used[st.top()] = 0;
                    st.pop();
                }
                st.push(c);
            }
            used[c] = 1; count[c]--;
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};