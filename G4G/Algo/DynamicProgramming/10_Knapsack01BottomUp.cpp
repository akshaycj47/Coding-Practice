#include <cassert>
#include <algorithm>

/**
* Function that computes the maximum value of subset of val[]
* such that sum of the weights of this subset is smaller than or equal to W.
* @params {array} wt - Array of weights
* @params {array} v - Array of values
* @params {int} n - Number of elements
* @params {int} W - Maximum weight permissible
*/
int maxValueKnapsack(int* wt, int* v, int n, int W) {

	int** K = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		K[i] = new int[W + 1];
	}

	// Initializing the first row and column with zero
	for (int i = 0; i < n + 1; i++) {
		K[i][0] = 0;
	}
	for (int i = 0; i < W + 1; i++) {
		K[0][i] = 0;
	}

	// Fill out the table
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if (wt[i - 1] <= j) {
				// Find the maximum of include and not include
				K[i][j] = std::max(v[i - 1] + K[i - 1][j - wt[i - 1]],    // Include
					               K[i - 1][j]							  // Don't include
							      );
			}
			else {
				// Can't include
				K[i][j] = K[i - 1][j];
			}
		}
	}
	return K[n][W];
}

/**
* Starting point of the program
*/
int main() {

	int wt[] = { 10, 20, 30 };
	int v[] = { 60, 100, 120 };
	int n = sizeof(wt) / sizeof(wt[0]);
	int W = 50;
	assert(maxValueKnapsack(wt, v, n, W) == 220);

	int wt2[] = { 5, 4, 6, 3 };
	int v2[] = { 10, 40, 30, 50 };
	int n2 = sizeof(wt2) / sizeof(wt2[0]);
	int W2 = 10;
	assert(maxValueKnapsack(wt2, v2, n2, W2) == 90);
}