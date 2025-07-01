#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combSum(int index, int target, vector<int> &temp, vector<vector<int>> &result, vector<int> &candidates) {
        // Positive Base Case
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        // Negative Base Case
        if(target < 0 || index >= candidates.size()) {
            return;
        }

        // Pick the current Element
        temp.push_back(candidates[index]);

        // Recursive call to keep finding the combination
        combSum(index, target - candidates[index], temp, result, candidates);

        // Now backtrack it to reset state
        temp.pop_back();

        // recursive call to see if there is combination with next index
        combSum(index + 1, target, temp, result, candidates);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        combSum(0, target, temp, result, candidates);
        return result;
    }
};