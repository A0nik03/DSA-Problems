//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    int brute(int arr[],int n,int target){
       int maxi = 0;
       for(int i = 0; i < n; i++){
           for(int j = i; j < n;j++){
               int sum = 0;
               for(int k = i;k <= j;k++){
                   sum+=arr[k];
                   if(sum == target){
                       maxi = max(maxi,j - i + 1);
                   }
               }
               
           }
           
       }
       return maxi;
    }
    
    int better_One(int arr[],int n,int target){
       int maxi = 0;
       for(int i = 0; i < n; i++){
            int sum = 0;
           for(int j = i; j < n;j++){
               sum += arr[j];
               if(sum == target){
               maxi = max(maxi,j - i + 1);
            }
            }
            
       }
       return maxi;
    }
    
    int better_Two(int arr[],int n,int target){
       int maxi = 0;
       map<int,int> mpp;
       int sum = 0;
       for(int i = 0; i < n; i++){
           sum+=arr[i];
           int remaining = target - sum;
           if(mpp.find(remaining) != mpp.end()){
               int len = i - mpp[remaining];
               maxi = max(maxi,len);
           }
           else if(mpp.find(sum) == mpp.end()){
               mpp[sum] = i;
           }
       }
       return maxi;
    }
    
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       return better_Two(A,N,K);
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends