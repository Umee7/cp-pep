#include<bits/stdc++.h>
using namespace std;



class Solution {
    public:

        // Recursion 
        int climbStairs(int n) {
            if(n == 1 || n == 2) return n;
            return climbStairs(n-1) + climbStairs(n-2);
        }


        // Tabulation
        int climbStairs(int n) {
            vector<int> dp(n+1);
            return findWays(n, dp);
        }
    
        int findWays(int n, vector<int> &dp) {
            if(n == 1 || n == 2) return n;
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i < dp.size(); i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
    
            return dp[dp.size() - 1];
        }

        
    };