/* Given a NxM matrix containing Uppercase English Alphabets only. Your task is to 
tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, 
neighbouring cells are those cells that share an edge or a corner with the cell. */

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int n, int m, 
                int x, int y, char c){
    // Check for Out of Bounds.
    if (x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }

    // If the character doesn't match
    else if (board[x][y] != c){
        return false;
    }

    // All test cases passed. Welcome aboar mate.
    return true;
}

bool hasPath(vector<vector<char>> &board, int n, int m, 
                int x, int y, string s = "ODINGNINJA") {
    // Base Case
    if (s.length() == 0){
        return true;
    }

    // Main Code

    // Marking the charater as visited by replacing it with
    // any lowercase alphabet.
    char c = board[x][y];
    board[x][y] = 'a';

    // Searching for the first character of string s.

    // Searching Up.
    if (isValid(board, n, m, x - 1, y, s[0]) ){
        if (hasPath(board, n, m, x - 1, y, s.substr(1)) ){
            return true;
        }
    }

    // Searching Down.
    if (isValid(board, n, m, x + 1, y, s[0]) ){
        if (hasPath(board, n, m, x + 1, y, s.substr(1)) ){
            return true;
        }
    }

    // Searching Left.
    if (isValid(board, n, m, x, y - 1, s[0]) ){
        if (hasPath(board, n, m, x, y - 1, s.substr(1)) ){
            return true;
        }
    }

    // Searching Right.
    if (isValid(board, n, m, x, y + 1, s[0]) ){
        if (hasPath(board, n, m, x, y + 1, s.substr(1)) ){
            return true;
        }
    }

    // Searching Top Left.
    if (isValid(board, n, m, x - 1, y - 1, s[0]) ){
        if (hasPath(board, n, m, x - 1, y - 1, s.substr(1)) ){
            return true;
        }
    }

    // Searching Top Right.
    if (isValid(board, n, m, x - 1, y + 1, s[0]) ){
        if (hasPath(board, n, m, x - 1, y + 1, s.substr(1)) ){
            return true;
        }
    }

    // Searching Bottom Left.
    if (isValid(board, n, m, x + 1, y - 1, s[0]) ){
        if (hasPath(board, n, m, x + 1, y - 1, s.substr(1)) ){
            return true;
        }
    }

    // Searching Bottom Right.
    if (isValid(board, n, m, x + 1, y + 1, s[0]) ){
        if (hasPath(board, n, m, x + 1, y + 1, s.substr(1)) ){
            return true;
        }
    }

    // Marking the cell as not visited again.
    board[x][y] = c;

    // No path exists. Thus return false.
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            if (board[row][col] == 'C'){

                if (hasPath(board, n, m, row, col) ){
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}
