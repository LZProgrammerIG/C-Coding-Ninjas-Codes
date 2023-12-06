/* Given an undirected, connected and weighted graph G(V, E) with V number 
of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.

For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and 
whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while 
printing an edge.

2. Print V-1 edges in above format in different lines.
 */
#include <iostream>
#include <climits>

using namespace std;

int findMinVertex(int *weight, bool *visited, int size){
    int minWeight = INT_MAX;
    int ans = -1;

    for (int i = 0; i < size; i++){
        if (visited[i]){
            continue;
        }

        if (weight[i] < minWeight){
            minWeight = weight[i];
            ans = i;
        }
    }

    return ans;
}

void Build_MST_Prims(int** edges, int* parents, 
                    int* weight, bool* visited, int V){
        
    // Main Code

    for (int i = 0; i < V; i++){
        int minVertex = findMinVertex(weight, visited, V);

        // Marking minVertex as visited.
        visited[minVertex] = true;

        // Finding adjacent vertex of minVertex
        for (int j = 0; j < V; j++){
            if (edges[minVertex][j] > 0 && !visited[j] ){

                if (weight[j] > edges[minVertex][j]){  
                    weight[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // Creating the adjaceny matrix for input.
    int **edges = new int*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new int[V] ();
    }

    // Taking input
    int first, second, Weight;

    for(int i = 0; i < E; i++){
        cin >> first >> second >> Weight;
        edges[first][second] = Weight;
        edges[second][first] = Weight;
    }

    // Creating parents, weight and visited array.
    int *parents = new int[V] ();
    parents[0] = -1;
    
    int *weight = new int[V];
    weight[0] = 0;
    for (int i = 1; i < V; i++){
        weight[i] = INT_MAX; 
    }

    bool *visited = new bool[V] ();


    // Time for Prim's Algorithm
    // Lets start with 0.

   Build_MST_Prims(edges, parents, weight, visited, V);

    // Printing the MST.
    for (int i = 1; i < V; i++){
        cout << min(i, parents[i]) << " ";
        cout << max(i, parents[i]) << " ";
        cout << weight[i] << endl;
    }

    // Deleting all the dynamic arrays.
    delete [] parents;
    delete [] visited;
    delete [] weight;

    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
