

// Recursion 
class Solution {
public:
    int findMinimumPath(vector<vector<int>> &grid, int m, int n, int i, int j) {
        
        // Negative Base Case
        if( i >= m || j >= n ) return INT_MAX;

        // Base Case
        if(i == m - 1 && j == n - 1)return grid[i][j];
        
        int down = findMinimumPath(grid, m, n, i + 1, j);
        int right = findMinimumPath(grid, m, n, i, j + 1);
        return grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return findMinimumPath(grid, grid.size(), grid[0].size(), 0, 0);
    }
}; 

// Memoisation

class Solution {
public:
    int findMinimumPath(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &dp) {
        
        // Negative Base Case
        if( i >= m || j >= n ) return INT_MAX;

        // Base Case
        if(i == m - 1 && j == n - 1)return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int down = findMinimumPath(grid, m, n, i + 1, j, dp);
        int right = findMinimumPath(grid, m, n, i, j + 1, dp);
        return dp[i][j] =  grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return findMinimumPath(grid, grid.size(), grid[0].size(), 0, 0, dp);
    }
};

//Tabulation 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int j = 1; j < grid[0].size(); j++) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};