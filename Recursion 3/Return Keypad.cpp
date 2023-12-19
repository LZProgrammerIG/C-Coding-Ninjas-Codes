/*
Given an integer n, using phone keypad find out all the possible 
strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note:-
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have 
to populate the output array and return the count of elements 
populated in the output array.

Input Format:- 
Integer n.

Output Format:- 
All possible strings in different lines.
*/


#include <iostream>
#include <string>

using namespace std;

string getOptions(int digit){
    switch (digit){
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return " ";
    }
}


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number 
    into the output string array. You do not need to print anything, 
    just return the number of strings inserted into the array.
    */

    // Base Case
    if (num == 0 || num == 1){
        output[0] = "";
        return 1;
    }

    // Recursive Call
    int smallOutputSize = keypad(num / 10, output);

    // Small Calculation
    int last_digit = num % 10;
    string options = getOptions(last_digit);

    // Making n copies of numbers in output where n is
    // options.length() - 1;
    for (int i = 1; i < options.size(); i++){
        for (int j = 0; j < smallOutputSize; j++){
            output[j + (smallOutputSize * i)] = output[j];
        }
    }

    // Inserting each char of options in output array one by one
    int k = 0;
    for (int i = 0; i < options.size(); i++){
        for (int j = 0; j < smallOutputSize; j++,k++){
            output[k] += options[i];
        }
    }

    return smallOutputSize * options.size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
