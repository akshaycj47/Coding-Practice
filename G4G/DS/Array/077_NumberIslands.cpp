#include <cassert>
#include <iostream>

/**
 * Function marks the visited coordinates of the matrix
 * @params {matrix} arr - Given 2D matrix of dimensions 5x5
 * @params {matrix} visited - Auxiliary 2D matrix to mark visited coordinates
 * @params {int} i - x coodinate of point to be marked as visited
 * @params {int} j - y coodinate of point to be marked as visited
 * @params {int} row - Number of rows in 2D matrix
 * @params {int} col - Number of columns in 2D matrix
 */
void markVisited(int arr[5][5], bool** visited, int i, int j, int row, int col) {

	// Remove invalid coordinates
	if (i < 0 || i >= row || j < 0 || j >= col) {
		return;
	}

	// Discard invalid and already visitedcoordinates
	if (arr[i][j] == 0 || visited[i][j] == true) {
		return;
	}

	// Mark current and joint coordinates as visited
	visited[i][j] = true;
	markVisited(arr, visited, i - 1, j - 1, row, col);
	markVisited(arr, visited, i - 1, j, row, col);
	markVisited(arr, visited, i - 1, j + 1, row, col);
	markVisited(arr, visited, i, j - 1, row, col);
	markVisited(arr, visited, i, j + 1, row, col);
	markVisited(arr, visited, i + 1, j - 1, row, col);
	markVisited(arr, visited, i + 1, j, row, col);
	markVisited(arr, visited, i + 1, j + 1, row, col);
}

/**
 * Function which counts number of islands in a given matrix
 * @params {matrix} arr - Given 2D matrix of dimensions 5x5
 * @return {int} Number of islands
 */
int numIslands(int arr[5][5]) {

	int row = 5;
	int col = 5;

	// First create a boolean matrix to store the visited coordinates
	bool** visited = new bool*[row];
	for (int i = 0; i < row; i++) {
		visited[i] = new bool[col];
	}
	// Initialize every coordinate as false
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visited[i][j] = false;
		}
	}

	// Start counting the number of islands
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				count++;
				markVisited(arr, visited, i, j, row, col);
			}
		}
	}
	return count;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[5][5] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};
    assert(numIslands(arr) == 5);
}