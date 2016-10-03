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
* @params {int} i, j - Starting point
* @params {int} m, n - End point
* @return {int} minimum cost to move from A[i][j] to A[m][n]
*/
int minCost(int A[3][3], int i, int j, int m, int n) {

	if (i > m || j > n) {
		return INT_MAX;											// Out  of bounds
	}
	else if (i == m && j == n) {
		return A[i][j];											// We reached
	}
	return A[i][j] + minThree(minCost(A, i, j + 1, m, n),		// Right direction
		                      minCost(A, i + 1, j, m, n),		// Down direction
							  minCost(A, i + 1, j + 1, m, n)	// Diagonal direction
							  );
}

/**
* Starting point of the program
*/
int main() {

	int A[3][3] = { {1, 2, 3},
				  {4, 8, 2},
				  {1, 5, 3} };
	assert(minCost(A, 0, 0, 2, 2) == 8);
}