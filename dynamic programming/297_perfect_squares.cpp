#include<bits/stdc++.h>
using namespace std;

// Recursion

class Solution {
    public:
        int numSquares(int n) {
            if(n == 0) return 0;
    
            int ans = INT_MAX;
            return findPerfectSquares(n);
    
            for(int i = 1; i*i <= n; i++) {
                ans = min(ans, 1+numSquares(n-i*i));
            }
            return ans;
        }
    };


// memoisation

class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n+1, -1);
    
            return findSquares(n, dp);
        }
        int findSquares(int n, vector<int> &dp) {
            if(n == 0) return 0;
    
    
            int ans = INT_MAX;
            if(dp[n]!=-1) return dp[n];
    
            for(int i = 1; i*i <= n; i++) {
                ans = min(ans, 1+findSquares(n-i*i, dp));
            }
            return dp[n] = ans;
        }
    };

// Tabulation
class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n+1, INT_MAX);
            
            return findSquares(n, dp);
        }
        int findSquares(int n, vector<int> &dp) {
            if(n == 0) return 0;
            dp[0] = 0;
    
    
            for(int i = 1; i < dp.size(); i++) {
                for(int j = 1; j*j <= i; j++) {
                    dp[i] = min(dp[i], 1+dp[i-j*j]);
                }
            }
            return dp[n];
        }
    };