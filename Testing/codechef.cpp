//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int i = 0;
        int cnt = 0;
         int jumpDist = 0;
        while(jumpDist >= n){
            if(arr[i] == 0){
                return -1;
            }
            
            cnt++;
            cout<<"i:"<<i<<endl;
            cout<<"count "<<cnt<<endl;
            cout<<"Jump:"<<jumpDist<<endl;
            
            jumpDist = i + arr[i];
            i += arr[i];
            cout<<"Changed i:"<<i<<endl;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends