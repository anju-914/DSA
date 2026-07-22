// 2161. Partition Array According to Given Pivot
// Difficulty: Medium
// Topics: Array, Two Pointers, Simulation
// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, more;

        for(int num : nums){
            if(num < pivot) less.push_back(num);
            else if(num == pivot) equal.push_back(num);
            else more.push_back(num);
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), more.begin(), more.end());

        return less;
    }
};