// 3867. Sum of GCD of Formed Pairs
// Difficulty: Medium
// Topics: Array, Math, Two Pointers, Sorting, Simulation, Number Theory
// Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/

class Solution {
    public:
        long long gcdSum(vector<int>& nums) {
                int n=nums.size();
                        vector<int> a(n);
                                int mx=0;
                                        for(int i=0;i<n;i++){
                                                    mx=max(mx,nums[i]);
                                                                a[i]=std::gcd(nums[i],mx);
                                                                        }
                                                                                sort(a.begin(),a.end());
                                                                                        long long ans=0;
                                                                                                int l=0,r=n-1;
                                                                                                        while(l<r){
                                                                                                                    ans+=std::gcd(a[l], a[r]);
                                                                                                                                l++;
                                                                                                                                            r--;
                                                                                                                                                    }
                                                                                                                                                            return ans;
                                                                                                                                                                }
                                                                                                                                                                };