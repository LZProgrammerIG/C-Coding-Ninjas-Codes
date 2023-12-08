/* Given an integer h, find the possible number of balanced 
binary trees of height h. You just need to return the count 
of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Time complexity should be O(h). */


#include <iostream>
using namespace std;

#define m 1000000007

int balancedBTs(int n, int *arra) {
    // Base Cases
    if (n <= 1) {
        return 1;
    }

    // Main Code

    // Checking if the answer is already in the array
    if (arra[n] != -1){
        return arra[n];
    }

    // If the answer not found, then calculate
    long x = balancedBTs(n - 1, arra) % m;
    long y = balancedBTs(n - 2, arra) % m;

    int comb1 = (int) ((x * x) % m);
    int comb2 = (int) ((x * y) % m);
    // Comb3 is (y * x) % m which is same as comb2

    // Saving ans in array for future use
    int ans = (comb1 + (2 * comb2) % m) % m;
    arra[n] = ans;
    
    return ans;
}

int balancedBTs(int n) {
    int* arra = new int [n + 1];
    
    for (int i = 0; i <= n; i++){
        arra[i] = -1;
    }

    return balancedBTs(n, arra);
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}