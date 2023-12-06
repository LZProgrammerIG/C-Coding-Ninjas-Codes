/* Given an undirected graph G(V,E), find and print all the connected components 
of the given graph G.

Note:- 
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the 
  connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in 
increasing order (separated by space). Order of different components doesn't matter. */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Allcomponents(bool **edges, int size, bool *visited, int start = 0){
    //  Creating the mini answer array
    vector<int> mini_ans;
    
    // Marking starting vertex in visited array.
    visited[start] = true;

    // Creating a queue for BFS approach.
    queue<int> pendingVertices;
    pendingVertices.push(start);

    while (!pendingVertices.empty() ){
        int currVertex = pendingVertices.front();
        mini_ans.push_back(currVertex);
        pendingVertices.pop();

        for (int i = 0; i < size; i++){
            if (edges[currVertex][i] && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return mini_ans;
}

vector<vector<int>> Allcomponents(bool **edges, int size){
    // Creating the ans vector
    vector<vector<int>> ans;

    /* Creating a visited array which will store all the vertices
    encountered by the function to avoid an infinite cycle of
    calls between two adjacent vertices. */
    bool *visited = new bool[size] ();
    
    for (int i = 0; i < size; i++){
        if (!visited[i] ){
            vector<int> MiniAns = Allcomponents(edges, size, visited, i);
            sort(MiniAns.begin(), MiniAns.end() );
            ans.push_back(MiniAns);
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


    int start, end;
    cin >> start >> end;

    vector<vector<int>> Ans = Allcomponents(edges, V);
    for (int i = 0; i < Ans.size(); i++){
        for (int j = 0; j < Ans[i].size(); j++){
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }
    
    // Deleting all the dynamic arrays.
    for (int i = 0; i < V; i++){
        delete [] edges[i];
    }

    delete [] edges;
}
