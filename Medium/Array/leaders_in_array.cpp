//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    
#include <algorithm>
class Solution{
    //Function to find the leaders in the array.
    
    private:
    vector<int> brute(int a[], int n){
        vector<int> ans;
        for(int i = 0; i < n;i++){
            bool leader = true;
            for(int j = i + 1; j < n;j++){
                if(a[j] > a[i]){
                    leader = false;
                    break;
                }
            }
            if(leader == true){
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
    
    vector<int> optimal(int a[], int n){
        int maxi = INT_MIN;
        vector<int> ans;
        for(int i = n - 1;i >= 0;i--){
            if(a[i] >= maxi){
                ans.push_back(a[i]);
                maxi = max(maxi,a[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    public:
    vector<int> leaders(int a[], int n){
        return optimal(a,n);
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends