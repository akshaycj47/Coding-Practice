#include <cstdio>
#define N 9
#define UNASSIGNED 0

void printGrid(int grid[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool numPresentRow(int grid[N][N], int row, int col, int num) {

	for (int j = 0; j < N; j++) {
		if (grid[row][j] == num) {
			return true;
		}
	}
	return false;
}

bool numPresentCol(int grid[N][N], int row, int col, int num) {

	for (int i = 0; i < N; i++) {
		if (grid[i][col] == num) {
			return true;
		}
	}
	return false;
}

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

bool isSafeMove(int grid[N][N], int row, int col, int num) {

	// Check if number is present in current row, current column, or current subgrid
	if (numPresentRow(grid, row, col, num) || numPresentCol(grid, row, col, num) || numPresentSubGrid(grid, row, col, row - row%3, col - col%3, num)) {
		return false;
	}
	return true;
}

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

void solveSudoku(int grid[N][N]) {

	if (solveSudokuUtil(grid)) {
		printf("Solved Sudoku\n");
		printGrid(grid);
	}
	else {
		printf("Solution not possible\n");
	}
}

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