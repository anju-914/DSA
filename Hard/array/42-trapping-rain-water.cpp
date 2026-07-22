// 42. Trapping Rain Water
// Difficulty: Hard
// Topics: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
// Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftmax(height.size());
    vector<int>rightmax(height.size());
    
    leftmax[0] = height[0];
    rightmax[height.size()-1] = height[height.size()-1];

    int i=1,j=height.size()-2;
    while(i<height.size() && j>0) {
       leftmax[i] = max(leftmax[i-1],height[i]);
       rightmax[j] = max(rightmax[j+1],height[j]);
       i++,j--;
    }

    int trappedWater = 0;
    for(int i=0; i<height.size(); i++){
        int currWater = min(leftmax[i],rightmax[i]) - height[i];
        if(currWater > 0){
            trappedWater += currWater;
        }
    }

      return trappedWater;
    }
};