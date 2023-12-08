/* For the given infinite supply of coins of each of denominations, 
D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the 
total number of ways W, in which you can make the change for 
Value V using coins of denominations D.

Return 0 if the change isn't possible.

Input Format:- 
The first line of the input contains an integer value N, which 
denotes the total number of denominations.

The second line of input contains N values, separated by a single 
space. These values denote the value of denomination.

The third line of the input contains an integer value, that 
denotes the value of V.

Output Format:- 
Print the total total number of ways i.e. W. */


#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDeno, int value, int** arra){
	// Base Case
    if (value == 0){
        return arra[numDeno][value] = 1;
	}

	// If number of coins is 0 or value is less than 0 then
    // there is no way to make the value.
    if (numDeno == 0 || value < 0){
        return 0;
	}
	
	// Main Code

    // If the subproblem is previously calculated then
    // simply return the result
    if (arra[numDeno][value] != -1){
        return arra[numDeno][value];
	}
 
    // Two options for the current coin
    int include = countWaysToMakeChange(denominations, numDeno, value - denominations[numDeno - 1], arra);
	int exclude = countWaysToMakeChange(denominations, numDeno - 1, value, arra);

	// Save the answer in the array after calculating.
	int ans = include + exclude;
	arra[numDeno][value] = include + exclude;

	return ans; 
}

int countWaysToMakeChange(int denominations[], int numDeno, int value){
	// Creating a 2D array for memoisation.
	int **arra = new int*[numDeno + 1];
	for (int i = 0; i <= numDeno; i++){
		arra[i] = new int[value + 1];

		for (int j = 0; j <= value; j++){
			arra[i][j] = -1;
		}
	}

	return countWaysToMakeChange(denominations, numDeno, value, arra);
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}