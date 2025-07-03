#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxGold = INT_MIN;
        void findMaxGold(int row, int col, vector<vector<int>> &grid, int currentGold) {
            if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0) {
                return;
            }
            currentGold += grid[row][col];
            maxGold = max(maxGold, currentGold);
            int val = grid[row][col];
            grid[row][col] = 0;
            // Up
            findMaxGold(row - 1, col, grid, currentGold);
            // Bottom
            findMaxGold(row + 1, col, grid, currentGold);
            // Left
            findMaxGold(row, col - 1, grid, currentGold);
            // Right
            findMaxGold(row, col + 1, grid, currentGold);
    
            grid[row][col] = val;
    
        }
        int getMaximumGold(vector<vector<int>>& grid) {
           for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) {
                    findMaxGold(i, j, grid, 0);
                }
            }
           } 
           return maxGold;
        }
    };