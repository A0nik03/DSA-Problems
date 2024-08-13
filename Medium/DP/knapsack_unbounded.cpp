// Knapsack with Duplicate Items


/*
Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int ind, int w, int profit[], int weight[]) {
        if (ind == 0) {
            return (w / weight[0]) * profit[0];
        }
    
        int notTake = f(ind - 1, w, profit, weight);
        int take = -1e9;
        if (weight[ind] <= w) {
            take = profit[ind] + f(ind, w - weight[ind], profit, weight);
        }
        return max(take, notTake);
    }
    
    int f_memo(int ind, int w, int profit[], int weight[], vector<vector<int>> &dp) {
        if (ind == 0) {
            return (w / weight[0]) * profit[0];
        }
        if (dp[ind][w] != -1) {
            return dp[ind][w];
        }
        
        int notTake = f_memo(ind - 1, w, profit, weight, dp);
        int take = -1e9;
        if (weight[ind] <= w) {
            take = profit[ind] + f_memo(ind, w - weight[ind], profit, weight, dp);
        }
        
        return dp[ind][w] = max(take, notTake);
    }
    
    int f_tabu(int n, int w, int profit[], int weight[]) {
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        
        for (int wt = 0; wt <= w; wt++) {
            dp[0][wt] = (wt / weight[0]) * profit[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            for (int wt = 0; wt <= w; wt++) {
                int notTake = dp[ind - 1][wt];
                int take = -1e9;
                if (weight[ind] <= wt) {
                    take = profit[ind] + dp[ind][wt - weight[ind]];
                }
                dp[ind][wt] = max(take, notTake);
            }
        }
        
        return dp[n - 1][w];
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        return f_tabu(N,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends