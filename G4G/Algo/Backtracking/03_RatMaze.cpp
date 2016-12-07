#include <cstdio>
#define N 4

/**
* Function to print solution
* @params {matrix} sol - Solution matrix
*/
void printSolution(int sol[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", sol[i][j]);
		}
		printf("\n");
	}
}

/**
* Function to check if a given coordinate is valid
* @params {int} x - x coordinate
* @params {int} y - y coordinate
* @params {matrix} sol - Solution matrix
* @params {matrix} maze - Maze matrix
* @return {bool} True, if move is valid; else false
*/
bool isValidMove(int x, int y, int sol[N][N], bool maze[N][N]) {

	return x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1 && maze[x][y] == 1;
}

/**
* Utility function to solve maze puzzle
* @params {int} x - x coordinate of solution
* @params {int} y - y coordinate of solution
* @params {int} movei - Move number
* @params {matrix} sol - Solution matrix
* @params {matrix} maze - Maze matrix
* @params {array} xMove - Array of x coordinates of possible moves
* @params {array} yMove - Array of y coordinates of possible moves
* @return {bool} True, if maze can be solved; else false
*/
bool solveMazeUtil(int x, int y, int movei, int sol[N][N], bool maze[N][N], int xMoves[2], int yMoves[2]) {

	// Return true if we reach the end
	if (x == N - 1 && y == N - 1) {
		return true;
	}

	// Try all next moves from current coordinates (x, y)
	for (int k = 0; k < 2; k++) {
		int xNext = x + xMoves[k];
		int yNext = y + yMoves[k];
		if (isValidMove(xNext, yNext, sol, maze)) {
			sol[xNext][yNext] = movei;
			if (solveMazeUtil(xNext, yNext, movei + 1, sol, maze, xMoves, yMoves)) {
				return true;
			}
			else {
				sol[xNext][yNext] = -1;							// Backtracking
			}
		}
	}
	return false;
}

/**
* Function to solve maze
* @params {matrix} maze - Maze matrix
*/
void solveMaze(bool maze[N][N]) {

	// First create a solution matrix, and initialize it
	int sol[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sol[i][j] = -1;
		}
	}

	// We start from the position (0, 0)
	sol[0][0] = 0;

	// Possible moves of rat (rat can only move in forward or 
	// downward direction)
	int xMoves[2] = { 1, 0 };
	int yMoves[2] = { 0, 1 };

	// Start from (0, 0) and explore all moves using utility function
	if (solveMazeUtil(0, 0, 1, sol, maze, xMoves, yMoves) == true) {
		printSolution(sol);
	}
	else {
		printf("Solution could not be found\n");
	}
}

/**
* Starting point of the program
*/
int main() {

	bool maze[N][N] = { { 1, 0, 0, 0 },
						{ 1, 1, 0, 1 },
						{ 0, 1, 0, 0 },
						{ 1, 1, 1, 1 } };
	solveMaze(maze);
}