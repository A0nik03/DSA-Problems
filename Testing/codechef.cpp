//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    string longestCommonPrefix (string arr[], int N){
        sort(arr, arr+N);
        string str1 = arr[0];
        string str2 = arr[N-1];
        string ans ="";
        for(int i = 0; i < str2.length(); i++){
            if(str1[i] != str2[i])
             break;
             
            ans += str1[i];
        }
       if(ans.empty())
        return "-1";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// } Driver Code Ends