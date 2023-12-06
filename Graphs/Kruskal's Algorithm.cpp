/* Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose 
weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.

2. Print V-1 edges in above format in different lines. */

#include <iostream>
#include <algorithm>

using namespace std;

class Edge{
    public:
        // Data members
        int source;
        int destination;
        int weight;

        // Default Constructor
        Edge(){
            source = 0;
            destination = 0;
            weight = 0;
        }

        // Parametrized Constructor
        Edge(int source, int destination, int weight){
            this -> source = source;
            this -> destination = destination;
            this -> weight = weight;
        }
};


// Comparator function to sort our input array in
// ascending order on basis of weight.
bool CompareWeight(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void takeinput(Edge* input, int size){
    int source, destination, weight;
    
    for (int i = 0; i < size; i++){
        cin >> source >> destination >> weight;
        
        Edge e1(source, destination, weight);
        input[i] = e1;
    }

    // Sorting the input array on the basis of weight.
    sort(input, input + size, CompareWeight);
}


// Finds the top parent of a vertex.
int findAncestor(int* parent, int num){
    int ancestor = parent[num];

    // A vertex has no parent if it is the parent of itself.
    // Means it has no parent if parent[vertex] == vertex.
    while (parent[ancestor] != ancestor){
        ancestor = parent[ancestor];
    }

    return ancestor;
}

// NOTE :- 
// Union by rank and path compression algorithm should be
// used instead of union find algorithm for cycle detection.
void Build_MST(Edge* input, int E, Edge* output, int V){
    /* Creating a parent array to avoid cycle formation.
    Every vertex is a parent of itself. If two vertices have
    same parent, then that means we have a path between
    them. So connecting those two vertices together will
    definitely form a cycle. Hence we will join those vertices
    only which have different parents. */
    int *parent = new int[V];
    for (int i = 0; i < V; i++){
        parent[i] = i;
    }

    // Maintaining a count to break the loop after our output
    // array is completely filled.
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++){
        Edge e1 = input[i];

        int source_ancestor = findAncestor(parent, e1.source);
        int dest_ancestor = findAncestor(parent, e1.destination);

        if (source_ancestor == dest_ancestor){
            // Connecting them will form a cycle. Hence skip,
            continue;
        }

        /* After forming a connection between source and
        destination, the ancestor of source will also become the
        ancestor of the destination's ancestor. */
        parent[dest_ancestor] = source_ancestor;

        // Forming the edge between source and destination
        // in our MST.
        output[count] = e1;
        count++;
    }

    // Deleting Array.
    delete [] parent;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Creating input array.
    Edge* input = new Edge[E];

    // Creating an output array.
    // MST will have V-1 edges.
    Edge* output = new Edge[V - 1];

    takeinput(input, E);

    Build_MST(input, E, output, V);

    // Printing the MST
    for (int i = 0; i < V - 1; i++){
        Edge e1 = output[i];

        cout << min(e1.source, e1.destination) << " ";
        cout << max(e1.source, e1.destination) << " ";
        cout << e1.weight << endl; 
    }

    // Deleting the Arrays.
    delete [] input;
    delete [] output;
}
