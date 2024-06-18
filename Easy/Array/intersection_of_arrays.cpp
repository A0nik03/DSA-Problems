// Ques: Intersection of Arrays
#include <iostream>
#include <vector>
using namespace std;

// Brute
#include <bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &nums1, int n, vector<int> &nums2,
                                  int m) {

  vector<int> visited(m, 0);
  vector<int> intersection;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((nums1[i] == nums2[j]) && visited[j] == 0) {
        intersection.push_back(nums1[i]);
        visited[j] = 1;
        break;
      }

      if (nums2[j] > nums1[i]) {
        break;
      }
    }
  }
  return intersection;
}