#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force
vector<int> bruteMeth(int n,vector<int>& a){
    sort(a.begin(),a.end());
    int largest = a[n-1];
    int slargest = -1;
    for(int i = n-2;i>=0;i--){
        if(a[i]!=largest){
        slargest = a[i];
        break;
        }
    }

    int smallest = a[0];
    int ssmallest = -1;
    for(int i = 1;i<=n-1;i++){
        if(a[i]!=smallest){
        ssmallest = a[i];
        break;
        }
    }
return {slargest,ssmallest};
}
// Time Complexity: O(n + nlogn)

// Better Approach
vector<int> betterMeth(int n,vector<int>& a){
    int largest = a[0];
    for(int i = 1;i<=n-1;i++){
        if(a[i] > largest){
        largest = a[i];
        }
    }
    
    int slargest = INT32_MIN;
    for(int i = 0;i<=n-1;i++){
        if(a[i] > slargest && a[i] < largest){
        slargest = a[i];
        }
    }

    int smallest = a[0];
    for(int i = 1;i<=n-1;i++){
        if(a[i] < smallest){
        smallest = a[i];
        }
    }
    
    int ssmallest = INT32_MAX;
    for(int i = 0;i<=n-1;i++){
        if(a[i] < ssmallest && a[i] > smallest){
        ssmallest = a[i];
        }
    }
return {slargest,ssmallest};
}
// Time complexity: O(2n)

// Optimal Approach
vector<int> optimalMeth(int n,vector<int>& a){
    int largest = a[0];
    int slargest = INT32_MIN;
    for(int i = 1;i<=n-1;i++){
        if(a[i] > largest){
        slargest = largest;
        largest = a[i];
        }
        else if(a[i] != largest && a[i] > slargest){
            slargest = a[i];
        }
    }

    int smallest = a[0];
    int ssmallest = INT32_MAX;

    for(int i = 1;i<=n-1;i++){
        if(a[i] < smallest){
        ssmallest = smallest;
        smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < ssmallest){
            ssmallest = a[i];
        }
    }

return {slargest,ssmallest};
}
// Time Complexity: O(n)


vector<int> getSecondOrderElements(int n, vector<int> a) {
    vector<int> brute = bruteMeth(n,a);
    vector<int> better = betterMeth(n,a);
    vector<int> optimal = optimalMeth(n,a);
    return optimal;
}
