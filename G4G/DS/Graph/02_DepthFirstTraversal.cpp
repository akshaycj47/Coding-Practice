#include <list>
#include <iostream>

class Graph {
private:
    int V;                                                  // Number of vertices
    std::list<int>* adj;                                    // Pointer to array containing adj list
public:
    Graph( int V );                                         // Constructor
    void addEdge( int u, int v );                           // Add edge to the Graph
    void DFT( int start );                                  // Depth First Traversal
    void DFTUtil( int start, bool* visited );               // Utility function for DFT
};

// Constructor
Graph::Graph( int V ) {

    this->V = V;
    adj = new std::list<int>[ V ];
}

// Add edge
void Graph::addEdge( int u, int v ) {

    adj[ u ].push_back( v );            // Add v to u's list
}

// Utility function for DFT
void Graph::DFTUtil( int start, bool* visited ) {

    // If given vertex is already visited, then return
    if( visited[ start ] )
    {
        return;
    }

    // Print current element and mark it as visited
    std::cout << start << " ";
    visited[ start ] = true;

    // Iterate through remaining elements
    std::list<int>::iterator it;
    for( it = adj[ start ].begin(); it != adj[ start ].end(); it++ )
    {
        DFTUtil( *it, visited );
    }
}

// Depth First Traversal
void Graph::DFT( int start ) {

    // First create a visited boolean array to mark visited vertices
    bool* visited = new bool[ V ];
    for( int i = 0; i < V; i++ )
    {
        visited[ i ] = false;
    }

    DFTUtil( start, visited );
    std::cout << "\n";
}

int main() {

    Graph g( 4 );
    g.addEdge( 0, 1 );
    g.addEdge( 0, 2 );
    g.addEdge( 1, 2 );
    g.addEdge( 2, 0 );
    g.addEdge( 2, 3 );
    g.addEdge( 3, 3 );

    // Print BFT starting from vertex 2
    g.DFT( 2 );

    // Print BFT starting from vertex 0
    g.DFT( 0 );

    return 0;
}
