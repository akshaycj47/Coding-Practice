#include <cstdio>
#define N 9
#define UNASSIGNED 0

/**
* Function to print given Sudoku grid
* @params {matrix} grid - Sudoku grid
*/
void printGrid(int grid[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/**
* Function to check if a given number is present on current row
* @params {matrix} grid - Sudoku grid
* @params {int} row - Row index of current position
* @params {int} col - Col index of current position
* @params {int} num - Given number to be checked
* @return {bool} If number is present on the current row, 
* return true; else return false
*/
bool numPresentRow(int grid[N][N], int row, int col, int num) {

	for (int j = 0; j < N; j++) {
		if (grid[row][j] == num) {
			return true;
		}
	}
	return false;
}

/**
* Function to check if a given number is present on current column
* @params {matrix} grid - Sudoku grid
* @params {int} row - Row index of current position
* @params {int} col - Col index of current position
* @params {int} num - Given number to be checked
* @return {bool} If number is present on the current column, 
* return true; else return false
*/
bool numPresentCol(int grid[N][N], int row, int col, int num) {

	for (int i = 0; i < N; i++) {
		if (grid[i][col] == num) {
			return true;
		}
	}
	return false;
}

/**
* Function to check if a given number is present on current 3x3 sub-grid
* @params {matrix} grid - Sudoku grid
* @params {int} row - Row index of current position
* @params {int} col - Col index of current position
* @params {int} gridRowBegin - Start row index of 3x3 sub-grid
* @params {int} gridColBegin - Start col index of 3x3 sub-grid
* @params {int} num - Given number to be checked
* @return {bool} If number is present on the current 3x3 sub-grid, 
* return true; else return false
*/
bool numPresentSubGrid(int grid[N][N], int row, int col, int gridRowBegin, int gridColBegin, int num) {

	for (int i = gridRowBegin; i < gridRowBegin + 3; i++) {
		for (int j = gridColBegin; j < gridColBegin + 3; j++) {
			if (grid[i][j] == num) {
				return true;
			}
		}
	}
	return false;
}

/**
* Function to check if a given number can be placed on the 
* current position
* @params {matrix} grid - Sudoku grid
* @params {int} row - Row index of current position
* @params {int} col - Col index of current position
* @params {int} num - Given number to be checked
* @return {bool} If number can be placed on the current position, 
* return true; else return false
*/
bool isSafeMove(int grid[N][N], int row, int col, int num) {

	// Check if number is present in current row, current column, or current subgrid
	if (numPresentRow(grid, row, col, num) || numPresentCol(grid, row, col, num) || numPresentSubGrid(grid, row, col, row - row%3, col - col%3, num)) {
		return false;
	}
	return true;
}

/**
* Function to find unassigned position in the Sudoku grid
* @params {matrix} grid - Sudoku grid
* @params {int} row - Row index of unassigned position
* @params {int} col - Col index of unassigned position
* @return {bool} If unassigned position is found, return true;
* else return false
*/
bool findUnassignedPosition(int grid[N][N], int& row, int& col) {

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (grid[row][col] == UNASSIGNED) {
				return true;
			}
		}
	}
	return false;
}

/**
* Utility function to solve Sudoku
* @params {matrix} grid - Sudoku grid
* @return {bool} If Sudoku can be solved, return true; else false
*/
bool solveSudokuUtil(int grid[N][N]) {

	int row;
	int col;
	// If all positions in the grid are assigned, then Sudoku is solved
	if (!findUnassignedPosition(grid, row, col)) {
		return true;
	}

	// Now that unassisgned position is found, we can try out numbers 1 to 9 (N)
	for (int num = 1; num <= N; num++) {

		// Check if it is safe to place that number on unassigned position
		if (isSafeMove(grid, row, col, num)) {

			// Assign the number to this position
			grid[row][col] = num;

			// Continue and see if the solution is valid
			if (solveSudokuUtil(grid)) {
				return true;
			}
			else {
				grid[row][col] = UNASSIGNED; 				// Backtracking
			}
		}
	}
	return false;
}

/**
* Function to solve Sudoku
* @params {matrix} grid - Sudoku grid
*/
void solveSudoku(int grid[N][N]) {

	if (solveSudokuUtil(grid)) {
		printf("Solved Sudoku\n");
		printGrid(grid);
	}
	else {
		printf("Solution not possible\n");
	}
}

/**
* Starting point of the program
*/
int main() {

	// 0 means unassigned cells
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	printf("Before solving: \n");
	printGrid(grid);
	solveSudoku(grid);
	return 0;
}