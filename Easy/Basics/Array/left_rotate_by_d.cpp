
#include <iostream>
#include <vector>
using namespace std;

// Brute Approach
vector<int> bruteMeth(vector<int> arr,int k){
    int n = arr.size();
    int temp[k+1];
    int m = 0;
    for(int i = 0;i<k;i++){
        temp[m] = arr[i];
        m++;
    }

    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    int j = 0;
    for (int i = n - k; i < n; i++){
        arr[i] = temp[j];
        j++;
}
    return arr;

}

vector<int> betterMeth(vector<int> arr,int k){
    int temp[k];
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        temp[(i - k + n)%n] = arr[i];
    }

    
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    return arr;
}
// Time Complexity: O(n+k)
// Space Complexity: O(k)

void optimalMeth(vector<int>& arr,int k){
    int n = arr.size();
    reverse(arr.begin(),arr.end());
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}
// Time Complexity: O(2n)
// Space Complexity: O(1)

vector<int> rotateArray(vector<int>arr, int k) {
    vector<int> brute =  bruteMeth(arr,k);
    vector<int> better = betterMeth(arr,k);
    optimalMeth(arr,k);

    return arr;
}
