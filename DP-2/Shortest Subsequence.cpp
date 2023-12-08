/* Gary has two string S and V. Now, Gary wants to know 
the length shortest subsequence in S, which is not a 
subsequence in V.

Note: The input data will be such that there will always 
be a solution.

Input Format:- 
The first line of input contains a string, that denotes 
the value of S. The following line contains a string, 
that denotes the value of V.

Output Format:- 
Length of shortest subsequence in S such that it is not 
a subsequence in V */


#include <iostream>
#include <string>
using namespace std;

#define MAX 2099
/* The reason we can't take INT_MAX because if we add 
1 to INT_MAX, it will cause the sign bit to change from
0 to 1 which will give us the value of INT_MIN. 

We have to take MAX because we are using min() function
to calculate our answer. */

int solve(string s, string v){
    int m = s.length();
    int n = v.length();
 
    // Creating a 2D array dynamically.
    int **arra = new int*[m + 1];
    for (int row = 0; row <= m; row++){
        arra[row] = new int[n + 1];
    }
 
    // When v string is empty
    for (int i = 0; i <= m; i++)
        arra[i][0] = 1;
 
    // When s string is empty
    for (int i = 0; i <= n; i++)
        arra[0][i] = MAX;
 
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            char ch = s[i-1];
            int k;
            
            for (k = j-1; k >= 0; k--){
                if (v[k] == ch){
                    break;
                }
            }
 
            // Char not present in v.
            if (k == -1){
                arra[i][j] = 1;
            }else{
               arra[i][j] = min(arra[i-1][j], arra[i-1][k] + 1);
            }
        }
    }
 
    int ans = arra[m][n];
    
    // If answer is >= MAX, that means no answer exists.
    if (ans >= MAX){
        ans = -1;
    }
 
    return ans;
}

/* int solve(string s, string v, int** arra){
    int m = s.length();
    int n = v.length();

    // Base Cases

    // S string is empty
    if (m == 0){
        return MAX;
    }
 
    // T string is empty
    if (n <= 0){
        return 1;
    }
    
    // Main Code

    // Checking if the answer alreay exists.
    if (arra[m][n] != -1){
        return arra[m][n];
    }

    // Answer doesn't exist, so we calculate.

    // Loop to search for current character
    int k;
    for (k = 0; k < n; k++){
        if (v[k] == s[0]){
            break;
        }
    }
 
    // char not found in v
    if (k == n){
        return 1;
    }
 
    // Return minimum of following two
    // Not including current char in answer
    // Including current char
    int ans = min(solve(s.substr(1), v, arra), 1 + solve(s.substr(1), v.substr(k+1), arra ));

    // Save answer before returning.
    arra[m][n] = ans;

    return ans;
}

int solve(string s, string v){
    int m = s.length();
    int n = v.length();
    
    int **arra = new int*[m + 1];
    for (int row = 0; row <= m; row++){
        arra[row] = new int[n + 1];

        for (int col = 0; col <= n; col++){
            arra[row][col] = -1;
        }
    }

    return solve(s, v, arra);
} */

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}