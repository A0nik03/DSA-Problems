// 0 - 1 Knapsack Problem

/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind, int W,int Wt[],int val[]){
        if(ind == 0){
            if(W >= Wt[ind]) return val[ind];
            return 0;
        }
        int notTake = 0 + f(ind - 1,W,Wt,val);
        int take = INT_MIN;
        if(W >= Wt[ind]){
            take = val[ind] + f(ind - 1,W - Wt[ind],Wt,val);
        }
        return max(take,notTake);
    }
    
    int f_memo(int ind, int W,int Wt[],int val[],vector<vector<int>> &dp){
        if(ind == 0){
            if(W >= Wt[ind]) return val[ind];
            return 0;
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        int notTake = 0 + f_memo(ind - 1,W,Wt,val,dp);
        int take = INT_MIN;
        if(W >= Wt[ind]){
            take = val[ind] + f_memo(ind - 1,W - Wt[ind],Wt,val,dp);
        }
        return dp[ind][W] = max(take,notTake);
    }
    
    int f_tabu(int W, int Wt[], int val[], int n){
        vector<vector<int>> dp(n,vector<int>(W + 1,0));
        for(int i = Wt[0]; i <= W; i++) dp[0][i] = val[0];
        
        for(int ind = 1; ind < n; ind++){
            for(int weight = 0; weight <= W; weight++){
                int notTake = 0 + dp[ind - 1][weight];
                int take = INT_MIN;
                if(weight >= Wt[ind]){
                    take = val[ind] + dp[ind - 1][weight - Wt[ind]];
                }
                dp[ind][weight] = max(take,notTake);
            }
        }
        return dp[n - 1][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   vector<vector<int>> dp(n,vector<int>(W + 1,-1));
      return f_tabu(W,wt,val,n); 
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends