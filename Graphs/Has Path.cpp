/* Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:- 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G. */
  
#include <iostream>
using namespace std;

bool HasPath(bool **edges, bool *visited, int size, int target, int start = 0){
    // Base Case
    // Return true if staring vertex has a direct edge with target.
    if (edges[start][target]){
        return true;
    }

    // Main Code
    
    // Marking starting vertex as visited.
    visited[start] = true;

    for (int i = 0; i < size; i++){
        if (edges[start][i] && !visited[i] ){
            if (HasPath(edges, visited, size, target, i)){
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V,E;
    cin >> V >> E;

    bool **edges = new bool*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new bool[V] ();

        /* for (int j = 0; j < V; j++){
            edges[i][j] = false;
        } */
    }

    int first, second;
    for (int i = 0; i < E; i++){
        cin >> first >> second;

        edges[first][second] = true;
        edges[second][first] = true;
    }

    bool *visited = new bool[V] ();

    int start, end;
    cin >> start >> end;

    string ans = (HasPath(edges, visited, V, end, start)) ? "true" : "false";
    cout << ans << endl;

    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
}
