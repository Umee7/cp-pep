#include<bits/stdc++.h>
using namespace std;

// Recursion 
class Solution {
    public:
    int allPaths(int m, int n, int i, int j) {
        // Negative Base Case 
        if(i >= m  || j >= n) return 0;

        // Base Case
        if(i == m - 1 && j == n - 1) return 1;

        
        // Bottom 
        int bottom = allPaths(m, n, i + 1, j);

        // Right 
        int right = allPaths(m, n, i, j + 1);

        return bottom + right;
    }
    int uniquePaths(int m, int n) {
        return allPaths(m, n, 0, 0);
    }
}

// Memoisation
    class Solution {
        public:
        int allPaths(int m, int n, int i, int j, vector<vector<int>> &dp) {
            // Negative Base Case 
            if(i >= m  || j >= n) return 0;

            // Base Case
            if(i == m - 1 && j == n - 1) return 1;

            if(dp[i][j] != -1) return dp[i][j];

            // Bottom 
            int bottom = allPaths(m, n, i + 1, j, dp);

            // Right 
            int right = allPaths(m, n, i, j + 1, dp);

            return bottom + right;
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return allPaths(m, n, 0, 0, dp);
        }
    }

// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = 1;

        for(int i = 1; i < m; i ++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i < n; i++) {
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                int way1 = dp[i-1][j];
                int way2 = dp[i][j-1];
                dp[i][j] = way1 + way2;
            }
        }

        return dp[m-1][n-1];
    }
};