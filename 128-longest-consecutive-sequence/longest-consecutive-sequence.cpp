class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int currConsSeq = 1;
        int longConsSeq = 0;

        for(int i = 1; i<n;i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currConsSeq++;
                }
                else{
                    longConsSeq = max(longConsSeq , currConsSeq);
                    currConsSeq = 1;
                }
            }
        }

        return max(currConsSeq, longConsSeq);
    }
};