// Square root of a number

/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long start = 1;
        long long end = x;
        long long ans = 0;
        
        
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(x < mid * mid){
                end = mid - 1;
            }
            else if(mid * mid <= x){
                ans = mid;
                start = mid + 1;
            }
        }
        if(ans % x == 0){
        return ans;
        }
        else{
            return floor(ans);
        }
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends