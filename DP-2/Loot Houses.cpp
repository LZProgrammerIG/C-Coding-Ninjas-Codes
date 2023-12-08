/* A thief wants to loot houses. He knows the amount of 
money in each house. He cannot loot two consecutive houses. 
Find the maximum amount of money he can loot.

Input Format:- 
The first line of input contains an integer value of 'n'. 
It is the total number of houses.

The second line of input contains 'n' integer values separated 
by a single space denoting the amount of money each house has.

Output Format:- 
Print the the maximum money that can be looted. */


#include <iostream>
using namespace std;

int maxMoneyLooted_Memo(int *arr, int n, int *arra){
    // Base Case
    if (n <= 0){
        return 0;
    }

    // Main Code

    // Checking if the answer already exists.
    if (arra[n] != -1){
        return arra[n];
    }

    // Answer not found, so calculate.

    // Including the element.
    // Moving two steps further because consecutive
    // elements not allowed.
    int include = arr[0] + maxMoneyLooted_Memo(arr + 2, n - 2, arra);

    // Excluding the element and moving one step further.
    int exclude = maxMoneyLooted_Memo(arr + 1, n - 1, arra);

    int ans = max(include, exclude);

    // Saving the answer in array before returning it.
    arra[n] = ans;
    return ans;
}

int maxMoneyLooted_Brute(int *arr, int n){
	// Base Case
    if (n <= 0){
        return 0;
    }

    // Main Code

    // Including the element.
    // Moving two steps further because consecutive
    // elements not allowed.
    int include = arr[0] + maxMoneyLooted_Brute(arr + 2, n - 2);

    // Excluding the element and moving one step further.
    int exclude = maxMoneyLooted_Brute(arr + 1, n - 1);

    return max(include, exclude);
}

int maxMoneyLooted(int *arr, int n){
    int *arra = new int [n+1];
    for (int i = 0; i <= n; i++){
        arra[i] = -1;
    }

    return maxMoneyLooted_Memo(arr, n, arra);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}