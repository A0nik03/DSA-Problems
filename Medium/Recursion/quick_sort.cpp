#include <iostream>
using namespace std;

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	int pivot = input[start];
	int i = start;
	int j = end;
	while(i<j){
	    while(input[i] <= pivot && i <= end - 1){
			i++;
		}
		while(input[j] > pivot && j >= start + 1){
			j--;
		}
		if(i<j){
			swap(input[i],input[j]);
		}
		
	}
	swap(input[j],input[start]);
	return j;
}

void quickSort(int input[], int start, int end) {
	if(start < end){
		int partition = partitionArray(input,start,end);
		quickSort(input,start,partition-1);
		quickSort(input,partition+1,end);
	}
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)