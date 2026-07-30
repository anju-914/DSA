class Solution {
public:
    int gcd(int a,int b){
        for(int i=min(a,b);i>=i;i--){
            if(a%i==0 && b%i==0){
                return i;
            }

        }
        return -1;
    }
    int findGCD(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return gcd(nums[0],nums[nums.size()-1]);    
    }
};