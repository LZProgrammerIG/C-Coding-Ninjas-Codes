/*
Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is 
possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)

Your task is to find if it is possible to reach the destination point using only the desired 
moves or not.

For example:- 
For the coordinates, source point = (1, 1) and destination point = (3, 5)
The output will be true as the destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)

Input Format:- 
The first line of input contains an integer 'T' representing the number of test cases. Then the 
test cases follow.

The only line of each test case contains four space-separated integers sx, sy, dx, and dy where 
sx, sy represents the coordinates of the source point and dx, dy represents the coordinates of 
the destination point.

Output Format:- 
For each test case, return the boolean true if the destination point can be reached from the 
source point using only the desired moves, else return false.

The output for each test case is to be printed on a separate line.
*/



#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Base cases
    if (sx > dx || sy > dy) {
        return false;
    }

    // Current point is equal to destination
    if (sx == dx && sy == dy) {
        return true;
    }

    // Recursive Calls
    // Check for other 2 possibilities
    //return (reachDestination(sx + sy, sy, dx, dy) || reachDestination(sx, sy + sx, dx, dy));


    // Instead of going from source to destination, we go to source from destination.
    // This way the recursive calls will be less.
    if (dy > dx){
        return reachDestination(sx, sy, dx, dy - dx);
    }
    
    return reachDestination(sx, sy, dx - dy, dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a>> b>> c>> d;

        
        if(reachDestination(a,b,c,d)){
            cout<< "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}