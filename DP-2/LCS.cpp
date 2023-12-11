/* You have been given two Strings “STR1” and “STR2” of characters. 
Your task is to find the length of the longest common subsequence.
A String ‘a’ is a subsequence of a String ‘b’ if ‘a’ can be obtained 
from ‘b’ by deletion of several (possibly, zero or all) characters. 
A common subsequence of two Strings is a subsequence that is common to both Strings.

Input Format:- 
The first line contains an integer ‘T’ denoting the number of test cases. 
Then each test case follows. 

The first input line of each test case contains two space-separated Strings “STR1” 
and “STR2” representing two Strings. 

Output Format:- 
For each test case, print the length of the longest common subsequence. 
Print the output of each test case in a separate line.

Note:- 
You are not required to print the expected output; it has already been taken care of. 
Just implement the function.  */


#include <iostream>
#include <string>

using namespace std;

int LCS_DP(string s, string t){
  int m = s.length();
  int n = t.length();

  // Creating Dynamic Array for DP.
  int** arra = new int*[m + 1];
  for (int i = 0; i <= m; i++){
    arra[i] = new int[n + 1] ();
  }

  // The first row and first column will remain 0 as LCS of two strings 
  // with one having size 0 is 0.

  /* 
  Code Logic:- 

  The (i,j) cell represents the size of LCS when the size of s and t
  is i and j respectively.
  Since we are deleting elements from the left so when the size of,
  say "abcd" is 2, then that means the string now is "cd". 
  
  If the first character of both strings matches, increment the
  answer by 1 and move forward in both strings (i.e we deleted the 
  first element in both string and are now searching for the size 
  of LCS in remaining strings).

  If the first element does not matches then we have 3 choices:-
    1. Move forward in String s.
    2. Move forward in String t.
    3. Move forward in Both Strings.
  
  This process continues until either of the string becomes of length 0.
  */

  // Filling the rest of cells.
  for (int i = 1; i <= m; i++){
    for (int j = 1; j <= n; j++){

      // Checking if the first element of s and t matches.
      // If yes, then increase the value of ans by 1.
      if (s[m-i] == t[n-j]){
        arra[i][j] = 1 + arra[i - 1][j - 1];
      }else{
        int ans = max(arra[i][j-1], max(arra[i-1][j], arra[i-1][j-1]));
        arra[i][j] = ans;
      }
    }
  }

  // Deleting the Dynamic Array before returning the final answer.
  int ans = arra[m][n];
  for (int i = 0; i <= m; i++){
    delete[] arra[i];
  }
  delete[] arra;

  // Returning the final answer.
  return ans;
}

int main(){
  int testcases;
  cout << "Enter number of test cases here:- " << endl;
  cin >> testcases;

  string s, t;
  cout << "Enter source string s here:- " << endl;
  cin >> s;

  cout << "Enter destination string t here:- " << endl;
  cin >> t;

  while (testcases--){
    cout << LCS_DP(s, t) << endl;
  }
  
  return 0;
}
