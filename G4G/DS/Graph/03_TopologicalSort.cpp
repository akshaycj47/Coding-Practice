#include <list>
#include <stack>
#include <iostream>

class Graph {
private:
    int V;                                                                           // Number of vertices
    std::list<int>* adj;                                                             // Pointer to array containing adj list
public:                                                                              
    Graph( int V );                                                                  // Constructor
    void addEdge( int u, int v );                                                    // Add edge to the Graph
    void DFTUtil( int start, bool* visited, std::stack<int>& result );               // Utility function for modified DFT
    void topologicalSort();                                                          // Perform topological sort
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

// Perform modified DFT
void Graph::DFTUtil( int start, bool* visited, std::stack<int>& result ) {

    // If vertex is already visited then return
    if( visited[ start ] )
    {
        return;
    }

    // Iterate through remaining elements
    std::list<int>::iterator it;
    for( it = adj[ start ].begin(); it != adj[ start ].end(); it++ )
    {
        DFTUtil( *it, visited, result );
    }

    // Add current element to the result and mark it as visited
    result.push( start );
    visited[ start ] = true;
}

// Perform topoligical sort
void Graph::topologicalSort() {

    // In topological sort, we have to perform modified version of Depth First Traversal
    // in which we first perfrom traversal, and then print element
    // We have to perform DFT on all elements though
    // Elements get stored in reverse order, so that can be implemented using stack

    // First created a visited array
    bool* visited = new bool[ V ];
    for( int i = 0; i < V; i++ )
    {
        visited[ i ] = false;
    }

    // Create a stack to store the result
    std::stack<int> result;

    // Perform modified DFT on all vertices
    for( int i = 0; i < V; i++ )
    {
        DFTUtil( i, visited, result );
    }

    // Print the result
    while( !result.empty() )
    {
        int top = result.top();
        std::cout << top << " ";
        result.pop();
    }
    std::cout << std::endl;
}

int main() {

    Graph g( 6 );
    g.addEdge( 5, 2 );
    g.addEdge( 5, 0 );
    g.addEdge( 2, 3 );
    g.addEdge( 3, 1 );
    g.addEdge( 4, 0 );
    g.addEdge( 4, 1 );

    // Find topological sort
    g.topologicalSort();
}
