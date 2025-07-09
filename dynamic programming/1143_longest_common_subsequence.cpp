#include<bits/stdc++.h>
using namespace std;
    

// recursion
    class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            return findCS(text1, text2, 0, 0) ;
        }
    
        int findCS(string text1, string text2, int i, int j) {
            
            if( i == text1.size() || j == text2.size()) return 0;
            if(text1[i] == text2[j]) {  
                return 1 + findCS(text1, text2, i + 1, j + 1);
            } else{
                return max(findCS(text1, text2, i+1, j), findCS(text1, text2, i, j+1));
            }
        }
    };

// Memoisation 
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
            return LCS(0, 0, text1, text2, dp);
        }
        int LCS(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
            // Basecase
            if(i == text1.size() || j == text2.size()) return 0;
            // equals case
            if(dp[i][j] != -1) return dp[i][j];
            if(text1[i] == text2[j]) {
                return dp[i][j] =  1 + LCS(i + 1, j + 1, text1, text2, dp);
            } 
            // not equals case
            else {
                return dp[i][j] =  max(LCS(i + 1, j, text1, text2, dp), LCS(i, j + 1, text1, text2, dp));
            }
        }
    };
    
// Memoisation reverse
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
            return LCS(text1.size() - 1, text2.size() - 1, text1, text2, dp);
        }
        int LCS(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
            // Basecase
            if(i < 0 || j < 0) return 0;
            // equals case
            if(dp[i][j] != -1) return dp[i][j];
            if(text1[i] == text2[j]) {
                return dp[i][j] =  1 + LCS(i - 1, j - 1, text1, text2, dp);
            } 
            // not equals case
            else {
                return dp[i][j] =  max(LCS(i - 1, j, text1, text2, dp), LCS(i, j - 1, text1, text2, dp));
            }
        }
    };
