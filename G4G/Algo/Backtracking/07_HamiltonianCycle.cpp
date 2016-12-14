#include <cstdio>
#define V 5

/**
* Function to print solution
* @params {array} path - Array which stores the vertex for a given position
*/
void printSolution(int* path) {

	printf("Following represents the Hamiltonian Path:\n");
	for (int i = 0; i < V; i++) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

/**
* Check if it is safe to color a vertex v with color c
* @params {matrix} graph - Adjacency matrix which represents the graph
* @params {array} path - Array which stores the vertex for a given position
* @params {int} v - Current vertex
* @params {int} pos - Current position
* @return If color is valid then return true; else return false
*/
bool isSafeMove(bool graph[V][V], int* path, int v, int pos) {

	// Check if there is a link between current vertex and 
	// vertex on the previous position
	if (graph[path[pos - 1]][v] == false) {
		return false;
	}

	// Check if the vertex has been already included
	for (int i = 0; i < V; i++) {
		if (path[i] == v) {
			return false;
		}
	}
	return true;
}

/**
* Utility function to find Hamiltonian Cycle
* @params {matrix} graph - Adjacency matrix which represents the graph
* @params {array} path - Array which stores the vertex for a given position
* @params {int} pos - Current position
*/
bool hamiltonianCycleUtil(bool graph[V][V], int* path, int pos) {

	// Base case: If all vertices are included in the Hamiltonian cycle
	if (pos == V) {
		// If there is an edge from last included vertex to the first vertex
		if (graph[0][path[pos - 1]]) {
			return true;
		}
		return false;
	}

	// Try different vertices as the next candidates for the Hamiltonian cycle
	// We don't include 0 as we included 0 as the starting path of the Hamiltonian cycle
	for (int v = 1; v < V; v++) {
		// Check if current vertex can be considered for given position
		if (isSafeMove(graph, path, v, pos)) {
			// Mark the vertex with current position
			path[pos] = v;

			// Check if solution (path) can be continued
			if (hamiltonianCycleUtil(graph, path, pos + 1)) {
				return true;
			}
			else {
				path[pos] = -1;								// Backtrack
			}
		}
	}
	return false;
}

/**
* Function to find Hamiltonian Cycle, if any
* @params {matrix} graph - Adjacency matrix which represents the graph
*/
void hamiltonianCycle(bool graph[V][V]) {

	// Create a solution array which stores the path
	// or order in which we traverse each vertex
	// Initially all vertices are unvisited
	int* path = new int[V];
	for (int i = 0; i < V; i++) {
		path[i] = -1;
	}

	// Start finding Hamiltonian path using the utility function
	// Let's put vertex 0 as the first vertex of the path. If there is 
	// a Hamiltonian cycle, the path can begin from any vertex since the 
	// graph is undirected
	path[0] = 0;
	if (hamiltonianCycleUtil(graph, path, 1)) {
		printSolution(path);
	}
	else {
		printf("Hamiltonian cycle not possible\n");
	}
}

/**
* Starting point of the program
*/
int main() {

	/* Let us create the following graph
	(0)--(1)--(2)
	 |   / \   |
	 |  /   \  |
	 | /     \ |
	(3)-------(4)    */
	bool graph1[V][V] = { { 0, 1, 0, 1, 0 },
						  { 1, 0, 1, 1, 1 },
						  { 0, 1, 0, 0, 1 },
						  { 1, 1, 0, 0, 1 },
						  { 0, 1, 1, 1, 0 },
						  };
	hamiltonianCycle(graph1);

	/* Let us create the following graph
	(0)--(1)--(2)
	 |   / \   |
	 |  /   \  |
	 | /     \ |
	(3)       (4)    */
	bool graph2[V][V] = { { 0, 1, 0, 1, 0 },
						  { 0, 1, 0, 0, 1 },
						  { 1, 1, 0, 0, 0 },
						  { 0, 1, 1, 0, 0 },
						  { 1, 0, 1, 1, 1 },
						  };
	hamiltonianCycle(graph2);

	return 0;
}