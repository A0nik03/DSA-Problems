// Subset Sum Problem

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind, int target, vector<int>& arr){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
       
        bool notTake = f(ind - 1,target,arr);
        bool take = false;
        if(arr[ind] <= target) take = f(ind - 1,target - arr[ind],arr);
        return take | notTake;
    }

    bool f_memo(int ind, int target, vector<int>& arr,vector<vector<int>> & dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f_memo(ind - 1,target,arr,dp);
        bool take = false;
        if(arr[ind] <= target) take = f_memo(ind - 1,target - arr[ind],arr,dp);
        return dp[ind][target] = take | notTake;
    }
    
    bool f_tabu(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum + 1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum;target++){
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n - 1][sum];
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum + 1, - 1)); 
        return f_memo(n - 1, sum , arr , dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends