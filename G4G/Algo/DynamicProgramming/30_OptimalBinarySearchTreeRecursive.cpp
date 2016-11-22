#include <climits>
#include <algorithm>
#include <cassert>

/**
* Function that constructs a BST of all keys such that the total cost of all
* the searches is as small as possible
* @params {array} keys - Array of keys
* @params {array} freqs - Array of frequencies
* @params {int} level - Level of BST that is to be multiplied with frequency to 
* get the cost, initially 1
* @params {int} x - Left bound of the array, initially 0
* @params {int} y - Right boung of the array, initially 'n - 1'
* @return {int} Minimum cost of searches for an optimal BST
*/
int optimalBSTCost(int* keys, int* freq, int level, int x, int y) {

	// Base case
	if (x > y) {
		return 0;
	}

	// Find out the optimal root for a given level
	int minCost = INT_MAX;
	for (int i = x; i <= y; i++) {

		int currCost = freq[i] * level + 
					   optimalBSTCost(keys, freq, level + 1, x, i - 1) +		// Optimal cost for left subtree
					   optimalBSTCost(keys, freq, level + 1, i + 1, y);			// Optimal cost for right subtree
		minCost = std::min(minCost, currCost);
	}
	return minCost;
}

/**
* Starting point of the program
*/
int main() {

	int keys[] = { 10, 12, 20 };
	int freq[] = { 34, 8, 50 };
	int n = sizeof(keys) / sizeof(keys[0]);
	assert(optimalBSTCost(keys, freq, 1, 0, n - 1) == 142);

	int keys2[] = { 10, 12 };
	int freq2[] = { 34, 50 };
	int n2 = sizeof(keys2) / sizeof(keys[0]);
	assert(optimalBSTCost(keys2, freq2, 1, 0, n2 - 1) == 118);
}