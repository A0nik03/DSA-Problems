// Find Missing And Repeating

/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
private:

//Brute (Loops)

    vector<int> brute_Loop(vector<int> arr,int n){
        int rep = -1,mis = -1;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < n;j++){
                if(i == arr[j]){
                    cnt++;
                }
            }
            if(cnt == 0){
                mis = i;
            }else if(cnt == 2){
                rep = i;
            }
            
            if(mis != -1 && rep != -1){
                break;
            }
        }
        return {rep,mis};
        
    }
    
    //Better (Hashing)

    vector<int> better_Hashing(vector<int> arr,int n){
        int hash[n+1] = {0},rep = -1,mis = -1;
        for(int i = 0; i < n; i++){
            hash[arr[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0){
                mis = i;
            }else if(hash[i] == 2){
                rep = i;
            }
            
            if(mis != -1 && rep != -1){
                break;
            }
        }
        return {rep,mis};
    }
    
    //Optimal (Maths)

    vector<int> optimal_Maths(vector<int> arr,int n){
        
        // Sum till N Natural Numbers
        long long SN = (n * (n + 1L))/2;
        //  Sum of Square till N Natural Numbers
        long long S2N = (n * (n + 1L)*(2*n + 1L))/6;
        
        long long S = 0,S2 = 0;
        for(int i = 0; i < n ;i++){
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }
        
        //S-Sn = X-Y:
        long long val1 = S - SN;
        
        // S2-S2n = X^2-Y^2:
        long long val2 = S2 - S2N;
        // X + Y
        val2 = val2 / val1;
        
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        
        long long x = (val1 + val2)/ 2;
        long long y = x - val1;
        
        return {(int)x,(int)y};
    }
    
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        return optimal_Maths(arr,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends