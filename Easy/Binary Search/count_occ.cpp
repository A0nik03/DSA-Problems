// Number of occurrence

/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int first_Occ(int nums[],int n, int target){
        int ans = -1;
        int start = 0;
        int end = n - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }

    int last_Occ(int nums[],int n, int target){
        int ans = -1;
        int start = 0;
        int end = n - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    
	int count(int arr[], int n, int x) {
	    if(first_Occ(arr,n,x) == -1){
	        return 0;
	    }
	    return (last_Occ(arr,n,x) - first_Occ(arr,n,x) + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends