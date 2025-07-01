#include<bits/stdc++.h>
using namespace std;

void printN(int n) {
    if(n == 0) return;
    printN(n - 1);
    cout<<n<<" ";
}

int largest(int arr[], int n ) {
    if(n ==1 )return arr[0];
    
    int sp = largest(arr, n-1);
    return max(sp, arr[n-1]);
    // TC - O(n) SC - O(n) auxilary SC - O(1)
}

void reverseArray(int array[], int &l, int &r) {
   if(l >= r) return;
   swap(array[l], array[r]);
   l++; r--;
   reverseArray(array, l, r);
}

int main() {
    // printN(5);
    
    
    int arr[] = {1, 2, 3, 4, 6, 5};
    int answer = largest(arr, 6);
    // cout << answer;
    
    
    int array[] = {1, 2, 3, 4, 5};
    int l = 0, r = 4;
    reverseArray(array, l, r);
    // for(int num : array) {
    //     cout<<num<<" ";
    // }
    
    // Reverse Stack 
    // int top = s.peek();
    // s.pop();
    //how to insert at bottom?
    
}