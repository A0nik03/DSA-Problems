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
    cout<<"Student: "<<student<<endl;
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
        cout<<"Mid: "<<mid<<endl;
        if(isPossible(arr,n,m,mid)){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}

int main(){
    vector<int> arr = {12,34,67,90};
    int ans = findPages(arr,arr.size(),2);
    cout<< ans<<endl;
}