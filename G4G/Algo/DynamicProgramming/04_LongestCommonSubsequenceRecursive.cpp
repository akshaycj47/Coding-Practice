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

	// Base condition, when either of the string's length is 0
	if (m == 0 || n == 0) {
		return 0;
	}
	// If the final characters in both strings are same
	if (a[m - 1] == b[n - 1]) {
		return 1 + lcs(a, b, m - 1, n - 1);
	}
	// If final characters are not the same
	else {
		return std::max(lcs(a, b, m - 1, n), lcs(a, b, m, n - 1));
	}
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