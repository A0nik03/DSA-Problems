// Geek Jump

/*
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   Recursion
    int jump_recurr(vector<int>& height, vector<int>& dp,int ind){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int left = jump_recurr(height,dp,ind - 1) + abs(height[ind] - height[ind - 1]);
        int right = INT_MAX;
        if(ind > 1){
        right = jump_recurr(height,dp,ind - 2) + abs(height[ind] - height[ind - 2]);
        }
        
        dp[ind] = min(left,right);
        return dp[ind];
    }
    
// Memoization
    int jump_memo(vector<int>& height, int n,int ind){
        if(ind == 0) return 0;
        
        int left = jump_memo(height,n,ind - 1) + abs(height[ind] - height[ind - 1]);
        int right = INT_MAX;
        if(ind > 1){
        right = jump_memo(height,n,ind - 2) + abs(height[ind] - height[ind - 2]);
        }
        
        return min(left,right);
        
    }
    
// Tabulation
    int jump_tabular(vector<int>& height, int n){
        vector<int> dp(n,0);
        
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if(i > 1){
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(left,right);
        }
        
        return dp[n - 1];
    }
    
// Tabulation (Space Optimization)
    int jump_tabular_sp(vector<int>& height, int n){

        int prev1 = 0,prev2 = 0; 
        
        for(int i = 1; i < n; i++){
            int left = prev1 + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if(i > 1){
                right = prev2+ abs(height[i] - height[i - 2]);
            }
            int curr = min(left,right);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }

    int minimumEnergy(vector<int>& height, int n) {
        int ind = n - 1;
        return jump_tabular_sp(height,n);
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
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends