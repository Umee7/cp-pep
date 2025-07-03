#include<bits/stdc++.h>
using namespace std;


// Memoisation way
class Solution {
    public:
        int findFib(int n, vector<int> &dp) {
            if(n == 0 || n == 1) return n;
            if(dp[n] != -1) {
                return dp[n];
            }
            return dp[n] = findFib(n-1, dp) + findFib(n-2, dp);
        }
    
        int fib(int n) {
            vector<int> dp(n+1, -1);
            return findFib(n, dp);
        }
    };

// Tabulation
    class Solution {
        public:
            int fib(int n) {
                vector<int> dp(n+1);
                return findFib(n, dp);
            }
        
            int findFib(int n, vector<int> dp) {
                if(n == 0 || n == 1) return n;
        
                dp[0] = 0;
                dp[1] = 1;
        
                for(int i = 2; i < dp.size(); i++) {
                    dp[i] = dp[i-1] + dp[i-2];
                }
        
                return dp[dp.size() - 1];
            }
        };