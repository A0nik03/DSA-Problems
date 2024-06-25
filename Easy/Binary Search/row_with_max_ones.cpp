//  Row with Maximum 1's

/*
You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.

Your task is to find the index of the row with the maximum number of ones.

Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> arr, int n, int x) {
  int start = 0;
  int end = n - 1;
  int ans = n;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
  int cnt_max = 0;
  int ind = -1;
  for (int i = 0; i < n; i++) {
    int cnt = m - lowerbound(matrix[i], m, 1);
    if (cnt > cnt_max) {
       cnt_max = cnt;
       ind = i;
    }
  }
  return ind;
}