#include <iostream>
using namespace std;

// Problem statement
// You are given an integer ‘n’.

// Function ‘sumOfDivisors(n)’ is defined as the sum of all divisors of ‘n’.
// Find the sum of ‘sumOfDivisors(i)’ for all ‘i’ from 1 to ‘n’.

// Brute
int sumdiv(int n){
	int sum = 0;
	for(int i = 1;i<=n;i++){
		if(n%i == 0){
			sum+=i;
		}
	}
return sum;
}
// Time Complexity: O(n)
// Better
int sumdiv(int n){
	int sum = 0;
	for(int i = 1;i*i<=n;i++){
		if(n%i == 0){
			sum+=i;
			if((n/i) != i){
				sum+=n/i;
			}
		}
	}
return sum;
}
// Time Complexity: O(sqrt(n))

int sumOfAllDivisors(int n){
	int sum = 0;
	for(int i = 1;i<=n;i++){
		sum+=sumdiv(i);
	}
	return sum;
}

int main()
{
    int n;
    cin>>n;
   cout<<sumOfAllDivisors(n)<<endl;
}