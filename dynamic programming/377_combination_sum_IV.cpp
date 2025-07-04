#include<bits/stdc++.h>
using namespace std;

// Recursion 
int combinationSum4(vector<int>& nums, int target) {
    return comSum(target, nums);
}

int comSum(int target, vector<int> nums) {
    if(target == 0) return 1;
    if(target < 0) return 0;

    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        count += comSum(target - nums[i], nums);
    }

    return count;
}

// Memoisation

class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target + 1, -1);
            return comSum(target, nums, dp);
        }
    
        int comSum(int target, vector<int> &nums, vector<int> &dp) {
            if(target == 0) return 1;
            if(target < 0) return 0;
    
    
    
            int count = 0;
    
            if(dp[target]!=-1) return dp[target];
    
    
            for(int i = 0; i < nums.size(); i++) {
                count += comSum(target - nums[i], nums,dp);
            }
    
            return dp[target] =  count;
        }
    };

    // Tabulation

    int comSum(int target, vector<int> &nums, vector<int> &dp) {
        if(target < 0) return 0;
        if(target == 0) return nums[0];

        dp[0] = 1;

        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i-nums[j] >= 0) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }