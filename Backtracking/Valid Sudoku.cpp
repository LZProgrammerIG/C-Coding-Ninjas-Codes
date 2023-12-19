/*
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), 
and some empty cells (denoted by 0).

You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) 
such that the final matrix is a valid Sudoku solution.

A Sudoku solution must satisfy all the following conditions:-
1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.

Note:- 
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in 
the problem statement.


Input Format:- 
The first line contains a single integer 'T' denoting the number of test cases.
Then 'T' test cases follow.

Every test case contains 9 lines, with each line containing 9 single space-separated digits 
(0, if the cell is empty or a digit (1 - 9) otherwise).


Ouput Format:- 
For each test case, print a single line containing “yes”(without quotes), if there exists a Sudoku 
solution or “no” (without quotes) otherwise. Note the lowercase format of the output.
*/


#include <iostream>
using namespace std;

void findBox(int matrix[9][9], int x, int y, int &row_start, int &col_start){
    // Finding the starting column number first
    if (y < 3){
        col_start = 0;
    }else{
        col_start = (y < 6) ? 3 : 6;
    }

    // Finding starting row number
     if (x < 3){
        row_start = 0;
    }else{
        row_start = (x < 6) ? 3 : 6;
    }
}

bool isValidMove(int matrix[9][9], int x, int y, int number){
    // Checking Row
    for (int col = 0; col < 9; col++){
        if (matrix[x][col] == number){
            return false;
        }
    }

    // Checking Column
    for (int row = 0; row < 9; row++){
        if (matrix[row][y] == number){
            return false;
        }
    }

    // Checking Box
    
    // First need to find the starting coorinates of the box 
    int box_row_start = 0;
    int box_col_start = 0;
    findBox(matrix, x, y, box_row_start, box_col_start);

    // Now running loop to check the box
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            
            if (matrix[box_row_start][box_col_start] == number){
                return false;
            }
            box_col_start++;
        }
        box_row_start++;
        box_col_start -= 3;
    }

    // GG. All test cases passed. Permission granted.
    return true;
}

bool isItSudoku(int matrix[9][9], int row = 0, int col = 0) {
    // Base Case
    if (row == 8 && col == 9){
        return true;
    } 
    
    if (col == 9){
        col = 0;
        row++;
    }   

    
    // Main Code
    if (matrix[row][col] == 0){
        for (int number = 1; number < 10; number++){
            
            if (isValidMove(matrix, row, col, number)){
                matrix[row][col] = number;
                
                if (isItSudoku(matrix,  row, col + 1)){
                    return true;
                }
                matrix[row][col] = 0;

            }
        }

        return false;

    }else{
        return isItSudoku(matrix, row, col + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int matrix[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin >> matrix[i][j];
        }
        bool ans = isItSudoku(matrix);
        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}
