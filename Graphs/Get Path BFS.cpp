/* Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there 
is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note:- 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix. */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void getPathBFS(bool **edges, int size, int target, int start = 0){
    /* Creating a visited array which will store all the vertices
    encountered by the function to avoid an infinite cycle of
    calls between two adjacent vertices. */
    bool *visited = new bool[size] ();
    visited[start] = true;

    // Creating a queue for BFS approach.
    queue<int> pendingVertices;
    pendingVertices.push(start);

    /* Creating a map which will store the starting vertex as value
    and the vertices appended in the queue by the starting 
    vertex as keys. This way we can backtrack which vertex was
    responsible for appending our target vertex and so on. */
    unordered_map<int, int> path;
    path[target] = -1;

    // A flag to break the while loop when target vertex enters 
    // the queue.
    bool flag = true;


    while (!pendingVertices.empty() && flag){
        int currVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < size; i++){
            if (edges[currVertex][i] && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;

                path[i] = currVertex;

                if (i == target){
                    flag = false;
                    break;
                }
            }
        }
    }

    // Now time to use our map to reconstruct the path from 
    // target to starting vertex.
    if (path[target] != -1){
        int papa = path[target];

        cout << target << " ";
        while (papa != start){
            cout << papa << " ";
            papa = path[papa];
        }

        cout << papa << " " << endl;
    }

    // War's over mate. You can rest in peace now.
    delete[] visited;
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


    int start, end;
    cin >> start >> end;

    getPathBFS(edges, V, end, start);
    
    // Deleting all the dynamic arrays.
    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;
}
