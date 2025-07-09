#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            return findLines(nums1, nums2, 0, 0);
        } 
    
        int findLines(vector<int> &nums1, vector<int> &nums2, int i , int j) {
            if(i ==  nums1.size() || j == nums2.size()) {
                return 0;
            }
    
            if(nums1[i] == nums2[j]) {
                return 1 + findLines(nums1, nums2, i + 1, j + 1); 
            } else {
                return max(findLines(nums1, nums2, i + 1, j), findLines(nums1, nums2, i , j + 1));
            }
    
        }
    };

// Memoisation bottom up

class Solution {
    public:
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
            return findLines(nums1, nums2, 0, 0, dp);
        } 
    
        int findLines(vector<int> &nums1, vector<int> &nums2, int i , int j, vector<vector<int>> &dp) {
            if(i ==  nums1.size() || j == nums2.size()) {
                return 0;
            }
    
            if(dp[i][j] != - 1) return dp[i][j];
            if(nums1[i] == nums2[j]) {
                return dp[i][j] =  1 + findLines(nums1, nums2, i + 1, j + 1, dp); 
            } else {
                return dp[i][j] =  max(findLines(nums1, nums2, i + 1, j, dp), findLines(nums1, nums2, i , j + 1, dp));
            }
    
        }
    };

// Memoisation bottom up dp[i][j] = max uncrossed Lines from i-th j-th index t

class Solution {
    public:
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
            return findLines(nums1, nums2, nums1.size() - 1, nums2.size()  - 1, dp);
        } 
    
        int findLines(vector<int> &nums1, vector<int> &nums2, int i , int j, vector<vector<int>> &dp) {
            if(i == -1 || j == -1) {
                return 0;
            }
    
            if(dp[i][j] != - 1) return dp[i][j];
            if(nums1[i] == nums2[j]) {
                return dp[i][j] =  1 + findLines(nums1, nums2, i - 1, j - 1, dp); 
            } else {
                return dp[i][j] =  max(findLines(nums1, nums2, i - 1, j, dp), findLines(nums1, nums2, i , j - 1, dp));
            }
    
        }
    };