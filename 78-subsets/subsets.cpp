class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>subset;

        createSubSet(nums,0,res,subset);
        return res;
    }

    void createSubSet(vector<int>&nums , int index,vector<vector<int>>& res, vector<int>&subset){
        if(index==nums.size()){
            res.push_back(subset);
            return ;
        }

        subset.push_back(nums[index]);
        createSubSet(nums, index+1,res,subset);

        subset.pop_back();
        createSubSet(nums,index+1,res,subset);
    }
};