/* Given two integers a and b. You need to find and return 
the count of possible ways in which we can represent the 
number a as the sum of unique integers raise to the power b.

For example: if a = 10 and b = 2, only way to represent 10 as 
sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 .

Hence, answer is 1.

Note : x^y represents x raise to the power y.

Input Format:- 
The first line of input contains two space separated integers, 
that denote the value of a and b.

Output Format:- 
The first and only line of output contains count of ways in 
which a can be represented as sum of unique integers raised to 
power b. */


#include <iostream>
#include <cmath>

using namespace std;

// DP Where ?
// It's a normal recursion problem.

int getAllWays(int a, int b, int current_num = 1) {
	// Base cases
    int val = (a - pow(current_num, b));
   
    if (val == 0){
        return 1;
    }

    if (val < 0){
        return 0;
    }
    
    // Main Code

    // Consider two possibilities, current_num is included and 
    //current_num is not included.
    return getAllWays(val, b, current_num + 1) + getAllWays(a, b, current_num + 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}