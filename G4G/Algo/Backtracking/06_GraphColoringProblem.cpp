#include <cstdio>
#define V 4

/**
* Function to print solution
* @params {array} color - Array which stores the color value of each vertex
*/
void printSolution(int* color) {

	printf("Following are the painted colors on the vertices:\n");
	for (int i = 0; i < V; i++) {
		printf("%d ", color[i]);
	}
	printf("\n");
}

/**
* Check if it is safe to color a vertex v with color c
* @params {matrix} graph - Adjacency matrix which represents the graph
* @params {array} color - Array which stores the color value of each vertex
* @params {int} c - Current color
* @params {int} v - Current vertex
* @return If color is valid then return true; else return false
*/
bool isSafe(bool graph[V][V], int* color, int c, int v) {

	// Check every adjacent vertex and see if it colored with the 
	// given color already. If it is not colored, then it is safe
	// to color given vertex with color c
	for (int i = 0; i < V; i++) {
		if (graph[v][i] && color[i] == c) {
			return false;
		}
	}
	return true;
}

/**
* Utility function to solve graph coloring problem
* @params {matrix} graph - Adjacency matrix which represents the graph
* @params {int} m - Minimum number of colors
* @params {array} color - Array which stores the color value of each vertex
* @params {int} v - Current vertex
*/
bool graphColoringUtil(bool graph[V][V], int m, int* color, int v) {

	// Base case: If all vertices assigned a color, then return true
	if (v == V) {
		return true;
	}

	// Consider this vertex v and try different colors
	for (int c = 1; c <= m; c++) {
		// Check if assignment of color c to vertex v is safe
		if (isSafe(graph, color, c, v)) {
			color[v] = c;
			
			// Check if this can be continued
			if (graphColoringUtil(graph, m, color, v + 1)) {
				return true;
			}
			else {
				color[v] = 0;					// Backtracking step
			}
		}
	}
	return false;
}

/**
* Function to solve graph coloring problem
* @params {matrix} graph - Adjacency matrix which represents the graph
* @params {int} m - Minimum number of colors
*/
void graphColoring(bool graph[V][V], int m) {

	// All vertices will initially color values as 0
	int* color = new int[V];
	for (int i = 0; i < V; i++) {
		color[i] = 0;
	}

	// Find if graphs can be colored such that no two adjacent 
	// vertices of the graph are colored with same color
	if (graphColoringUtil(graph, m, color, 0)) {
		printSolution(color);
	}
	else {
		printf("Solution not found\n");
	}
}

/**
* Starting point of the program
*/
int main() {

	/* Create following graph and test whether it is 3 colorable
		(3)---(2)
		 |   / |
		 |  /  |
		 | /   |
		(0)---(1)
	*/
	bool graph[V][V] = { { 0, 1, 1, 1 },
						 { 1, 0, 1, 1 },
						 { 1, 1, 0, 1 },
						 { 1, 0, 1, 0 } };
	int m = 3;
	graphColoring(graph, m);
	return 0;
}