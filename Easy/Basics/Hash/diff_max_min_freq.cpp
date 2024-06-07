// Difference between highest and lowest occurrence

// Given an array, the task is to find the difference between highest occurrence and lowest occurrence of any number in an array.
// Note: If only one type of element is present in the array return 0.

// Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findDiff(int nums[], int n) {
        map<int,int> hash;
        for(int i = 0;i<n;i++){
            hash[nums[i]]++;
        }
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        for(auto it:hash){
            if(it.second > max_value){
                max_value = it.second;
            }

            if(it.second < min_value){
                min_value = it.second;
            }
        }
        return (max_value - min_value);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n], i;
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.findDiff(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends