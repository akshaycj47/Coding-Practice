#include <queue>
#include <list>
#include <iostream>

class Graph {
private:
    int V;                      // Number of vertices
    std::list<int>* adj;        // Pointer to array containing adj list
public:
    Graph( int V );               // Constructor
    void addEdge( int u, int v ); // Add edge to the Graph
    void BFT( int start );        // Breadth First Traversal
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

// Breadth First Traversal
void Graph::BFT( int start ) {

    // First create a visited boolean array to mark visited vertices
    bool* visited = new bool[ V ];
    for( int i = 0; i < V; i++ )
    {
        visited[ i ] = false;
    }

    // Create a queue to perform BFT
    std::queue<int> q;

    // Add start node to the queue and mark it as visited
    q.push( start );
    visited[ start ] = true;

    // Iterator to iterate through adjacency list
    std::list<int>::iterator it;

    // Traverse while queue is not empty
    while( !q.empty() )
    {

        int curr = q.front();
        std::cout << curr << " ";
        q.pop();

        for( it = adj[ curr ].begin(); it != adj[ curr ].end(); it++ )
        {

            // If vertex is not visited, add it to the queue
            if( visited[ *it ] == false )
            {

                q.push( *it );
                visited[ *it ] = true;
            }
        }
    }

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
    g.BFT( 2 );

    return 0;
}
