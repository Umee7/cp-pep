#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void findSubsets(int index, set<vector<int>> &subsequences, vector<int> &temp, vector<int> &nums) {
            // Base Case
            if(index == nums.size()){
                if(temp.size() > 1) {
                    subsequences.insert(temp);   
                }
                return;
                
            }
    
           // pick
           if(temp.empty() || nums[index] >= temp.back()) {
                temp.push_back(nums[index]);
                findSubsets(index + 1, subsequences, temp, nums);
                // Backtrack
                temp.pop_back();
           }
    
           // Not Pick
           findSubsets(index + 1, subsequences, temp, nums);
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            set<vector<int>> subsequences;
            vector<int> temp;
    
            findSubsets(0, subsequences, temp, nums);
            
            vector<vector<int>> result(subsequences.begin(), subsequences.end());
            return result;
        }
    };