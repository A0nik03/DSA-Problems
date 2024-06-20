// Rotation

/*
Given an ascending sorted rotated array arr of distinct integers of size n. The array is right-rotated k times. Find the value of k.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        int ind = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= mini) {
                mini = nums[mid];
                ind = mid;
            }

            if (nums[low] < nums[mid] && nums[low] < nums[high]) {
                high = mid - 1;
            } else if(nums[mid] > nums[high] && nums[high] < nums[low]) {
                low = mid + 1;
            }
            else{
                low++;
                high--;
            }
        }
        return ind;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends