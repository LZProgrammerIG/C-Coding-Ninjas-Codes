/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there 
is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.

Note:- 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix. */

#include <iostream>
#include <vector>

using namespace std;

void getPath(bool **edges, int size, bool *visited, vector<int> &ans, 
        int target, int start = 0){
                
    // Pushing start vertex in the visite array.
    visited[start] = true;
    
    // Base Cases
    if (start == target){
        ans.push_back(target);
        return;
    }

    // Checking if the starting vertex has a direct edge with
    // the target.
    /* if (edges[start][target]){
        ans.push_back(target);
        ans.push_back(start);
        return;
    } */

    // Main Code

    // Calling recursion on all the vertices ajacent to the 
    // starting vertex.
    for (int i = 0; i < size; i++){
        if (edges[start][i] && !visited[i] ){
            getPath(edges, size, visited, ans, target, i);

            // If there exists a path, then ans vector won't be
            // empty.
            if (ans.size() > 0){
                ans.push_back(start);
                return;
            }
        }
    }
    
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

    /* Creating a visited array which will store all the vertices
    encountered by the function to avoid an infinite cycle of
    calls between two adjacent vertices. */
    bool *visited = new bool[V] ();

    vector<int> ans;

    int start, end;
    cin >> start >> end;


    getPath(edges, V, visited, ans, end, start);
    
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    // Deleting all the dynamic arrays.
    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
}
