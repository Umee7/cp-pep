#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void findSubsets(int index, vector<int> &temp, vector<vector<int>> &result, vector<int> &nums) {
            // Base Case    
            if(index == nums.size()) {
                result.push_back(temp);
                return;
            } 
            // Pick Case
            temp.push_back(nums[index]);
            findSubsets(index + 1, temp, result, nums);
    
            //backtrack
            temp.pop_back();
    
            //check duplicates
            while(index+1 < nums.size() && nums[index] == nums[index+1]) index++;
    
            // Not Pick
            findSubsets(index + 1, temp, result, nums);
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            vector<int> temp;
    
            findSubsets(0, temp, result, nums);
            return result;
        }
    };