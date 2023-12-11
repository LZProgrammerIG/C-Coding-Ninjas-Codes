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
