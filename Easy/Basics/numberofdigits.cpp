#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Ques:  Number of digits
// Statement: You are given a number 'n'.
// Return number of digits in ‘n’.

// Time Complexity: O (n) where n is the number of digits in the given integer
// Space Complexity: O(1)

int brute(int n){
	int cnt =0;
	while(n!=0){
		cnt++;
		n/=10;
	}
	return cnt;
}

// Time Complexity: O (1) 
// Space Complexity: O(1)

int intution1(int n){
	string num = to_string(n);
	return num.size();

}

// Use logarithm base 10 to count the number of digits. As
// The number of digits in an integer = the upper bound of log10(n).

int intution2(int n){
	int cnt = (int)(log10(n)+1);
	return cnt;
}

int countDigits(int n){
	return intution2(n);
}