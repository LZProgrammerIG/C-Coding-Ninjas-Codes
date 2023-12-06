/* It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's 
and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined 
as a part which consist of only '1's, and all '1's share an edge with each other on the cake. 
  Given the size of cake N and the cake, can you find the count of '1's in the biggest piece 
of '1's for Gary ? */


#include <iostream>
#include <vector>
using namespace std;

// Since the largest piece can be a combination of rectangles,
// Thus we will not use DP.

bool isYummyPiece(vector<vector<int>> &cake, int n, int x, int y){
    // Checking for Out of Bounds.
    if (x < 0 || x >= n || y < 0 || y >= n){
        return false;
    }

    // Checking for visited or not Yummy piece.
    if (cake[x][y] == 0){
        return false;
    }

    // Bring me my CAKE !!!
    return true;
}


int getBiggestPiece(vector<vector<int>> &cake, int n, int x, int y) {
    int count = 0;
    
    // Marking the piece as visited.
    cake[x][y] = 0;

    // Searching for yummiest largest piece.

    // Searching Up.
    if (isYummyPiece(cake, n, x - 1, y)){
        count += getBiggestPiece(cake, n, x - 1, y);
    }

    // Searching Down.
    if (isYummyPiece(cake, n, x + 1, y)){
        count += getBiggestPiece(cake, n, x + 1, y);
    }

    // Searching Left.
    if (isYummyPiece(cake, n, x, y - 1)){
        count += getBiggestPiece(cake, n, x, y - 1);
    }

    // Searching Right.
    if (isYummyPiece(cake, n, x, y + 1)){
        count += getBiggestPiece(cake, n, x, y + 1);
    }

    return count + 1;
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    int largestPiece = 0;
    
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            
            if (cake[row][col] == 1){
                int piece = getBiggestPiece(cake, n, row, col);
                largestPiece = max(largestPiece, piece);
            }
        }
    }

    return largestPiece;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
