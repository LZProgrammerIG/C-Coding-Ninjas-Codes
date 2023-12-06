/*
Given an undirected and disconnected graph G(V,E). Print its Breadth First Search Traversal
starting from vertex 0.
Note:- 
1. V is the number of vertices numbered from 0 to V - 1.
2. E is the number of edges in graph G.
3. Handle for disconnected graph as well.
*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void printBFS(bool **edges, int size, 
                unordered_map<int, bool> &visited, int startVertex = 0){
    // Shitty Edge Case
    if (size == 0){
        return;
    }
    
    // Main Code
    queue<int> print;
    print.push(startVertex);

    while (!print.empty()){
        // Printing the element.
        int element = print.front();
        cout << element << " ";

        // Inserting the element in map.
        visited[element] = true;

        // Searching edges for that element in the array.
        for (int i = 0; i < size; i++){
            
            // If i has an edge with the element and i was never
            // printed (i doesn't exist in map) then we push i in
            // the queue.
            if (edges[element][i] && !visited[i] ){
                print.push(i);

                // Marking i as visited.
                visited[i] = true;
            }
        }

        // Removing the element from queue.
        print.pop();
    }

    // Calling recursion on  the vertices which are not connected
    // to our mainland.
    for (int i = 1; i < size; i++){
        if (!visited[i]){
            printBFS(edges, size, visited, i);
        }
    }
}

void takeinput(bool **edges, int E){
    int first_int, second_int;

    for (int i = 0; i < E; i++){
        cin >> first_int >> second_int;

        edges[first_int][second_int] = true;
        edges[second_int][first_int] = true;
    }
}   

int main() {
    int V,E;
    cin >> V >> E;

    bool **edges = new bool*[V];
    for (int i = 0; i < V; i++){
        edges[i] = new bool[V];

        for (int j = 0; j < V; j++){
            edges[i][j] = false;
        }
    }

    takeinput(edges, E);

    // Creating a map for our print function.
    unordered_map<int, bool> visited;
    printBFS(edges, V, visited);
}
