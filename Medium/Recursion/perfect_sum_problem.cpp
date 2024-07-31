// Perfect Sum Problem

/*
Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = 1e9+7;
	int f(int* nums,int n, int target,int ind,int sum){
	    if(sum > target) return 0;
        if(ind == n){
            if(sum == target) return 1;
            else return 0;
        }
        

        sum+=nums[ind];
        int l = f(nums,n,target,ind+1,sum)%mod;
        sum-=nums[ind];
        int r = f(nums,n,target,ind+1,sum)%mod;
        return (l + r)%mod;
    }
    
	int perfectSum(int arr[], int n, int sum)
	{
	    int s = 0;
        return f(arr,n,sum,0,s);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends