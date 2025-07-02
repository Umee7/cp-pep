#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minDiff = INT_MAX;
        void findDistributions(int index, vector<int> &temp, vector<int> &cookies, int k) {
            // Base Case
            if(index == cookies.size()) {
                int maxC = INT_MIN;
                for(int num : temp) {
                    maxC = max(maxC, num);
                }
    
                minDiff = min(minDiff, maxC);
                return;
            }
    
            for(int i = 0; i < k; i++) {
                int cookie = cookies[index];
                
                temp[i]+=cookie;
                findDistributions(index + 1, temp, cookies, k);
                temp[i]-=cookie;
            }
        }
    
        int distributeCookies(vector<int>& cookies, int k) {
            vector<int> temp(k);
            findDistributions(0, temp, cookies, k);
            return minDiff;
        }
    };