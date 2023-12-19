/*
Given an integer n, using phone keypad find out and print all the possible strings 
that can be made using digits of input n.

Note:- 
The order of strings are not important. Just print different strings in new lines.

Input Format:- 
Integer n.

Output Format:- 
All possible strings in different lines.
*/


#include <iostream>
#include <string>

using namespace std;

string getOptions(int num){
    switch(num){
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
    }
}

void printKeypad(int num, string output = ""){
    /*
    Given an integer number print all the possible combinations of the keypad. 
    You do not need to return anything just print them.
    */

    // Base Case
    if (num == 0){
        cout << output << endl;
        return;
    }

    // Small Calculation
    int last_digit = num % 10;
    num /= 10;

    string options = getOptions(last_digit);

    // Recursive Call
    for (int i = 0; i < options.length(); i++){
        printKeypad(num, options[i] + output);
    }

}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
