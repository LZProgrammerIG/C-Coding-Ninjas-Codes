/* An integer matrix of size (M x N) has been given. Find out the 
minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i,  j), you can move in three directions:
1. ((i + 1),  j) which is, "down".
2. (i, (j + 1)) which is, "to the right".
3. ((i+1), (j+1)) which is, "to the diagonal".

The cost of a path is defined as the sum of each cell's 
values through which the route passes.

Input Format:- 
The first line of the test case contains two integer values, 
'M' and 'N', separated by a single space. They represent the 
'rows' and 'columns' respectively, for the two-dimensional 
array/list.

The second line onwards, the next 'M' lines or rows represent 
the ith row values.

Each of the ith row constitutes 'N' column values separated 
by a single space.

Output Format:- 
Print the minimum cost to reach the destination. */


#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n){
	// Creating a Dynamic 2D array for DP.
	int** arra = new int*[m];
	for (int i = 0; i < m; i++){
		arra[i] = new int[n] ();
	}

	// The (i,j) cell contains minimum cost path to the last cell which is
	// (m - 1, n - 1) cell. So to calculate the minimum cost
	// path from (0,0) we will start from (m - 1, n - 1).
	arra[m - 1][n - 1] = input[m - 1][n - 1];

	// Filling last column.
	for (int row = m - 2; row >= 0; row--){
		arra[row][n - 1] = input[row][n - 1] + arra[row + 1][n - 1];
	}

	// Filling last row.
	for (int col = n - 2; col >= 0; col--){
		arra[m - 1][col] = input[m - 1][col] + arra[m - 1][col + 1];
	}

	// Filling the rest of cells.
	for (int row = m - 2; row >= 0; row--){
		for (int col = n - 2; col >= 0; col--){
			arra[row][col] = input[row][col] + 
				min(arra[row + 1][col], min(arra[row][col + 1], arra[row + 1][col + 1]) );
		}
	}

	return arra[0][0];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}