// 1344. Angle Between Hands of a Clock
// Difficulty: Medium
// Topics: Math
// Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    typedef double d; 
    double angleClock(int hour, int minutes) {
         d minuteAngle = minutes * 6; 
        d hourAngle = hour * 30 + minutes * 0.5; 

        d x = abs(hourAngle - minuteAngle); 
        d mini = min(x , 360-x); 

        return mini; 
    }
};