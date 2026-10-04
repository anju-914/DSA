class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int aMin = 0, aMax= 0;

        for(int i = n-1;i>=0;i--){

            char c = s[i];
            aMin += (c==')') - (c=='(')-(c=='*');
            aMax += (c==')') - (c=='(')+(c=='*');

            if(aMax<0) return 0;
            aMin = max(aMin , 0);
        }

        return aMin == 0;
    }
};