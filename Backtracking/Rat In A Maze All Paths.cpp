/*
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print 
all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'.  
Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked 
means the rat can­not enter into those cells and those with value 1 are open.


Input Format:- 
The first line of input contains an integer 'N' representing the dimension of the maze.

The next 'N' lines of input contain 'N' space-separated integers representing the type 
of the cell.


Ouptut Format:- 
For each test case, return the path from the start position to the destination position 
and only cells that are part of the solution path should be 1, rest all cells should be 0.

Output for every test case will be printed in a separate line.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool isValidMove(vector<vector<int>> &maze, int x, int y, int n){
  // Out of bounds check
  if (x < 0 || x >=n || y < 0 || y >=n){
    return false;
  }

  // If the cell is bocked
  else if (maze[x][y] == 0){
    return false;
  }

  // GG all test case passed. Welcome aboard soldier.
  return true;
}

void RatInMaze_helper(vector<vector<int> > &maze, vector<vector<int> > &ans, 
                                    vector <int> &temp, int x, int y, int n){
  
  // Base Case
  if (x == n-1 && y == n-1){
    ans.push_back(temp);
    return;
  }

  // Main Code

  // Marking the cell as visited
  maze[x][y] = 0;

  // Finding answer through backtracking

  // Moving Up
  if (isValidMove(maze, x - 1, y, n)){
    temp[((x-1)* n) + y] = 1;

    RatInMaze_helper(maze, ans, temp, x - 1, y, n);

    // Backtrack
    temp[((x-1)* n) + y] = 0;
    maze[x - 1][y] = 1;
  }

  // Moving Left
  if (isValidMove(maze, x , y - 1, n)){
    temp[(x* n) + y - 1] = 1;

    RatInMaze_helper(maze, ans, temp, x, y - 1, n);

    // Backtrack
    temp[(x* n) + y - 1] = 0;
    maze[x][y - 1] = 1;
  }

  // Moving Right
  if (isValidMove(maze, x , y + 1, n)){
    temp[(x* n) + y + 1] = 1;

    RatInMaze_helper(maze, ans, temp, x, y + 1, n);

    // Backtrack
    temp[(x* n) + y + 1] = 0;
    maze[x][y + 1] = 1;
  }

  // Moving Down
  if (isValidMove(maze, x + 1, y, n)){
    temp[((x+1)* n) + y] = 1;

    RatInMaze_helper(maze, ans, temp, x + 1, y, n);

    // Backtrack
    temp[((x+1)* n) + y] = 0;
    maze[x + 1][y] = 1;
  }

  // Marking the cell as unvisited again after use
  maze[x][y] = 1;

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Creating temporary and answer vectors.
  vector<vector<int>> ans;
  
  // Shitty edge case
  if (maze[0][0] == 0){
    return ans;
  }

  // Back to creating vectors.
  
  vector<int> temp;

  // Initialising temporary vector with zeroes but 0th element with 1.
  for (int i  = 0; i < (n*n); i++){
    temp.push_back(0);
  }
  temp[0] = 1;


  // Its helper time !!!
  // HELPER !!

  RatInMaze_helper(maze, ans, temp, 0, 0, n);

  return ans;
}

int main()
{

  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  
  vector<vector<int>> ans = ratInAMaze(maze, n);

  // sort(ans.begin(),ans.end());

  int s = ans.size();
  for (int i = 0; i < s; i++)
  {
    int t = ans[i].size();
    for (int j = 0; j < t; j++)
    {
      cout << ans[i][j] << " ";
    }

    cout << endl;
  }
}