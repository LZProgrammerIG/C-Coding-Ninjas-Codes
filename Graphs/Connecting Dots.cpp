/* Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters 
(i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. 
The key of this game is to find a cycle that contain dots of same colour. 
Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only 
if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should 
  also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if 
there exists a cycle on the board. */

#include <iostream>
#include <vector>
using namespace std;

// DISCLAMIER:- This algorithm doesn't check for a cycle 
// which is not forming a rectangle or square.

// A-Z = 65-90.
// a-z = 97-122.
// Lowercase = +32, Uppercase = -32.

bool isValid(vector<vector<char>> &board, int n, int m, 
            int x, int y, int prevX, int prevY, char c){
    
    // Checking Out of Bounds.
    if (x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }

    // Checking if the dots are of same colour.
    if (board[x][y] != c && board[x][y] != (c + 32) ){
        return false;
    }

    // Checking if we are not going back to the immediate
    // previous cell to avoid infinite calls between two 
    // adjacent cells.
    if (x == prevX && y == prevY){
        return false;
    }

    // GG. All tests cases passed. Are you the choosen one?
    return true;
}

bool hasCycle(vector<vector<char>> &board, int n, int m, 
            int x, int y, int prevX, int prevY) {

    // Base Case
    
    // Cycle found if we traceback to a visited cell.
    // Lowercase letter = visited cell.
    if (board[x][y] >= 97){
        return true;
    }

    // Main Code
    char colour = board[x][y];

    // Marking the cell as visited.
    board[x][y] += 32;

    // Searching for the cycle.

    // Searching Up.
    if (isValid(board, n, m, x - 1, y, prevX, prevY, colour)){
        if (hasCycle(board, n, m, x - 1, y, x, y)){
            return true;
        }
    }

    // Searching Down.
    if (isValid(board, n, m, x + 1, y, prevX, prevY, colour)){
        if (hasCycle(board, n, m, x + 1, y, x, y)){
            return true;
        }
    }

    // Searching Left.
    if (isValid(board, n, m, x, y - 1, prevX, prevY, colour)){
        if (hasCycle(board, n, m, x, y - 1, x, y)){
            return true;
        }
    }

    // Searching Right.
    if (isValid(board, n, m, x, y + 1, prevX, prevY, colour)){
        if (hasCycle(board, n, m, x, y + 1, x, y)){
            return true;
        }
    }

    // Reaching at this point means no cycle exists.
    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            
            // Uppercase letters means unvisited cells and ASCII
            // value of all uppercase letters is <= 90.
            if (board[row][col] <= 90){
                
                if (hasCycle(board, n, m, row, col, -1, -1) ){
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
