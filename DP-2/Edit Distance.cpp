/* You are given two strings S and T of lengths M and N, 
respectively. Find the 'Edit Distance' between the strings.

Edit Distance of two strings is the minimum number of steps 
required to make one string equal to the other. In order to 
do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note:- 
Strings don't contain spaces in between. */

#include <iostream>
#include <cstring>
using namespace std;

int editDistance_DP(string s1, string s2, int** arra) {
	int m = s1.length();
	int n = s2.length();
	
	// Filling obvious spots in the array.

	// Filling top row first.
	for (int i = 0; i <= n; i++){
		arra[0][i] = i;
	}

	// Now filling first column.
	for (int i = 0; i <= m; i++){
		arra[i][0] = i;
	}

	// Now filling rest of the spots row - wise
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			
			if (s1[m - i] == s2[n - j]){
				arra[i][j] = arra[i-1][j-1];
			}else{
				arra[i][j] = min(arra[i-1][j-1], min(arra[i][j-1], arra[i-1][j] ) ) + 1;
			}
		}
	}

	return arra[m][n];
}

int editDistance_Memo(string s1, string s2, int** arra) {
	int m = s1.length();
	int n = s2.length();
	
	// Base Case
	
	// If length of one string is 0, return the length of other string 
	if (m == 0 || n == 0){
		return max(m, n);
	}

	// Main Code

	// Check if the answer is alreay present
	if (arra[m][n] != -1){
		return arra[m][n];
	}

	// If answer is not present, then calculate.
	int ans;
	
	if (s1[0] == s2[0] ){
		ans = editDistance_Memo(s1.substr(1), s2.substr(1), arra);
	}else{
		// When the first character doesn't match

		// Adding the character in s2
		int add = editDistance_Memo(s1.substr(1), s2, arra) + 1; 

		// Deleting the character in s2
		int del = editDistance_Memo(s1, s2.substr(1), arra) + 1;

		// Updating the character in s2
		int update = editDistance_Memo(s1.substr(1), s2.substr(1), arra) + 1;  

		ans = min(add, min(del, update) );
	}

	// Save the answer in arra before returning
	arra[m][n] = ans;

	return ans;
}

int editDistance(string s1, string s2){
	int m = s1.length();
	int n = s2.length();
	
	// Creating a 2D array for memoization.
	int **arra = new int*[m + 1];

	for (int i = 0; i <= m; i++){
		arra[i] = new int[n + 1];

		for (int j = 0; j <= n; j++){
			arra[i][j] = -1;
		}
	}

	// Calling our main function
	//return editDistance_Memo(s1, s2, arra);
	return editDistance_DP(s1, s2, arra);
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}