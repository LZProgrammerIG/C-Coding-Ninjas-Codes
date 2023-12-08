/* Given a positive integer 'n',  find and return the minimum number 
of steps that 'n' has to take to get reduced to 1. You can perform 
any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ). 

Print the minimum number of steps.
*/  


#include <bits/stdc++.h>
using namespace std;

int countStepsToOne_helper(int n, unordered_map<int, int> &map){
	// Base Case
	if (n == 1){
		return 0;
	}

	// Checking if the answer already exists
	if (map[n] > 0){
		return map[n];
	}

	// Recursive Calls
	int y = INT_MAX, z = INT_MAX;

	// Subtracting by 1.
	int x = countStepsToOne_helper(n - 1, map);

	// Dividing by 2.
	if (n % 2 == 0){
		y = countStepsToOne_helper(n / 2, map);
	}

	// Dividing by 3.
	if (n % 3 == 0){
		z = countStepsToOne_helper(n / 3, map);
	}

	int ans = min(x, min(y, z)) + 1;
	map[n] = ans;

	return ans;
}

int countStepsToOne(int n){
	unordered_map<int, int> map;
	return countStepsToOne_helper(n, map);
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}