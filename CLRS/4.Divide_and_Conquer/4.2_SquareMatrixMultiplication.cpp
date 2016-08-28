// Simple square matrix multiplication
// CLRS page 76

#include <iostream>
#include <cassert>

/**
 * Function which performs square matrix multiplication
 * @params {2d array} A - The first matrix to be multiplied
 * @params {2d array} B - The second matrix to be multiplied
 * @params {2d array} C - The resultant matrix after multiplication
 * @params {int} n - The number of rows / columns
 */
void squareMatrixMultiplication(int A[3][3], int B[3][3], int C[3][3], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	int A[3][3] = { {1, 2, 3},
                    {4, 5, 6},
					{7, 8, 9} };
	int B[3][3] = { {9, 8, 7},
                    {6, 5, 4},
					{3, 2, 1} };
	int C[3][3] = { {0, 0, 0},
                    {0, 0, 0},
					{0, 0, 0} };
	int n = 3;
	squareMatrixMultiplication(A, B, C, n);
	int D[3][3] = { {30, 24, 18},
                    {84, 69, 54},
					{138, 114, 90} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			assert(C[i][j] == D[i][j]);
			std::cout << C[i][j] << " ";
		}
		std::cout << std::endl;
	}
}