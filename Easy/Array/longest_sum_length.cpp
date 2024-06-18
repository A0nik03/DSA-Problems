#include <bits/stdc++.h>
using namespace std;

int brute_loop(vector<int> &A, int K) {
  int N = A.size();
  int len = 0;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      if (sum == K) {
        len = max(len, j - i + 1);
      }
    }
  }
  return len;
}

int better_hash(vector<int> &A, int K) {
  map<int, int> preSumMap;
  int sum = 0, maxLen = 0;
  for (int i = 0; i < A.size(); i++) {
    sum += A[i];
    if (sum == K) {
      maxLen = max(maxLen, i + 1);
    }

    int rem = sum - K;
    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }

    if (preSumMap.find(sum) == preSumMap.end()) {
      preSumMap[sum] = i;
    }
  }
  return maxLen;
}
// Only Optimal for +ve otherwise Hash map is perfect
int optimal_twopointer(vector<int> &A, int K) {
  long long sum = A[0];
  int maxLen = 0;
  int left = 0, right = 0;
  while (right < A.size()) {
    while (left <= right && sum > K) {
      sum -= A[left];
      left++;
    }

    if (sum == K) {
      maxLen = max(maxLen, right - left + 1);
    }

    right++;
    if (right < A.size()) {
      sum += A[right];
    }
  }
  return maxLen;
}

int getLongestSubarray(vector<int> &A, int K) {
  return better_hash(A, K);
}