#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int bSubsets(int index, vector<int>& temp, vector<int>& nums,
                            int k) {
            // Base Case
            if (index == nums.size())
                return 1;
    
            int pick = 0;
            // Case to pick
            if ((find(temp.begin(), temp.end(), nums[index] + k) == temp.end()) &&
                (find(temp.begin(), temp.end(), nums[index] - k) == temp.end())) {
                temp.push_back(nums[index]);
                pick = bSubsets(index + 1, temp, nums, k);
                // Backtracking
                temp.pop_back();
            }
    
            
            int notPick = 0;
            // Not pick Case
            notPick = bSubsets(index + 1, temp, nums, k);
    
            return pick + notPick;
        }
    
        int beautifulSubsets(vector<int>& nums, int k) {
            vector<int> temp;
            return bSubsets(0, temp, nums, k) - 1;
        }
    };