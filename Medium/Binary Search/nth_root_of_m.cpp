// Find Nth root of M

/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    long long start = 1;
        long long end = m;
        long long ans = -1;
        
        
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(m < pow(mid,n)){
                end = mid - 1;
            }
            else if(pow(mid,n) == m){
                return mid;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends