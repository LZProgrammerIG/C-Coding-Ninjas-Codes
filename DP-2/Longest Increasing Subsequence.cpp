/* Given an array with N elements, you need to find the length of the 
longest subsequence in the given array such that all elements of the 
subsequence are sorted in strictly increasing order.

Input Format:- 
The first line of input contains an integer N. The following line 
contains N space separated integers, that denote the value of elements 
of array.

Output Format:- 
The first and only line of output contains the length of longest subsequence. */


#include <iostream>
#include <climits>

using namespace std;

int longestIncreasingSubsequence(int* arr, int n, int** arra, int curr_index = 0, int prev_index = -1) {
	// Base Case
	if (curr_index == n){
		return 0;
	}

	// Main Code

	// Checking if the answer exists in the array.
	if (arra[curr_index][prev_index + 1] != -1){
		return arra[curr_index][prev_index + 1];
	}

	// In Soviet Russia, you don't search the answers.
	// You MAKE the answers.
	int include = INT_MIN;

	if (prev_index == -1 || arr[curr_index] > arr[prev_index]){
		include = longestIncreasingSubsequence(arr, n, arra, curr_index + 1, curr_index) + 1;
	}
	int exclude = longestIncreasingSubsequence(arr, n, arra, curr_index + 1, prev_index);
	
	int ans = max(include,exclude);

	// Gotta quicksave the progress so I can load
	// back after committing mass genocide.

	arra[curr_index][prev_index + 1] = ans;
	return ans;
}

int longestIncreasingSubsequence(int* arr, int n){
	int **arra = new int*[n + 1];
	for (int i = 0; i <= n; i++){
		arra[i] = new int[n + 1];

		for (int j = 0; j <= n; j++){
			arra[i][j] = -1;
		}
	}

	// Oi !
	// What the hell ?! What have you done?
	// Memo-ization.
	return longestIncreasingSubsequence(arr, n, arra);
}


// My OG Brute-Force Approach
/* int longestIncreasingSubsequence(int* arr, int n, int tempVal = INT_MIN) {
	// Base Case
	if (n == 0){
		return 0;
	}

	// Main Code
	int include = INT_MIN;

	if (arr[0] > tempVal){
		include = longestIncreasingSubsequence(arr + 1, n - 1, arra, arr[0]) + 1;
	}
	int exclude = longestIncreasingSubsequence(arr + 1, n - 1, arra, tempVal);
	
	return max(include,exclude);
} */

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}