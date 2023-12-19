/*
Given a string S, find and return all the possible permutations of the input string.

Note 1 :- 
The order of permutations is not important.

Note 2 :-
If original string contains duplicate characters, permutations will also be duplicates.

Input Format:- 
String S.

Output Format:-
All permutations in different lines.
*/


#include <iostream>
#include <string>

using namespace std;

// Method 1
// Time Taken = 47 ms

int returnPermutations(string input, string output[]){

	// Base Case
	if (input.length() == 0){
		output[0] = "";
		return 1;
	}
	
	// Recursive Call
	string permutation[1000];
	int array_size = returnPermutations(input.substr(1), permutation);

	// Small Calculation
	int output_index = 0;

	for (int i = 0; i < array_size; i++){
		for (int j = 0; j <= permutation[i].length(); j++){
			output[output_index] = permutation[i].substr(0,j) + input[0] + permutation[i].substr(j);
			output_index++;
		}
	}

	return output_index;
}


// Method 2
// Time taken = 326 ms

/* int returnPermutations(string input, string output[]){
	
	// Base Case
	if (input.length() == 0){
		output[0] = "";
		return 1;
	}

	int output_index = 0;	

	for (int i = 0; i < input.length(); i++){
		string permutation[1000];
		string inputString = input.substr(0,i) + input.substr(i+1);
		int array_size = returnPermutations(inputString, permutation);
	
		for (int j = 0; j < array_size; j++){
			output[output_index] = input[i] + permutation[j];
			output_index++;
		}
	}

	return output_index;
} */

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
