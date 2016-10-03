#include <cassert>
#include <cstring>
#include <algorithm>


/**
* Function that calculates longest palindromic subsequence for a string
* @params {cstring} c - Input string
* @params {int} n - Size of the string
* @return {int} Longest palindromic subsequence for the string
*/
int longestPalindromicSubsequence(char* c, int n) {

	// First create the matrix to store the tabular values
	int** M = new int*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new int[n];
	}

	// Start initialization. If there is a crossover (i > j) then we 
	// return 0, and if size of string is 1 (i == j), there is only
	// one possible subsequence
	// We use the trick to only update the matrix values that will 
	// be used in the computation ahead
	for (int i = 0; i < n; i++) {
		M[i][i] = 1;						// Crossover case
	}
	for (int i = 1; i < n; i++) {
		M[i][i - 1] = 0;					// Size of string 1 case
	}

	// Start filling out the matrix
	// We iterate along columns instead of rows. In the individual columns,
	// we iterate along rows from bottom to top.
	for (int j = 1; j < n; j++) {
		for (int i = j - 1; i >= 0; i--) {

			// Case when the first and the last element are the same
			if (c[i] == c[j]) {
				M[i][j] = 2 + M[i + 1][j - 1];
			}
			// Case when first and last element are not the same
			// We find the maximum after removing from front and back
			// individually
			else {
				M[i][j] = std::max(M[i + 1][j],				// When we remove from front
								   M[i][j - 1]				// When we remove from back
								   );
			}
		}
	}

	// Return top right element
	return M[0][n - 1];
}

/**
* Starting point of the program
*/
int main() {

	char c[] = "BBABCBCAB";
	int n = strlen(c);
	assert(longestPalindromicSubsequence(c, n) == 7);

	char c2[] = "GEEKSFORGEEKS";
	int n2 = strlen(c2);
	assert(longestPalindromicSubsequence(c2, n2) == 5);

	char c3[] = "GEEKS FOR GEEKS";
	int n3 = strlen(c3);
	assert(longestPalindromicSubsequence(c3, n3) == 7);
}