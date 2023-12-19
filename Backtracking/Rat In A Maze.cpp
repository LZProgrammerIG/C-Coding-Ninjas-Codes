/* You are given a starting position for a rat which is stuck in a maze 
at an initial point (0, 0) (the maze can be thought of as a 
2-dimensional plane). The maze would be given in the form of a square 
matrix of order 'N' * 'N' where the cells with value 0 represent the 
maze's blocked locations while value 1 is the open/available path that 
the rat can take to reach its destination. The rat's destination is at 
('N' - 1, 'N' - 1). Your task is to find all the possible paths that 
the rat can take to reach from source to destination in the maze. The 
possible directions that it can take to move in the maze are 'U'(up) 
i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 
'R' (right) i.e. (x + 1, y).

Note:- 
Here, sorted paths mean that the expected output should be in 
alphabetical order.

For example:- 
Given a square matrix of size 4*4 (i.e. here 'N' = 4):
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
Expected Output:
DDRDRR DRDDRR 
i.e. Path-1: DDRDRR and Path-2: DRDDRR

The rat can reach the destination at (3, 3) from (0, 0) by two paths, 
i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.

Input Format:- 
The first line contains an integer 'N', which denotes the dimensions of 
the square matrix (maze).

Then 'N' lines follow. Each line contains 'N' space-separated integers 
denoting the values which would either be 0 denoting a blocked path or 
1 denoting the available path in the maze, respectively.


Output Format:- 
For the given maze, print the vector/list of strings representing all 
the possible paths that the rat can take to reach from source to 
destination in the maze in sorted order.

Output for each test case will be printed in a separate line.*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidMove(int x, int y, int N, vector < vector < int >> & arr){
    // If the cell is out of bounds
    if (x < 0 || x >= N){
        return false;
    }else if (y < 0 || y >= N){
        return false;
    }
    
    // If the cell is blocked or visited
    else if (arr[x][y] == 0){
        return false;
    }

    // GG test passed. Welcome to the army soldier.
    return true;    
}

void searchMaze_Helper(vector < vector < int >> & arr, vector<string> &ans, int n, int x, int y, string s) {
    // Base case
    if (x == n-1 && y == n-1){
       ans.push_back(s);
       return;
    }

    // Main Code
    
    // Marking current cell as visited
    arr[x][y] = 0;

    //Moving Down 
    if (isValidMove(x + 1, y, n, arr)){
        s = s + "D"; 
        searchMaze_Helper(arr, ans, n, x + 1, y, s);
        
        // Backtrack
        s.pop_back();
    }

    //Moving Left
    if (isValidMove(x, y - 1 , n, arr)){
        s = s + "L"; 
        searchMaze_Helper(arr, ans, n, x, y - 1, s);
        
        // Backtrack
        s.pop_back(); 
    }

    //Moving Right
    if (isValidMove(x, y + 1, n, arr)){
        s = s + "R"; 
        searchMaze_Helper(arr, ans, n, x, y + 1, s);
        
        // Backtrack
        s.pop_back();
    }

    //Moving Up 
    if (isValidMove(x - 1, y, n, arr)){
        s = s + "U"; 
        searchMaze_Helper(arr, ans, n, x - 1, y, s);
        
        // Backtrack
        s.pop_back();
    }

    // Marking current cell as unvisited
    arr[x][y] = 1;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n){
    vector<string> ans;

    // Shitty Edge Case
    if (arr[0][0] == 0){
        return ans;
    }

    // Main Code
    string s = "";

    searchMaze_Helper(arr, ans, n, 0, 0, s);
    return ans;
}

class Runner {
    int t;
    vector<vector<int>> arr;

public:
    void takeInput() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr.push_back(vector<int>());
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
        }
    }

    void execute() {
        vector<vector<int> > arrCopy = arr;

        vector<string> ans= searchMaze(arrCopy, arrCopy.size());
    }

    void executeAndPrintOutput() {
        vector<string> ans = searchMaze(arr,arr.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
};

int main() {

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}