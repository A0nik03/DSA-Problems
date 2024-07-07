//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int findMaxNeg(long long int *a, int n){
        
        int ind = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= 0){
                ind = i - 1;
                return ind;
            }
        }
        return n - 1;
    }
    
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        
        
        long long int sum = 0;
        
        int ind = findMaxNeg(a,n);
        cout<<"ind: "<<ind<<endl;

        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
        for(int i = ind; i >= 0; i--){
           if(k >= 0){
               a[i] = a[i] * (-1);
               cout<<"a[i]: "<<a[i]<<" ";
               k--;
           }
        }
        cout<<endl;
        
        for(int i = 0; i < n; i++){
            cout<<"sum: "<<sum<<" ";
            sum+=a[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends