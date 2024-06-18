#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
vector<int> rotateArray(vector<int>& arr, int n) {
  int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(8);
    rotateArray(arr,3);
}