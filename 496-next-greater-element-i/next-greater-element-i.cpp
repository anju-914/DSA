class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int,int>mp;
        vector<int>res;

        for(int curr : nums2){
            if(st.empty()){
                st.push(curr);
                continue;
            }
            while(!(st.empty()) && curr > st.top()){
                mp[st.top()] = curr;
                st.pop();
            }
            st.push(curr);
        }
        for(int curr : nums1){
            if(mp.find(curr) == mp.end()){
                res.push_back(-1);
            }

            else {
                res.push_back(mp[curr]);
            }
        }

        return res;
    }
};