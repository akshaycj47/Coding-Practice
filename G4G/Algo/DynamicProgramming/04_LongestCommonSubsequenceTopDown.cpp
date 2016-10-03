#include <iostream>
#include <cassert>
#include <algorithm>

#define NIL -1

/**
* Function that initializes the lookup table
* @params {2d array} lookup - Lookup table
* @params {int} m, n - Dimensions of lookup table
*/
void initializeLookup(int** lookup, int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				lookup[i][j] = 0;
			}
			else {
				lookup[i][j] = NIL;
			}
		}
	}
}

/**
* Function that computes the longest common subsequence in two strings
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @return {int} length of lcs for a[0..m-1] & b[0..n-1]
*/
int lcs(char* a, char* b, int m, int n, int** lookup) {

	// First check the lookup table
	if (lookup[m][n] != NIL) {
		return lookup[m][n];
	}
	
	int lcsLength = 0;
	// If the final characters in both strings are same
	if (a[m - 1] == b[n - 1]) {
		lcsLength =  1 + lcs(a, b, m - 1, n - 1, lookup);
	}
	// If final characters are not the same
	else {
		lcsLength = std::max(lcs(a, b, m - 1, n, lookup), lcs(a, b, m, n - 1, lookup));
	}
	// Fill up the lookup table
	lookup[m][n] = lcsLength;
	return lookup[m][n];
}

/**
* Wrapper function that computes the longest common subsequence in two strings
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @return {int} length of lcs
*/
int lcsWrapper(char* a, char* b, int m, int n) {

	int** lookup = new int*[m+1];
	for (int i = 0; i < m+1; i++) {
		lookup[i] = new int[n+1];
	}
	initializeLookup(lookup, m+1, n+1);
	return lcs(a, b, m, n, lookup);
}

/**
* Starting point of the program
*/
int main() {

	char a[] = "AGGTAB";
	char b[] = "GXTXAYB";
	int m = strlen(a);
	int n = strlen(b);
	assert(lcsWrapper(a, b, m, n) == 4);

	char c[] = "ABCDGH";
	char d[] = "AEDFHR";
	int x = strlen(c);
	int y = strlen(d);
	assert(lcsWrapper(c, d, x, y) == 3);
}