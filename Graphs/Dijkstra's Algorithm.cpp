/* Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all 
other vertices (including source vertex also) using Dijkstra's Algorithm.

For each vertex, print its vertex number and its distance from source, in a separate 
line. The vertex number and its distance needs to be separated by a single space. */

#include <iostream>
#include <climits>

using namespace std;

int findMinVertex(int *distance, bool*visited, int V){
    // Returns the unvisited vertex with lowest
    // weight in the distance array.
    int minVertex = -1;
    
    for (int i = 0; i < V; i++){
        if (visited[i]){
            continue;
        }

        if (minVertex == -1 || distance[i] < distance[minVertex]){
            minVertex = i;
        }
    }

    return minVertex;
}

void Dijkstra(int **edges, int V){
    // Creating visited and distance (weight) array.
    bool *visited = new bool[V] ();

    // Distance array will store shortest distance of 
    // a vertex from 0.
    int *distance = new int[V];
    distance[0] = 0;
    for (int i = 1; i < V; i++){
        distance[i] = INT_MAX;
    }

    // No need to visit the last vertex, since all the 
    // adjacent vertices to it will have been visited 
    // already. So the loop will run only V - 1 times.
    for(int i = 0; i < V - 1; i++){
        int minVertex = findMinVertex(distance, visited, V);

        // Marking the minVertex as visited.
        visited[minVertex] = true;

        // Traversing the adjacnt vertices of minVertex.
        for (int j = 0; j < V; j++){
            if (edges[minVertex][j] > 0 && !visited[j]){
                
                // Calculating distance of adjacent vertex
                // from the source (0).
                int minDistance = distance[minVertex] + 
                                    edges[minVertex][j];

                // If this current distance is shorter than the
                // previous distance of the adjacent vertex 
                // from the source, then update the value.
                if (minDistance < distance[j]){
                    distance[j] = minDistance;
                }
            }
        }
    }

    // Printing vertices and their distance from the source.
    for (int i = 0; i < V; i++){
        cout << i << " " << distance[i] << endl;
    }

    // Deleting dynamic arrays.
    delete[] visited;
    delete[] distance;
}

int main() {
    // To reduce time complexity:- 
    // Use priority queue to store weights/distances.
    // Use Adjancy List insted of matrix.

    // Code is same as prims algorithm, just using the
    // above two methods will reduce time complexity.
    // From V^2 to (E+V)logV.

    int V,E;
    cin >> V >> E;

    // Using adjancy matrix to store edges.
    int **edges = new int*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new int[V] ();
    }

   // Taking input in matrix.
   int first, second, distance;
   for (int i = 0; i < E; i++){
       cin >> first >> second >> distance;
       
       edges[first][second] = distance;
       edges[second][first] = distance;
    }

    // Using Dijkstra's Algorithm to print all the vertices
    // and their shortest distance from source (0).

    Dijkstra(edges, V);

    // Deleting dynamic arrays.
    for (int i = 0; i < V; i++){
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
