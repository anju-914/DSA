// 3633. Earliest Finish Time for Land and Water Rides I
// Difficulty: Easy
// Topics: Array, Two Pointers, Binary Search, Greedy, Sorting
// Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirstEnd = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            landFirstEnd = min(landFirstEnd,
                               landStartTime[i] + landDuration[i]);
        }

        int finish1 = INT_MAX;

        for (int i = 0; i < waterStartTime.size(); i++) {
            finish1 = min(finish1,
                          max(landFirstEnd, waterStartTime[i]) +
                          waterDuration[i]);
        }

        int waterFirstEnd = INT_MAX;

        for (int i = 0; i < waterStartTime.size(); i++) {
            waterFirstEnd = min(waterFirstEnd,
                                waterStartTime[i] + waterDuration[i]);
        }

        int finish2 = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            finish2 = min(finish2,
                          max(waterFirstEnd, landStartTime[i]) +
                          landDuration[i]);
        }

        return min(finish1, finish2);
    }
};