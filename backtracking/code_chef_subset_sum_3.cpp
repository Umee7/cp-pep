#include <bits/stdc++.h>
using namespace std;

bool findSS(int index, vector<int> &nums, int sum, bool existance) {
    
    if(index == nums.size()) {
        if(existance && sum%3==0) return true;
        else return false;
    }
    // Pick

    if(findSS(index + 1, nums, sum + nums[index], true)) return true;

    // Not Pick
    if(findSS(index + 1, nums, sum, existance))return true;
    return false;
    
}

int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--) {
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int i = 0; i < size; i++ ){
            cin>>nums[i];
        }


        bool existance = false;
        if(findSS(0, nums, 0, existance)) {
           cout <<"YES"<<endl;
        }
        else cout << "NO"<<endl;
    }
}
