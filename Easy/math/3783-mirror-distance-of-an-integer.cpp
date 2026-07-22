// 3783. Mirror Distance of an Integer
// Difficulty: Easy
// Topics: Math
// Link: https://leetcode.com/problems/mirror-distance-of-an-integer/

class Solution {
public:
    int mirrorDistance(int n) {
       long long rev=0;
    for(int x=n; x; x/=10){
        rev=10*rev+x%10;
    }
    return abs(rev-n); 
    }
};