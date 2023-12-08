/* Given an NxM matrix that contains only 0s and 1s, find 
out the size of the maximum square sub-matrix with all 0s. 
You need to return the size of the square matrix with all 0s.

Input Format:- 
The first line of the test case contains two integer values, 
'N' and 'M', separated by a single space. They represent the 
'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent 
the ith row values.

Each of the ith rows constitutes column values separated by 
a single space (Either 0 or 1).

Output Format:- 
Print the size of maximum square sub-matrix. */


#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **input, int n, int m){
	// Shitty Edge Case
	if (n == 0 || m == 0){
		return 0;
	}

	// Creating an array for DP.
	int **arra = new int*[n];
	for (int i = 0; i < n; i++){
		arra[i] = new int[m];
	}

	// Filling values in first row and first column as
	// they are pretty obvious.
	// 0 if cell has value 1 and 1 if cell has value 0.

	// For first row.
	for (int col = 0; col < m; col++){
		arra[0][col] = (input[0][col] == 0) ? 1 : 0;
	}

	// For first column now.
	for (int row = 0; row < n; row++){
		arra[row][0] = (input[row][0] == 0) ? 1 : 0;
	}

	// Now filling the rest of array.
	for (int row = 1; row < n; row++){
		for (int col = 1; col < m; col++){
			
			if (input[row][col] == 1){
				arra[row][col] = 0;
			}
			
			else{
				arra[row][col] = min (arra[row-1][col-1], 
						min(arra[row-1][col], arra[row][col-1]) ) + 1;
			}
		}
	}

	// Now searching for the answer in our arra
	int ans = 0;

	for (int row = 0; row < n; row++){
		for (int col = 0; col < m; col++){
			ans = max(ans, arra[row][col]);
		}
	}

	return ans;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}