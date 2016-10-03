#include <cassert>
#include <climits>
#include <algorithm>

#define NIL - 1

/**
* Function that initializes the lookup table
* @params {2d array pointer} lookup - 2d array pointer to the lookup table
* @params {int} x, y - Dimensions of lookup table
*/
void initialize(int** lookup, int x, int y) {

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			lookup[i][j] = NIL;
		}
	}
}

/**
* Function that queries the lookup table
* @params {2d array pointer} lookup - 2d array pointer to the lookup table
* @params {int} x, y - Query coordinates
*/
int checkLookup(int** lookup, int x, int y) {
	if (x < 0 || y < 0) {
		return NIL;
	}
	return lookup[x][y];
}

/**
* Function that updates the values on the lookup table
* @params {2d array pointer} lookup - 2d array pointer to the lookup table
* @params {int} x, y - Update coordinates
*/
void updateLookup(int** lookup, int x, int y, int value) {
	if (x < 0 || y < 0) {
		return;
	}
	lookup[x][y] = value;
}

/**
* Function that computes the number of ways coin change can be arranged
* to generate the final value
* @params {int} n - Final value to be generated using change
* @params {int} m - Number of coins remaining in the subset
* @params {array} S - Subset of coins
* @return {int} number of ways coin change can be arranged
*/
int coinChange(int n, int m, int* S, int** lookup) {

	if (checkLookup(lookup, n, m) != NIL) {
		return lookup[n][m];
	}
	int value;
	if (n == 0) {
		value = 1;					// Only one way in which change can be arranged
	}
	else if (n < 0) {
		value = 0;					// No way change can be arranged
	}
	else if (n > 0 && m == 0) {
		value = 0;					// Not enough change in the subset to be used
	}
	else {
		// coinChange(include last change in subset) + coinChange(not include last change in subset)
		value = coinChange(n - S[m - 1], m, S, lookup) + coinChange(n, m - 1, S, lookup);
	}
	updateLookup(lookup, n, m, value);
	return value;
}

/**
* Wrapper function that computes the number of ways coin change can be arranged
* to generate the final value
* @params {int} n - Final value to be generated using change
* @params {int} m - Number of coins remaining in the subset
* @params {array} S - Subset of coins
* @return {int} number of ways coin change can be arranged
*/
int coinChangeWrapper(int n, int m, int* S) {

	int** lookup = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		lookup[i] = new int[m + 1];
	}
	initialize(lookup, n + 1, m + 1);
	return coinChange(n, m, S, lookup);
}

/**
* Starting point of the program
*/
int main() {

	int n = 4;
	int S[] = { 1, 2, 3 };
	int m = sizeof(S) / sizeof(S[0]);
	assert(coinChangeWrapper(n, m, S) == 4);

	int n2 = 10;
	int S2[] = { 2, 5, 3, 6 };
	int m2 = sizeof(S2) / sizeof(S2[0]);
	assert(coinChangeWrapper(n2, m2, S2) == 5);
}