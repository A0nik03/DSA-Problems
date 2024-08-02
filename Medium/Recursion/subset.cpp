// Subset Sums

/*
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void find(vector<int>& arr, int n,vector<int> &ds,int sum,int ind){
        if(ind == n){
            ds.push_back(sum);
            return;
        }
        
        find(arr,n,ds,sum + arr[ind],ind + 1);
        find(arr,n,ds,sum,ind + 1);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ds;
        int sum = 0;
        int ind = 0;
        find(arr,n,ds,sum,ind);
        sort(ds.begin(),ds.end());
        return ds;
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends