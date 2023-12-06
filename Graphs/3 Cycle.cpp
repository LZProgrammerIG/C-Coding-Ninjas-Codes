/* Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, 
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which 
(P,Q), (Q,R) and (R,P) are connected by an edge.

The first line of input contains two space separated integers, that denotes the 
value of N and M.
Each of the following M lines contain two integers, that denote the vertices which 
have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 

Print the count the number of 3-cycles in the given graph
*/

#include <iostream>
using namespace std;

int get3Cycles(bool **edges, int size){
    int count = 0;
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            
            /* If there is an edge between i and j, then it will
            find the value of k for which j and k share an
            edge. */

            if (edges[i][j]){
                for (int k = 0; k < size; k++){
                    
                    // To avoid an infinite loop between two points.
                    if (k == i){
                        continue;
                    }

                    /* After finding the value of k, we will check if
                    k and i has an edge with each other. If yes, 
                    then there is a cycle between i, j and k. */

                    if (edges[j][k] && edges[i][k]){
                        count++;
                    }
                }
            }
            
            
        }
    }

    /* Dividing count by 6 because each point in a cycle will give
    us the answer 2 (1 for clockwise + 1 for anticlockwise).
    Thus, one cycle will give us the answer 6 as it has 3 points.
    Therefore, our final answer will be a multiple of 6 and so we
    need to divide our count by 6 to give us the correct answer. */
    
    return count/6;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Creating the adjaceny matrix.
    bool **edges = new bool*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new bool[V] ();
    }

    // Taking input in the matrix.
    int first, second;

    for (int i = 0; i < E; i++){
        cin >> first >> second;
        edges[first][second] = true;
        edges[second][first] = true;    
    }

    // Calling our get cycle function.
    cout << get3Cycles(edges, V) << endl;

    // Deleting our matrix.
    for (int i = 0; i < V; i++){
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}
