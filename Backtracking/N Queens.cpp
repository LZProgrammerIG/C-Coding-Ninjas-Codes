/*
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' 
queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, or the same diagonal 
of any of the other queens. You have to print all such configurations.

Input Format:-
The first and the only line of input contains an integer 'N' representing the size of the 
chessboard and the number of queens.

Output Format:- 
Each line would be representing a single configuration.

Each configuration would contain 'N '* 'N' elements printed row-wise separated by spaces. 
The position where we can place the queen will have the value 1 rest will have the value 0.
*/



#include <iostream>
#include <vector>

using namespace std;

bool isValidMove(int x, int y, int n, vector<vector<int>> &board){
    // Checking for queen in upward column
    for (int i = 0; i < x; i++){
        if (board[i][y] == 1){
            return false;
        }
    }

    // Checking for queen in top left diagonal
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j-- ){
        if (board[i][j] == 1){
            return false;
        }
    }

    // Checking for queen in top right diagonal
    for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++ ){
        if (board[i][j] == 1){
            return false;
        }
    }

    // GG all test case passed. You are hired.
    return true;
}

void solveNQueens_helper(vector<vector<int>> &board, vector<vector<int>> &ans, int row, int n){
    // Base Case
    if (row == n){
        // Creating temp vector to store the ans which
        // will be appended in the final ans vector
        vector<int> temp;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                temp.push_back(board[i][j]);
            }
        }

        ans.push_back(temp);
    }

    // Main Code 
    for (int col = 0; col < n; col++){
        if (isValidMove(row, col, n, board)) {
            board[row][col] = 1;
            
            solveNQueens_helper(board, ans, row + 1, n);

            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Creating Vector and initialising with 0
    // Contructor :- 
    // vector <vector <int>> name (row_count, vector<int> (col_count));

    vector<vector<int>> v (n, vector<int> (n));
     vector<vector<int>> ans;


    // Using helper function to solve the problem
    solveNQueens_helper(v, ans, 0, n);

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}