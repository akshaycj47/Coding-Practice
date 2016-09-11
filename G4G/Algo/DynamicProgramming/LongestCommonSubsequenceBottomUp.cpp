#include <iostream>
#include <cassert>
#include <algorithm>

/**
* Function that computes the longest common subsequence in two strings
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @return {int} length of lcs for a[0..m-1] & b[0..n-1]
*/
int lcs(char* a, char* b, int m, int n) {

	// First create a 2D array to store the lookup values
	int** L = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		L[i] = new int[n + 1];
	}

	// Initialize the lookup table
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			L[i][j] = 0;
		}
	}

	// Start computing LCS using the table
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				L[i][j] = 1 + L[i - 1][j - 1];
			}
			else {
				L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
			}
		}
	}
	return L[m][n];
}

/**
* Starting point of the program
*/
int main() {

	char a[] = "AGGTAB";
	char b[] = "GXTXAYB";
	int m = strlen(a);
	int n = strlen(b);
	assert(lcs(a, b, m, n) == 4);

	char c[] = "ABCDGH";
	char d[] = "AEDFHR";
	int x = strlen(c);
	int y = strlen(d);
	assert(lcs(c, d, x, y) == 3);
}