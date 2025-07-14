#include<bits/stdc++.h>
using namespace std;

// Memoisation

class Solution {
public:
    int findPaths(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // Negative Base Case 
        if(m >= grid.size()  || n >= grid[0].size()) return 0;
        if(grid[m][n] == 1) return 0;

        // Base Case
        if(m == grid.size() - 1 && n == grid[0].size() - 1) return 1;

        if(dp[m][n] != -1) return dp[m][n];
        // Bottom 
        int bottom = findPaths(m + 1, n, grid, dp);

        // Right
        int right = findPaths(m, n + 1, grid, dp); 

        return dp[m][n] = bottom + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return findPaths(0, 0, obstacleGrid, dp);
    }
};

// Tabulation 

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        dp[0][0] = 1;

        for(int i = 1; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i < obstacleGrid[0].size(); i++) {
            if(obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }

        for(int i = 1; i < obstacleGrid.size(); i++) {
            for(int j = 1; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    int way1 = dp[i-1][j];
                    int way2 = dp[i][j-1];
                    dp[i][j] = way1 + way2;
                }
            }
        }
        
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};