/* Given an integer N, find and return the count of 
minimum numbers required to represent N as a sum 
of squares.

That is, if N is 4, then we can represent it as : 
{1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will 
be 1, as 1 is the minimum count of numbers required 
to represent N as sum of squares. */

#include <bits/stdc++.h>
using namespace std;

int minCount(int n, int *arra){
	// Base Case
	if (n < 0){
		return 0;
	}
	
	// Searching for answer in the array
	if (arra[n] != -1){
		return arra[n];
	}

	// Main Code

	// Answer not found, so calculating
	int ans = INT_MAX;
	int sqrt_Of_n = sqrt(n);
	
	for (int i = 1; i <= sqrt_Of_n; i++){
		int square_of_i = pow(i, 2);
		int x = minCount(n - square_of_i, arra) + 1;

		ans = min(ans,x);
	}

	// Saving answer in array for future use
	arra[n] = ans;

	return ans;
}

int minCount(int n){
	int *arra = new int[n + 1];
	
	// Initialising array
	arra[0] = 0;
	arra[1] = 1;
	for (int i = 2; i <= n; i++){
		arra[i] = -1;
	}

	int ans = minCount(n, arra);
	delete [] arra;

	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}