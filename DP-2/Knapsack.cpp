/* A thief is robbing a store and can carry a maximal weight of W into his 
knapsack. There are N items and ith item weighs wi and is of value vi. 
Considering the constraints of maximum weight that knapsack can carry, 
you have to find and return the maximum value that thief can generate 
by stealing items.

Note:- 
Space complexity should be O(W).

Input Format:- 
The first line contains an integers, that denote the value of N. 
The following line contains N space separated integers, that denote 
the values of weight of items. The following line contains N space 
separated integers, that denote the values associated with the items. 
The following line contains an integer that denote the value of W. 
W denotes maximum weight that thief can carry.

Output Format:- 
The first and only line of output contains the maximum value that 
thief can generate, as described in the task.  */


#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int knapsack_Memo(int *weights, int *values, int n, int maxWeight, int** arra){
	// Base Case
	if (n == 0){
		return 0;
	}

	// Main Code

	// Check if answer already exists
	if (arra[n][maxWeight] != -1){
		return arra[n][maxWeight];
	}

	// Answer not found, so we calculate it.
	int x = INT_MIN;

	// Inlcuding the first value if its weight doesn't exceed the maxWeight.
	if (weights[0] <= maxWeight){
		x = knapsack_Memo(weights + 1, values + 1,  n - 1, maxWeight - weights[0], arra) + values[0];	
	}

	// Not including the first value.
	int y = knapsack_Memo(weights + 1, values + 1, n - 1, maxWeight, arra);

	int ans = max(x,y);

	// Oi ! Don't forget to save the answer in the array.
	arra[n][maxWeight] = ans;

	return ans;
}

int knapsack(int* weights, int* values, int n, int maxWeight) {
	// Creatng a 2D array of n x maxWeight.

	int **arra = new int* [n+1];
	for (int i = 0; i <= n; i++){
		arra[i] = new int [maxWeight + 1];

		for (int j = 0; j <= maxWeight; j++){
			arra[i][j] = -1;
		}
	}
	
	return knapsack_Memo(weights, values, n, maxWeight, arra);
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}