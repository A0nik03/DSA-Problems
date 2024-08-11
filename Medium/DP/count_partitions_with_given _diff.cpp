// Partitions with Given Difference

/*
Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9 + 7;
    int f(int ind, vector<int> &arr, int k) {
        if (ind == 0){
            if(k == 0 && arr[0] == 0) return 2;
            if(k == 0 || arr[0] == k) return 1;
            return 0;
        }
        
        
        int notPick = f(ind - 1, arr, k);
        int pick = 0;
        if(arr[ind] <= k) {
            pick = f(ind - 1, arr, k - arr[ind]);
        }
        return (pick + notPick)%mod;
    }

    int f_memo(int ind, vector<int> &arr, int k,vector<vector<int>>& dp) {
        if (ind == 0){
            if(k == 0 && arr[0] == 0) return 2;
            if(k == 0 || arr[0] == k) return 1;
            return 0;
        }
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int notPick = f_memo(ind - 1, arr, k,dp);
        int pick = 0;
        if(arr[ind] <= k) {
            pick = f_memo(ind - 1, arr, k - arr[ind],dp);
        }
        return dp[ind][k] = (pick + notPick)%mod;
    }
    
    int f_tabu(vector<int> &arr, int k){
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
            dp[ind][sum] = (pick + notPick)%mod;
        }
    }
    return dp[n - 1][k];
    }
    
    int findWays(vector<int> &arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n,vector<int> (k + 1, -1));
        return f_tabu(arr, k);
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for(int i = 0; i < n; i++) totSum += arr[i];
        if((totSum - d) < 0 || (totSum - d) % 2) return false;
        return findWays(arr, (totSum - d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends