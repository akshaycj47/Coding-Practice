#include <cassert>
#include <climits>
#include <algorithm>

/**
* Function that computes the number of ways coin change can be arranged
* to generate the final value
* @params {int} n - Final value to be generated using change
* @params {int} m - Number of coins remaining in the subset
* @params {array} S - Subset of coins
* @return {int} number of ways coin change can be arranged
*/
int coinChange(int n, int m, int* S) {

	// Make a lookup table
	int** L = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		L[i] = new int[m + 1];
	}

	// Initialize the lookup table
	for (int i = 0; i < m + 1; i++) {
		L[0][i] = 1;					// Only one way in which change can be arranged
	}
	for (int i = 1; i < n + 1; i++) {
		L[i][0] = 0;					// Not enough change in the subset to be used
	}

	// Start filling out the table
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {

			int x = (i - S[j - 1]) >= 0 ? L[i - S[j - 1]][j] : 0;
			int y = L[i][j - 1];
			L[i][j] = x + y;
		}
	}
	return L[n][m];
}

/**
* Starting point of the program
*/
int main() {

	int n = 4;
	int S[] = { 1, 2, 3 };
	int m = sizeof(S) / sizeof(S[0]);
	assert(coinChange(n, m, S) == 4);

	int n2 = 10;
	int S2[] = { 2, 5, 3, 6 };
	int m2 = sizeof(S2) / sizeof(S2[0]);
	assert(coinChange(n2, m2, S2) == 5);
}