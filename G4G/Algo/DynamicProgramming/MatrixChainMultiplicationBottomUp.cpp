#include <cassert>
#include <climits>
#include <algorithm>

/**
* Function that computes the minimum number of multiplications
* needed to multiply the chain
* @params {array} arr - Array containing matrix dimensions
* @params {int} i - Start index
* @params {int} j - End index
* @return {int} minimum number of multiplications needed to
* multiply the chain
*/
int matrixChangeMultiplication(int* p, int n) {

	/* For simplicity of the program, one extra row and one
	extra column are allocated in m[][].  0th row and 0th
	column of m[][] are not used */
	//int m[n][n];
	int** m = new int*[n];
	for (int z = 0; z < n; z++) {
		m[z] = new int[n];
	}

	int i, j, k, L, q;

	/* m[i,j] = Minimum number of scalar multiplications needed
	to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L<n; L++)
	{
		for (i = 1; i <= n - L; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 1, 2, 3, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(matrixChangeMultiplication(arr, n) == 30);

	int arr2[] = { 10, 30, 5, 60 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(matrixChangeMultiplication(arr2, n2) == 4500);

	int arr3[] = { 40, 20, 30, 10, 30 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(matrixChangeMultiplication(arr3, n3) == 26000);
}