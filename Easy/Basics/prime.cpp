#include <iostream>
using namespace std;

// Problem statement:
// A prime number is a positive integer that is divisible by exactly 2 integers, 1 and the number itself.
// You are given a number 'n'.

// Find out whether 'n' is prime or not.


// Brute

// Complexity Analysis:
// Time Complexity: O(n)
// Space Complexity: O(1)

bool brute(int n){
	bool prime = 1;
	if(n == 1){
		return 0;
	}
	for(int i = 2; i <n;i++){
		if(n%i == 0){
		prime = 0;
		}
	}
return prime;
}

// Better(Optimal)
// Time Complexity: O(√n)
// Space Complexity: O(1)

bool better(int n){
	bool prime = 1;
	if(n == 1){
		return 0;
	}
	for(int i = 2; i*i <n;i++){
		if(n%i == 0){
		prime = 0;
		}
	}
return prime;
}

bool isPrime(int n)
{
	return better(n);
}
