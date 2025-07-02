#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxR = 0;
        void maxRequests(int index, int count, vector<int> &temp, vector<vector<int>> &requests) {
            // Base Case
            if(index == requests.size()) {
                for(int num : temp) {
                    if(num != 0) return;
                }
                maxR = max(maxR, count);
                return;
            }
    
            int from = requests[index][0];
            int to = requests[index][1];
    
            // process
            temp[from]--;
            temp[to]++;
            maxRequests(index + 1, count + 1, temp, requests);
    
            // Backtrack
            temp[from]++;
            temp[to]--;
            maxRequests(index + 1, count, temp, requests);
        }
    
        int maximumRequests(int n, vector<vector<int>>& requests) {
            vector<int> temp(requests.size());
            int count = 0;
            maxRequests(0, count, temp, requests);
            return maxR;
        }
    };