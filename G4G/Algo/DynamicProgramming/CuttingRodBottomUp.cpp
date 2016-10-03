#include <cassert>
#include <algorithm>

/**
* Function that calculates maximum obtainable value after cutting the rod
* This time, we attempt to do it without passing the length array
* @params {array} p - Array of prices
* @params {int} n - Size of array / Current length
* @params {int} L - Maximum length of the rod
* @return {int} Maximum obtainable value after cutting the rod
*/
int cutRodMaxValue(int* p, int n, int L) {

	// First check the base conditions
	if (n <= 0 || L <= 0) {
		return 0;
	}

	// Create a matrix to store the dynamic values
	int** M = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		M[i] = new int[L + 1];
	}

	// First, initialize 0th row (since n should be greater than 0)
	// and 0th column (since length should be greater than 0) to 0
	for (int i = 0; i < n + 1; i++) {
		M[i][0] = 0;
	}
	for (int i = 0; i < L + 1; i++) {
		M[0][i] = 0;
	}

	// Start filling out the matrix
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < L + 1; j++) {

			// If current length is greater than permissible length, 
			// we have to discard that length
			if (i > j) {
				M[i][j] = M[i - 1][j];
			}
			
			// Else, we have two options, either include that length
			// or not include that length. Find for both and select max
			else {
				M[i][j] = std::max(p[i - 1] + M[i][j - i],				// Include this length
								   M[i - 1][j]							// Don't include this length
								   );
			}
		}
	}
	return M[n][L];
}

/**
* Starting point of the program
*/
int main() {

	int p3[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n3 = sizeof(p3) / sizeof(p3[0]);
	assert(cutRodMaxValue(p3, n3, 8) == 22);

	int p4[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n4 = sizeof(p4) / sizeof(p4[0]);
	assert(cutRodMaxValue(p4, n4, 8) == 24);

	int p5[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n5 = sizeof(p5) / sizeof(p5[0]);
	assert(cutRodMaxValue(p5, n5, -5) == 0);
}