#include <cassert>

/**
* Function that computes the number of ways that k objects can be
* chosen from among n objects
* @params {int} n
* @params {int} k
* @return {int} number of ways that k objects can be chosen from
* among n objects
*/
int binomialCoefficient(int n, int k) {

	int** M = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		M[i] = new int[k + 1];
	}

	// Initialize
	for (int i = 0; i < n + 1; i++) {
		M[i][0] = 1;
	}

	// Fill up array
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (i == j) {
				M[i][j] = 1;
			}
			else {
				M[i][j] = M[i - 1][j - 1] + M[i - 1][j];
			}
		}
	}
	return M[n][k];
}

/**
* Starting point of the program
*/
int main() {

	assert(binomialCoefficient(4, 2) == 6);
	assert(binomialCoefficient(5, 2) == 10);
}