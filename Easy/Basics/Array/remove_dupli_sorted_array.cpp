#include <set>
#include <bits/stdc++.h>
using namespace std; 

// Brute Force
int bruteMeth(vector<int> &arr,int n){
	set<int> st;
	for(int i = 0;i<n;i++){
		st.insert(arr[i]);
	}

	int index = 0;
	for(auto it:st){
		arr[index++] = it;
	}
	return index;
}
// Time Complexity: O(n + nlogn)
// Space Complexity: O(n)

int optimalMeth(vector<int> &arr,int n){
	int i = 0;
	for(int j = 1;j<n;j++){
		if(arr[i] != arr[j]){
			arr[i+1] = arr[j];
			i++;
		}
	}
return i+1;
}
// Time Complexity: O(n)

int removeDuplicates(vector<int> &arr, int n) {
	// int brute = bruteMeth(arr,n);
	int optimal = optimalMeth(arr,n);
	return optimal;
}