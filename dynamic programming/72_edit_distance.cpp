#include<bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(), n = word2.size();
            return findDistances(0, 0, word1, word2, m, n);
        }
    
        int findDistances(int i, int j, string &word1, string &word2, int m, int n) {
            // Base Case
            if(i == m) return n - j;
            if(j == n) return m - i;
    
            if(word1[i] == word2[j]) {
                return findDistances(i + 1, j + 1, word1, word2, m, n);
            } else {
                int insert = 1 +  findDistances(i, j + 1, word1, word2, m, n);
                int delt = 1 + findDistances(i+1, j, word1, word2, m, n);
                int replace = 1 + findDistances(i+1, j+1, word1, word2, m, n);
    
                return min(insert,  min(delt, replace));
            }
        }
    
    };

//Memoisation 
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(), n = word2.size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return findDistances(0, 0, word1, word2, m, n, dp);
        }
    
        int findDistances(int i, int j, string &word1, string &word2, int m, int n, vector<vector<int>> &dp) {
            // Base Case
            if(i == m) return n - j;
            if(j == n) return m - i;
    
            if(dp[i][j] != -1) return dp[i][j];
            if(word1[i] == word2[j]) {
                return dp[i][j] = findDistances(i + 1, j + 1, word1, word2, m, n, dp);
            } else {
                int insert = 1 +  findDistances(i, j + 1, word1, word2, m, n, dp);
                int delt = 1 + findDistances(i+1, j, word1, word2, m, n, dp);
                int replace = 1 + findDistances(i+1, j+1, word1, word2, m, n, dp);
    
                return dp[i][j] = min(insert,  min(delt, replace));
            }
        }
    
    };

// Memoiosation reverse
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(), n = word2.size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return findDistances(m-1, n-1, word1, word2, m, n, dp);
        }
    
        int findDistances(int i, int j, string &word1, string &word2, int m, int n, vector<vector<int>> &dp) {
            // Base Case
            if(i == -1) return j + 1;
            if(j == -1) return i + 1;
    
            if(dp[i][j] != -1) return dp[i][j];
            if(word1[i] == word2[j]) {
                return dp[i][j] = findDistances(i - 1, j - 1, word1, word2, m, n, dp);
            } else {
                int insert = 1 +  findDistances(i, j- 1, word1, word2, m, n, dp);
                int delt = 1 + findDistances(i - 1, j, word1, word2, m, n, dp);
                int replace = 1 + findDistances(i - 1, j - 1, word1, word2, m, n, dp);
    
                return dp[i][j] = min(insert,  min(delt, replace));
            }
        }
    
    };