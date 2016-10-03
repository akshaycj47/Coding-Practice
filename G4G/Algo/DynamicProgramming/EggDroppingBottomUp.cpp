#include <cassert>
#include <climits>
#include <algorithm>
#include <iostream>
#define INVALID -1

/**
* Function that computes the minimum number of trials required to
* find the floor (critical floor) where the eggs start breaking
* @params {int} n - Number of eggs
* @params {int} k - Number of floors
* @return {int} minimum number of trials to find critical floor
*/
int eggDropping(int n, int k) {

	// First check the failing test cases
	if (n < 0) {
		return INVALID;
	}
	if (n == 0 && k > 0) {
		return INVALID;
	}

	// First create a matrix to store tabulation values
	int** M = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		M[i] = new int[k + 1];
	}

	// Fill out the initial values
	for (int i = 0; i < k + 1; i++) {
		M[1][i] = i;
	}
	for (int i = 0; i < n + 1; i++) {
		M[i][0] = 0;
		M[i][1] = 1;
	}

	// Fill out the values
	for (int i = 2; i < n + 1; i++) {
		for (int j = 2; j < k + 1; j++) {

			int minDrops = INT_MAX;
			for (int f = 1; f <= j; f++) {
				int curr = std::max(M[i - 1][f - 1], M[i][j - f]);
				minDrops = std::min(minDrops, curr);
			}
			M[i][j] = 1 + minDrops;
		}
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			std::cout << M[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return M[n][k];
}

/**
* Starting point of the program
*/
int main() {

	assert(eggDropping(2, 10) == 4);
	/*assert(eggDropping(2, 18) == 6);
	assert(eggDropping(0, 5) == INVALID);
	assert(eggDropping(-1, 0) == INVALID);
	assert(eggDropping(1, 10000) == 10000);
	assert(eggDropping(56, 1) == 1);
	assert(eggDropping(2, 36) == 8);*/
}