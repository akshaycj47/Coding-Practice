#include <iostream>
#include <cassert>
#include <algorithm>

int minThree(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}

/**
* Function that computes the minimum edit distance for two string
* We will perform all operations on the first string
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @return {int} minimum edit distance for a[0..m-1] & b[0..n-1]
*/
int editDistance(char* a, char* b, int m, int n) {

	// Create a lookup table
	int** L = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		L[i] = new int[n + 1];
	}

	// Initialize the lookup table
	for (int i = 0; i < m + 1; i++) {
		L[i][0] = i;
	}
	for (int j = 0; j < n + 1; j++) {
		L[0][j] = j;
	}

	// Start computing the minimum edit distance
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {

			if (a[i - 1] == b[j - 1]) {
				L[i][j] = L[i - 1][j - 1];				// When both are same
			}
			else {
				L[i][j] = 1 + minThree(L[i][j - 1],			// Insert
									   L[i - 1][j],			// Delete
									   L[i - 1][j - 1]		// Replace
									   );
			}
		}
	}
	return L[m][n];
}

/**
* Starting point of the program
*/
int main() {

	char a[] = "saturday";
	char b[] = "sunday";
	int m = strlen(a);
	int n = strlen(b);
	assert(editDistance(a, b, m, n) == 3);

	char c[] = "geek";
	char d[] = "gesek";
	int x = strlen(c);
	int y = strlen(d);
	assert(editDistance(c, d, x, y) == 1);
}