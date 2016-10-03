#include <cassert>
#include <climits>
#include <algorithm>

/**
* Function that finds the minimum of the three integers
* @params {int} a - First number
* @params {int} b - Second number
* @params {int} c - Third number
*/
int minThree(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}

/**
* Function that computes the minimum cost to move from location 
* A[i][j] to location A[m][n]
* @params {matrix} A - 2d array in which we have to calculate min cost
* @params {int} m, n - Dimensions of matrix
* @return {int} minimum cost to move from A[i][j] to A[m][n]
*/
int minCost(int A[3][3], int m, int n) {

	// First create a lookup table
	int** L = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		L[i] = new int[n + 1];
	}

	// Initialize the lookup table
	for (int i = 0; i < m + 1; i++) {
		L[i][0] = INT_MAX;
	}
	for (int j = 0; j < n + 1; j++) {
		L[0][j] = INT_MAX;
	}

	// Start filling out the table
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i - 1 == 0 && j - 1 == 0) {
				L[i][j] = A[i - 1][j - 1];
			}
			else {
				L[i][j] = A[i - 1][j - 1] + minThree(L[i][j - 1],			// Left
													 L[i - 1][j],			// Up
													 L[i - 1][j - 1]		// Diagonal
													 );
			}
		}
	}
	return L[m][n];
}

/**
* Starting point of the program
*/
int main() {

	int A[3][3] = { {1, 2, 3},
				  {4, 8, 2},
				  {1, 5, 3} };
	assert(minCost(A, 3, 3) == 8);
}