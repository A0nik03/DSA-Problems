// Minimal Cost


/*
There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone n.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int jump_tabular(vector<int>& height, int n, int k){
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                if(i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
                }
            }
        }
        
        return dp[n - 1];
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        return jump_tabular(height,n,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends