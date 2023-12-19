/* You are given a 2D board (N rows and M columns) of characters and a string word.

Your task is to return true if the given word exists in the grid, else return false. 
The word can be constructed from letters of sequentially adjacent cells, where adjacent 
cells are horizontally or vertically neighboring.

Note:- 
The same letter cell should not be used more than once.

Input Format:-
The first line contains a string 'word'.

The second line of input contains two single space-separated integers 'N' and 'M' representing 
the number of rows and columns of the grid respectively.

The next 'N' lines contain 'M' single space-separated characters each representing the elements 
in a row of the matrix.

Output Format:- 
The only line contains either “true” or “false”.
*/



#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

bool isValidMove(vector<vector<char>> &board, char letter, int x, int y, int n, int m){
    // If element is Out Of Bounds
    if (x < 0 || x >= m || y < 0 || y >= n){
        return false;
    }

    // If no desired character in proximity
    if (board[x][y] != letter){
        return false;
    }

    // GG all test case passed. Chad detected.
    return true;
}


bool check_for_word(vector<vector<char>> &board, string word, int x, int y, int m, int n){
    // Base case
    if (word.length() == 0){
        return true;
    }
    
    // Main Code

    // Storing and removing the character to avoid reusage of that character.
    char temp = board[x][y];
    board[x][y] = '\0';

    // Using backtracking to find the next character.

    // Moving Up
    if (isValidMove(board, word[0], x - 1, y, n, m)){
        
        if (check_for_word(board, word.substr(1), x - 1, y, m, n)){
            return true;
        }
    }

    // Moving Down
    if (isValidMove(board, word[0], x + 1, y, n, m)){
      
        if (check_for_word(board, word.substr(1), x + 1, y, m, n)){
            return true;
        }
    }

    // Moving Left
    if (isValidMove(board, word[0], x, y - 1, n, m)){
        
        if (check_for_word(board, word.substr(1), x , y - 1, m, n)){
            return true;
        }
    }

    // Moving Right
    if (isValidMove(board, word[0], x , y + 1, n, m)){
       
        if (check_for_word(board, word.substr(1), x , y + 1, m, n)){
            return true;
        }
    }


    // If the word is not found then restore the character and move on
    board[x][y] = temp;
    return false;
}

bool present(vector<vector<char>> &board, string word, int n, int m) {
    // Search whole 2D array for desired first character then call the
    // helper functions

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            
            if (board[i][j] == word[0]){
                
                if (check_for_word(board, word.substr(1), i, j, n, m)){
                    return true;
                }
            }
        }
    }

    // When the word is not found, accept defeat and return false.
    return false;
}

class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}