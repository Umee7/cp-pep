#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        // Recursion
        int rob(vector<int>& nums) {
            int n = nums.size() - 1;
            return robHouse(n, nums);
        }
    
        int robHouse(int n, vector<int> nums) {
            if(n == 0 ) return nums[0];
            if(n == - 1) return 0;
    
            int pick = nums[n] + robHouse(n-2, nums);
            int notPick = robHouse(n-1, nums);
    
            return max(pick, notPick);
        }

        //tabulation

        class Solution {
            public:
                int rob(vector<int>& nums) {
                    int n = nums.size();
                    vector<int> dp(n);
                    return robHouse(n, dp, nums);
                }
            
                int robHouse(int n, vector<int> &dp, vector<int>& nums) {
                    dp[0] = nums[0];
            
                    for(int i = 1; i < dp.size(); i++) {
                        int pick = nums[i] + (i >= 2 ? dp[i - 2] : 0);
                        int notPick = dp[i-1];
            
                        dp[i] = max(pick, notPick);
                    }
            
                    return dp[dp.size() - 1];
                }
            };
    };