/* Given a chain of matrices A1, A2, A3,.....An, you have to 
figure out the most efficient way to multiply these matrices. 
In other words, determine where to place parentheses to 
minimize the number of multiplications.

You will be given an array p[] of size n + 1. Dimension of 
matrix Ai is p[i - 1]*p[i]. You need to find minimum number 
of multiplications needed to multiply the chain.

Input Format:- 
The first line of input contains an integer, that denotes 
the value of n. The following line contains n+1 integers, 
that denote the value of elements of array p[].

Output Format:- 
The first and only line of output prints the minimum 
number of multiplication needed. */


#include <iostream>
#include <climits>

using namespace std;

int matrixChain_Memo(int **arra, int *arr, int start, int end){
    // Base Case
    if (end - start == 1){
        return 0;
    }
    
    // Main Code

    // Checking if the answer already exists in the array.
    if (arra[start][end] != -1){
        return arra[start][end];
    }
    
    // Couldn't find answer, so we make our own.
    int ans = INT_MAX;
    
    for (int k = start + 1; k < end; k++){
        int x = matrixChain_Memo(arra, arr, start, k);
        int y = matrixChain_Memo(arra, arr, k, end);

        int temp = x + y + arr[start] * arr[k] * arr[end];
        ans = min(ans, temp);
    }

    // Don't forget to quicksave the answer.
    arra[start][end] = ans;
    
    return ans;
}

int matrixChainMultiplication(int *arr, int n) {
    // Creating the 2D array for memoisation
    int **arra = new int*[n + 1];
    for (int i = 0; i <= n; i++){
        arra[i] = new int[n + 1];

        for (int j = 0; j <= n; j++){
            arra[i][j] = -1;
        }
    }

    return matrixChain_Memo(arra, arr, 0, n);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}