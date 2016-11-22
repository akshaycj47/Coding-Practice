#include <climits>
#include <algorithm>
#include <cassert>
#include <iostream>

int accessMatrix(int** M, int n, int i, int j) {

	if (i > j) {
		return 0;
	}
	if (i >= n || j >= n) {
		return 0;
	}
	int sum = 0;
	for (int k = i; k <= j; k++)
		sum += M[k][k];
	return M[i][j] + sum;
}

/**
* Function that constructs a BST of all keys such that the total cost of all
* the searches is as small as possible
* @params {array} keys - Array of keys
* @params {array} freqs - Array of frequencies
* @params {int} n - Number of elements in BST
* @return {int} Minimum cost of searches for an optimal BST
*/
int optimalBSTCost(int* keys, int* freq, int n) {

	// First create a matrix to store the DP values
	int** M = new int*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new int[n];
	}

	// Start bottom up approach
	for (int j = 0; j < n; j++) {
		for (int i = j; i >= 0; i--) {

			// If they are equal, then just take the frequency
			if (i == j) {
				M[i][j] = freq[i];
			}

			// Compute by trying all the combinations
			else {
				int minCost = INT_MAX;
				for (int k = i; k <= j; k++) {
					int currCost = M[k][k] + accessMatrix(M, n, i, k - 1) + accessMatrix(M, n, k + 1, j);
					minCost = std::min(minCost, currCost);
				}
				M[i][j] = minCost;
			}
		}
	}

	return M[0][n - 1];
}

/**
* Starting point of the program
*/
int main() {

	int keys[] = { 10, 12, 20 };
	int freq[] = { 34, 8, 50 };
	int n = sizeof(keys) / sizeof(keys[0]);
	//std::cout << optimalBSTCost(keys, freq, n) << std::endl;
	assert(optimalBSTCost(keys, freq, n) == 142);

	int keys2[] = { 10, 12 };
	int freq2[] = { 34, 50 };
	int n2 = sizeof(keys2) / sizeof(keys[0]);
	assert(optimalBSTCost(keys2, freq2, n2) == 118);

	int keys3[] = { 10, 12, 20, 25, 30 };
	int freq3[] = { 34, 8, 50, 25, 20 };
	int n3 = sizeof(keys3) / sizeof(keys3[0]);
	assert(optimalBSTCost(keys3, freq3, n3) == 252);

	int keys4[] = { 10, 12, 20, 25, 30, 40, 50, 60, 80, 100 };
	int freq4[] = { 34, 8, 50, 25, 20, 40, 70, 60, 5, 15 };
	int n4 = sizeof(keys4) / sizeof(keys4[0]);
	assert(optimalBSTCost(keys4, freq4, n4) == 809);
}