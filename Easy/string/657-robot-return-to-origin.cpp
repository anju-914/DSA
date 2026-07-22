// 657. Robot Return to Origin
// Difficulty: Easy
// Topics: String, Simulation
// Link: https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int H=0, V=0;
        for(char c: moves){
            H+=(c=='R');
            H-=(c=='L');
            V+=(c=='U');
            V-=(c=='D');
        }
        return (H==0) & (V==0);
    }
};