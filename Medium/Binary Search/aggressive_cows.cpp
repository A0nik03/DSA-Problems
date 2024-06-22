//  Aggressive Cows

/*
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

Print the maximum possible minimum distance.

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
  int dist = stalls[0], cowCnt = 1;
  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - dist >= mid) {
      dist = stalls[i];
      cowCnt++;
    }

    if (cowCnt >= k) {
      return 1;
    }
  }
  return 0;
}

int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
  if (k < 2) {
    return -1;
  }
  int maxi = *max_element(stalls.begin(), stalls.end());
  int mini = *min_element(stalls.begin(), stalls.end());
  int start = 0;
  int end = maxi - mini;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (isPossible(stalls, k, mid)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return end;
}