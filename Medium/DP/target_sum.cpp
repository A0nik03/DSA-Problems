// Target Sum

/*
Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target and return your answer with modulo 109+7.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int> &arr, int k){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (k + 1, 0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
        
        for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k;sum++){
            int notPick = dp[ind - 1][sum];
            int pick = 0;
            if(arr[ind] <= sum){
                pick = dp[ind - 1][sum - arr[ind]];
            }
            dp[ind][sum] = (pick + notPick);
        }
    }
    return dp[n - 1][k];
    }
    
    int findWays(vector<int> &arr, int k) {
        int n = arr.size();
        return solve(arr, k);
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for(int i = 0; i < n; i++) totSum += arr[i];
        if((totSum - d) < 0 || (totSum - d) % 2) return false;
        return findWays(arr, (totSum - d)/2);
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        return countPartitions(n,target,A);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends