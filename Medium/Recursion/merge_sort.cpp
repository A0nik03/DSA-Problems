#include <bits/stdc++.h>
using namespace std;
void merge(int *arr,int l,int r,int mid){
int temp[r-l+1];
int left = l;
int right = mid + 1;

int index = 0;
while(left<=mid && right<=r){
    if(arr[left] <= arr[right]){
        temp[index] = arr[left];
        left++;
    }
    else{
        temp[index] = arr[right];
        right++;
    }
    index++;
}
while(left<=mid){
    temp[index] = arr[left];
    index++;
    left++;
}
while(right<=r){
   temp[index] = arr[right];
    index++;
    right++;
}

for(int i=l;i<=r;i++){
    arr[i] = temp[i - l];
}
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r){
        return;
    }
    int mid = l + (r-l)/2;
    // Left Side
    mergeSort(arr,l,mid);
    // Right Side
    mergeSort(arr,mid+1,r);
    // Merging
    merge(arr,l,r,mid);
}

void merge(vector<int>& arr,int l,int r,int mid){
vector<int> temp;
int left = l;
int right = mid + 1;


while(left<=mid && right<=r){
    if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]);
        right++;
    }
}
while(left<=mid){
    temp.push_back(arr[left]);
    left++;
}
while(right<=r){
    temp.push_back(arr[right]);
    right++;
}

for(int i=l;i<=r;i++){
    arr[i] = temp[i - l];
}

}

void mergeSort(vector<int> arr, int l, int r) {
    if(l>=r){
        return;
    }
    int mid = l + (r-l)/2;
    // Left Side
    mergeSort(arr,l,mid);
    // Right Side
    mergeSort(arr,mid+1,r);
    // Merging
    merge(arr,l,r,mid);
}

// Time Complexity: O(nlog(n))