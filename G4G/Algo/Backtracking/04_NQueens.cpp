#include <cstdio>

/**
* Function to print solution
* @params {matrix} board - Chess board
* @params {int} N - Dimensions of chess board
*/
void printSolution(int** board, int N) {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

/**
* Function to check if we can place a queen safely on this 
* position on the board
* @params {matrix} board - Chess board
* @params {int} row - Row coordinate of chess board
* @params {int} col - Column coordinate of chess board
* @params {int} N - Dimensions of chess board
* @return {bool} True, if move is valid; else false
*/
bool isValidMove(int** board, int row, int col, int N) {

	// Check the horizontal left side
	for (int j = 0; j < col; j++) {
		if (board[row][j]) return false;
	}

	// Check for upper diagonal left side
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) return false;
	}

	// Check for lower diagonal left side
	for (int i = row, j = col; i < N && j >= 0; i++, j--) {
		if (board[i][j]) return false;
	}

	return true;
}

/**
* Utility function to solve N Queens
* @params {matrix} sol - Solution matrix
* @params {int} col - Current column coordinate of chess board
* @params {int} N - Dimensions of chess board
* @return {bool} True, if N Queens can be placed; else false
*/
bool solveNQueensUtil(int** board, int col, int N) {

	// If all queens are placed then return true
	if (col >= N) {
		return true;
	}

	// Fix this column and try placing queen in every row of this column
	for (int i = 0; i < N; i++) {

		// Check if queen can be placed on the board
		if (isValidMove(board, i, col, N)) {

			// Place a queen on this position
			board[i][col] = 1;

			// Check if it generates a correct solution
			if (solveNQueensUtil(board, col + 1, N)) {
				return true;
			}

			// Backtrack, remove queen from the board
			board[i][col] = 0;
		}
	}
	// Queen cannot be placed on any row in this column
	return false;
}

/**
* Function to solve N Queens
* @params {int} N - Dimensions of chess board
*/
void solveNQueens(int N) {

	// Create a board of size NxN
	int** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[N];
	}

	// Initialize the board
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}

	// Solve N Queens problem, passing the first column
	if (solveNQueensUtil(board, 0, N)) {
		printSolution(board, N);
	}
	else {
		printf("Solution not possible\n");
	}
}

/**
* Starting point of the program
*/
int main() {

	solveNQueens(4);
	solveNQueens(5);
	solveNQueens(3);
	solveNQueens(8);
	return 0;
}