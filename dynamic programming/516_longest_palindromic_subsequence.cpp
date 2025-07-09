#include<bits/stdc++.h>
using namespace std;

//Recursion with o(n) auxiliary space
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            return findLPS(s, s2, 0, 0);
        }
    
        int findLPS(string &s, string &s2, int i, int j) {
            if(i == s.size() || j == s2.size()) return 0;
            if(s[i] == s2[j]) {
                return 1 + findLPS(s, s2, i + 1, j + 1);
            } else {
                return max(findLPS(s, s2, i + 1, j), findLPS(s, s2, i, j + 1));
            }
        }
    };
//Recursion without o(n) auxiliary space

class Solution {
    public:
        int longestPalindromeSubseq(string s) {

            return findLPS(s, 0, s.size() - 1);
        }
    
        int findLPS(string &s, int i, int j, vector<vector<int>> &dp) {
            if(i == j) return 1;
            if(i > j) return 0;
    
            if(s[i] == s[j]) {
                return  2 + findLPS(s, i + 1, j - 1);
            } else {
                return  max(findLPS(s,i + 1, j), findLPS(s, i, j - 1));
            }
        }
    };

// Memoisation

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            vector<vector<int>> dp(s.size(), vector<int>(s2.size(), -1));
            return findLPS(s, s2, 0, 0, dp);
        }
    
        int findLPS(string &s, string &s2, int i, int j, vector<vector<int>> &dp) {
            if(i == s.size() || j == s2.size()) return 0;
    
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == s2[j]) {
                return dp[i][j] = 1 + findLPS(s, s2, i + 1, j + 1, dp);
            } else {
                return dp[i][j] = max(findLPS(s, s2, i + 1, j, dp), findLPS(s, s2, i, j + 1, dp));
            }
        }
    };

// memoisation without extra auxiliary space
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
    
            vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
            return findLPS(s, 0, s.size() - 1, dp);
        }
    
        int findLPS(string &s, int i, int j, vector<vector<int>> &dp) {
            if(i == j) return 1;
            if(i > j) return 0;
    
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == s[j]) {
                return dp[i][j] = 2 + findLPS(s, i + 1, j - 1, dp);
            } else {
                return dp[i][j] = max(findLPS(s,i + 1, j, dp), findLPS(s, i, j - 1, dp));
            }
        }
    };