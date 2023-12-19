/*
You are given a string 'S'. Your task is to partition 'S' such that every substring of the 
partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

Note:-
A substring is a contiguous segment of a string.


For example:- 
For a given string “BaaB”, 3 possible palindrome partitioning of the given string are:

{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}

Every substring of all the above partitions of “BaaB” is a palindrome.


Input Format:- 
The only line of input contains a string 'S'.


Output Format:- 
For each test case, print all the possible palindromic partitions of the given string 
in a separate line.

Each substring of a partition is written within quotes(““) and separated by comma(,) 
and space, and each partition of the given string is written inside square brackets[].

The output of each test case will be printed in a separate line.

Note:- 
All the substrings of a partition are sorted in lexicographical order in the output. 
You just need to return the partitions in any order.
*/


#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

bool checkPalindrome(string& s){
    int n = s.size();
    int i = 0, j = n - 1;
    
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        
        i++;
        j--;
    }
    return true;
}

void Partition_helper(vector<vector<string> >& res, string& s, int idx, vector<string>& curr){
    // Base Case
    if (idx == s.size()) {
        res.push_back(curr);
        return;
    }
    
    // Main Code

    // Stores the current substring.
    string t;
    for (int i = idx; i < s.size(); i++) {
        t.push_back(s[i]);

        // Check if the string is palindrome.
        if (checkPalindrome(t)) {

            // Adds the string to current list
            curr.push_back(t);

            // Recursive call for the remaining string
            Partition_helper(res, s, i + 1, curr);

            // Remove the string from the current string.
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) {
    vector<string> current_string;
    vector<vector<string>> ans;

    Partition_helper(ans, s, 0, current_string);

    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    //string str;
    //getline(cin, str);
    while(t--) {

    	string S;
    	getline(cin, S);

    	vector<vector<string>> ans = partition(S);
    	
    	for(int i = 0; i < ans.size(); i++) {

    		cout << "[";
    		
    		sort(ans[i].begin(), ans[i].end());
    		for(int j = 0; j < ans[i].size(); j++) {

    			if(j != ans[i].size() - 1) {
    				cout << "\"" << ans[i][j] << "\", ";
    			}
    			else {
    				cout << "\"" << ans[i][j] << "\"";
    			}

    		}

    		cout << "]" << endl;

    	}

    }

    return 0;

}