#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void getParenthesis(string temp, vector<string> &result, int n, int openCount, int closeCount) {
            if(temp.size() ==  (2 * n)) {
                result.push_back(temp);
                return;
            }
    
            // Open case 
            if(openCount < n) {
                temp.push_back('(');
                getParenthesis(temp, result, n, openCount + 1, closeCount);
                // backtracking
                temp.pop_back();
            }
            
    
            // Close case
            if(closeCount < openCount) {
                temp.push_back(')');
                getParenthesis(temp, result, n, openCount, closeCount + 1);
                // backtracking
                temp.pop_back();
            }
            
    
            
        }
    
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string temp = "";
            getParenthesis(temp, result, n, 0, 0);
            return result;
        }
    };