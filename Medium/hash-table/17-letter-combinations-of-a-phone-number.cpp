// 17. Letter Combinations of a Phone Number
// Difficulty: Medium
// Topics: Hash Table, String, Backtracking
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    unordered_map<int,string> m1 = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

    void backtrack(vector<string>& ans, string& temp, int n, int index, string digits){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i<m1[digits[index]-'0'].size(); i++){
            temp += m1[digits[index]-'0'][i];
            backtrack(ans,temp,n,index+1,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        string temp = "";
        backtrack(ans,temp,n,0,digits);
        return ans;
    }
};