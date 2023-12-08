/* A child is running up a staircase with n steps and can hop either 1 
step, 2 steps or 3 steps at a time. Implement a method to count how 
many possible ways the child can run up to the stairs. You need to 
return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with 
mod(10^9 +7) */


#include <iostream>
#define m 1000000007

using namespace std;

unsigned long long countStaircase(int n, unsigned long long *arr){
    // Base Case
    if (n < 0){
       return 0;
    }

    // Checking if the answer exists
    if (arr[n] != 0){
        return arr[n];
    }

    // Main Code

    // If the answer is not present, calculate
    unsigned long long x = countStaircase(n - 1, arr) % m;
    unsigned long long y = countStaircase(n - 2, arr) % m;
    unsigned long long z = countStaircase(n - 3, arr) % m;

    // Save in the array for future use before returning
    unsigned long long ans = (x + y + z) % m; 
    arr[n] = ans;

    return ans;
}

int main(){
    int test_case, cases;
    cin >> test_case;

    while (test_case--){
        cin >> cases;

        unsigned long long *arra = new unsigned long long [cases + 1];
        
        // Initialising Array Values
        arra[0] = 1;
        arra[1] = 1;
        for (int  i = 2; i <= cases; i++){
            arra[i] = 0;
        }
        
        cout << countStaircase(cases, arra) << endl;
        delete [] arra;
    }
    return 0;
}