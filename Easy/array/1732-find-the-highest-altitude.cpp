// 1732. Find the Highest Altitude
// Difficulty: Easy
// Topics: Array, Prefix Sum
// Link: https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      vector<int> altitude = {0};
        for (int i_gain : gain){
            altitude.push_back(altitude.back() + i_gain);
        }
        int max_altitude = 0;
        for (int alt : altitude){
            if (alt > max_altitude){
                max_altitude = alt;
            }
        }

        return max_altitude;
    }
};