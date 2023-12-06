/* Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:- 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
 */

#include <iostream>
using namespace std;

void isConnected(bool **edges, int size, bool *visited, int start = 0){            
    // Pushing start vertex in the visite array.
    visited[start] = true;
    
    // Calling recursion on all the vertices ajacent to the 
    // starting vertex.
    for (int i = 0; i < size; i++){
        if (edges[start][i] && !visited[i] ){
            isConnected(edges, size, visited, i);
        }
    }   
}

bool isConnected(bool **edges, int size){
    /* Creating a visited array which will store all the vertices
    encountered by the function to avoid an infinite cycle of
    calls between two adjacent vertices. */
    bool *visited = new bool[size] ();

    isConnected(edges, size, visited);

    bool ans = true;

    // if the visited array is all marked with true, then that means
    // the graph is connected.
    for (int i = 0; i < size; i++){
        if (!visited[i]){
            ans = false;
        }
    }

    delete[] visited;
    return ans;
}

int main() {
    int V,E;
    cin >> V >> E;

    // Creating a 2D eges matix to store the edges.
    bool **edges = new bool*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new bool[V] ();
    }

    // Taking input in the edges matrix.
    int first, second;
    for (int i = 0; i < E; i++){
        cin >> first >> second;

        edges[first][second] = true;
        edges[second][first] = true;
    }

   

    string ans = (isConnected(edges, V) ) ? "true" : "false";
    cout << ans << endl;

    
    // Deleting all the dynamic arrays.
    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;
}
