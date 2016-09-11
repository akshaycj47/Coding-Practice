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

	if (n == 0) {
		return 1;					// Only one way in which change can be arranged
	}
	else if (n < 0) {
		return 0;					// No way change can be arranged
	}
	else if (n > 0 && m == 0) {
		return 0;					// Not enough change in the subset to be used
	}
	else {
		// coinChange(include last change in subset) + coinChange(not include last change in subset)
		return coinChange(n - S[m - 1], m, S) + coinChange(n, m - 1, S);
	}
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