#include <iostream>
#include <cstdio>
#define N 7

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
* @return {bool} True, if move is valid; else false
*/
bool isValidMove(int x, int y, int sol[N][N]) {

	return x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1;
}

/**
* Utility function to solve knight's tour
* @params {int} x - x coordinate of solution
* @params {int} y - y coordinate of solution
* @params {int} movei - Move number
* @params {matrix} sol - Solution matrix
* @params {array} xMove - Array of x coordinates of possible moves
* @params {array} yMove - Array of y coordinates of possible moves
* @return {bool} True, if tour is possible; else false
*/
bool solveKnightsTourUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N])  {

	// Check if all moves over
	if (movei == N * N) {
		return true;
	}

	// Try all next moves from current coordinates (x, y)
	for (int k = 0; k < 8; k++) {
		int nextX = x + xMove[k];
		int nextY = y + yMove[k];
		if (isValidMove(nextX, nextY, sol)) {
			sol[nextX][nextY] = movei;
			if (solveKnightsTourUtil(nextX, nextY, movei + 1, sol, xMove, yMove) == true) {
				return true;
			}
			else {
				sol[nextX][nextY] = -1;							// Backtracking
			}
		}
	}
	return false;
}

/**
* Function to solve knight's tour
*/
void solveKnightsTour() {

	// Create a solution matrix, and initialize it
	int sol[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sol[i][j] = -1;
		}
	}

	// xMove[] and yMove[] define the next move of the knight
	// xMove[] is for next value of x coordinate
	// yMove[] is for next value of y coordinate
	int xMove[8] = { -1, 1, -1, 1, -2, -2, 2, 2 };
	int yMove[8] = { -2, -2, 2, 2, -1, 1, -1, 1 };

	// Knight is initially on the first blocl
	sol[0][0] = 0;

	// Start from (0, 0) and explore all tours using utility function
	if (solveKnightsTourUtil(0, 0, 1, sol, xMove, yMove) == false) {
		printf("Solution does not exist\n");
	}
	else {
		printSolution(sol);
	}
}

/**
* Starting point of the program
*/
int main() {

	solveKnightsTour();
	return 0;
}