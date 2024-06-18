// Count Inversions

/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  
//  Brute (Loop)
int numberOfInversions(long long *arr, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}
// Optimal (Merge Sort)

void merge(long long *arr, int start, int end, int mid,long long &cnt) {
  vector<long long> temp;
  int left = start;
  int right = mid + 1;

  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left++]);
    } else {
      temp.push_back(arr[right++]);
      cnt += (mid - left + 1);
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left++]);
  }
  while (right <= end) {
    temp.push_back(arr[right++]);
  }

  for (int i = 0; i < temp.size() && start <= end; i++) {
    arr[start++] = temp[i];
  }
}

void merge_sort(long long *arr, int start, int end,long long &cnt) {
  if (start >= end) {
    return;
  }
  int mid = start + (end - start) / 2;
  // Left sort
  merge_sort(arr, start, mid,cnt);
  // Right Sort
  merge_sort(arr, mid + 1, end,cnt);
  // Merge
  merge(arr, start, end, mid,cnt);
  
}


  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(int N, long long arr[]) {
    long long cnt = 0;
    merge_sort(arr,0,N - 1,cnt);
    return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(N, A) << endl;
    }

    return 0;
}

// } Driver Code Ends