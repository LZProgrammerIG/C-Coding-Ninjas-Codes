/* Whis and Beerus are playing a new game today. They form a tower 
of N coins and make a move in alternate turns. Beerus plays first. 
In one step, the player can remove either 1,  X, or Y coins from 
the tower. The person to make the last move wins the game. Can you 
find out who wins the game?

Input Format:- 
The first and the only line of input contains three integer values 
separated by a single space. They denote the value of N, X and Y, 
respectively.

Output Format:- 
Prints the name of the winner, either 'Whis' or 'Beerus' 
(Without the quotes). */


#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y){ 
    // To store results 
    bool dp[n + 1]; 
  
    // Initial values 
    dp[0] = false; 
    dp[1] = true; 
  
    // Computing other values. 
    for (int i = 2; i <= n; i++) { 
  
        /* If A losses game at any of i-1 or i-x or i-y 
		position then he will definitely win game.
		
		This is because A can choose to remove either 1,
		x or y coins, forcing B to lose at i-1 or i-x or i-y
		positions respectively. */

        if (i - 1 >= 0 && !dp[i - 1]){ 
            dp[i] = true; 
		}
        else if (i - x >= 0 && !dp[i - x]){
            dp[i] = true; 
		}
        else if (i - y >= 0 && !dp[i - y]){
            dp[i] = true;
		}
  
        // Else A loses game. 
        else{
            dp[i] = false;
		}
    } 
  
    // If dp[n] is true then A will win the
    // game otherwise  he losses 
	string winner = (dp[n]) ? "Beerus" : "Whis";
	
	return winner;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}