//  Allocate Books

/*
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid) {
  int student = 1;
  int bookPages = 0;
  for (int i = 0; i < n; i++) {
    if (bookPages + arr[i] <= mid) {
      bookPages += arr[i];
    } else {
      student++;
      if (student > m) {
        return false;
      } else {
        bookPages = arr[i];
      }
    }
  }
  return true;
}

int findPages(vector<int>& arr, int n, int m) {
  if (m > n)

    return -1;

  int maxi = INT_MIN,total = 0;
  for (auto it : arr) {
    total += it;
    maxi = max(maxi,it);
  }
  int start = maxi;
  int end = total;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(isPossible(arr,n,m,mid)){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}