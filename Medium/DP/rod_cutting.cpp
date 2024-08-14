// Rod Cutting

/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[], int ind,int n){
        if(ind == 0) return n * price[0];
        
        int notTake = 0 + f(price,ind - 1,n);
        int take = INT_MIN;
        int rodLen = ind + 1;
        if(rodLen <= n) take = price[ind] + f(price,ind,n - rodLen);
        return max(take,notTake);
    }
    
    int f_memo(int price[], int ind,int n,vector<vector<int>> &dp){
        if(ind == 0) return n * price[0];
        if(dp[ind][n] != -1) return dp[ind][n];
        int notTake = 0 + f_memo(price,ind - 1,n,dp);
        int take = INT_MIN;
        int rodLen = ind + 1;
        if(rodLen <= n) take = price[ind] + f_memo(price,ind,n - rodLen,dp);
        return dp[ind][n] = max(take,notTake);
    }
    
    int f_tabu(int price[], int n){
        vector<vector<int>> dp(n,vector<int> (n + 1, 0));
        for(int N = 0; N <= n; N++) dp[0][N] = N * price[0];
        for(int ind = 1; ind < n; ind++){
            for(int N = 0; N <= n;N++){
                int notTake = 0 + dp[ind - 1][N];
                int take = INT_MIN;
                int rodLen = ind + 1;
                if(rodLen <= N) take = price[ind] + dp[ind][N - rodLen];
                dp[ind][N] = max(take,notTake);
            }
        }
        return dp[n - 1][n];
    }
    
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int> (n + 1, -1));
        return f_tabu(price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends