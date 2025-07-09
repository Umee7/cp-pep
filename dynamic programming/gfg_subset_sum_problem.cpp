#include<bits/stdc++.h>
using namespace std;


// Memoisation
class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          vector<vector<int>>  dp(arr.size(), vector<int>(sum + 1, -1));
          return findSubset(0, sum, arr, dp);
      }
      
      bool findSubset(int index, int sum, vector<int> &arr,vector<vector<int>> &dp) {                 
          if(sum == 0) return true;
          if(index == arr.size()) return false;
          if(sum < 0) return false;
         
          // Pick 
          if(dp[index][sum] != -1) return dp[index][sum];
          bool pick = findSubset(index + 1, sum - arr[index], arr, dp);
          
          // Not Pick 
          bool notPick = findSubset(index + 1, sum, arr, dp);
          
          return dp[index][sum] =  (pick || notPick);
      }
  };

// memoisation reverse
class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          vector<vector<int>>  dp(arr.size(), vector<int>(sum + 1, -1));
          return findSubset(arr.size() - 1, sum, arr, dp);
      }
      
      bool findSubset(int index, int sum, vector<int> &arr,vector<vector<int>> &dp) {                 
          if(sum == 0) return true;
          if(index == -1) return false;
          if(sum < 0) return false;
         
          // Pick 
          if(dp[index][sum] != -1) return dp[index][sum];
          bool pick = findSubset(index - 1, sum - arr[index], arr, dp);
          
          // Not Pick 
          bool notPick = findSubset(index - 1, sum, arr, dp);
          
          return dp[index][sum] =  (pick || notPick);
      }
  };