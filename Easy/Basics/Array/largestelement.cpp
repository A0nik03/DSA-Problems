#include <bits/stdc++.h>
using namespace std; 

// Brute Force
int bruteMeth(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    return arr[n-1];
}
// Time Complexity: O(nlogn)

// Optimal Approach
int optimalMeth(vector<int> arr,int n){
   int largest = arr[0];
   int slargest = -1;
   for(int i = 1;i<n;i++){
       if(arr[i] > largest){
           largest = arr[i];
       }
   }
   return largest;
}
// Time Complexity: O(n)

int largestElement(vector<int> &arr, int n) {
    int brute = bruteMeth(arr,n);
    int optimal = optimalMeth(arr,n);
    return optimal;
}
