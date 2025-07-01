#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool findWord(int currentIndex, vector<vector<char>> &board, int row, int col, string word) {
            // Base case
            if(currentIndex == word.size()) {
                return true;
            }
    
            // Negative Base
            if(row < 0 || col < 0 || row == board.size() || col == board[0].size() || board[row][col] != word[currentIndex] ) return false;
    
            char ch = board[row][col];
            board[row][col] = '@';
    
            bool up = findWord(currentIndex + 1, board, row - 1, col, word);
            bool down = findWord(currentIndex + 1, board, row + 1, col, word);
            bool left = findWord(currentIndex + 1, board, row , col - 1, word);
            bool right = findWord(currentIndex + 1, board, row, col + 1, word);
    
    
            return up || down || left || right;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            // Find First letter of Word
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {
                    //If first digit found lets do recursive call
                    if(findWord(0, board, i, j, word)) return true;
                    
                }
                
            }
            return false;
            
        }
    };