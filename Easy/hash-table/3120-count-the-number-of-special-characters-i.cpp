// 3120. Count the Number of Special Characters I
// Difficulty: Easy
// Topics: Hash Table, String
// Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/

class Solution {
public:
    int numberOfSpecialChars(string word) {
       bitset<26> a=0, A=0;
        for(char c: word){
            if (c>='a') a[c-'a']=1;
            else A[c-'A']=1;
        }
        a=a&A;
        return a.count(); 
    }
};