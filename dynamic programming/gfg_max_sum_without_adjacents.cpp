#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
    public:
      // Recursion
      int findMaxSum(vector<int>& arr) {
          // code here
          int n = arr.size();
          return maxSum(n-1, arr);
      }
      
      int maxSum(int n, vector<int> &arr) {
          if(n < 0) return 0;
          if(n ==0 ) return 1;
          
          int pick  = arr[n] + maxSum(n-2, arr);
          int notPick = maxSum(n-1, arr);
          
          return  max(pick, notPick);
      }

      // Memoization
      int findMaxSum(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(), -1);
        int n = arr.size();
        return maxSum(n-1, arr, dp);
    }
    
    int maxSum(int n, vector<int> &arr, vector<int> &dp) {
        if(n < 0) return 0;
        if(n ==0 ) return arr[0];
        
        if(dp[n] != -1) return dp[n];
        
        
        int pick  = arr[n] + maxSum(n-2, arr, dp);
        int notPick = maxSum(n-1, arr, dp);
        
        return  dp[n] = max(pick, notPick);
    }

    // Tabulation 
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size());
        int n = arr.size();
        return maxSum(n, arr, dp);
    }
    
    int maxSum(int n, vector<int> &arr, vector<int> &dp) {
        if(n == 0 ) return 0;
        if(n == 1) return arr[0];
        
        dp[0] = arr[0];
        
        for(int i = 1; i < dp.size(); i++) {
            int pick = arr[i] + (i>=2 ?  dp[i-2] : 0);
            int notPick = dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[dp.size() - 1];
    };
  };