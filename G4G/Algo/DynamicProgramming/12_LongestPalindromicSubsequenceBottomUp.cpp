#include <cassert>
#include <cstring>
#include <algorithm>

/**
* Function that calculates longest common subsequence for two strings
* @params {cstring} c - String 1
* @params {cstring} d - String 2
* @params {int} m - String 1 size
* @params {int} n - String 2 size
* @return {int} Longest common subsequence for the two strings
*/
int longestCommonSubsequence(char*c, char* d, int m, int n) {

	// Create a matrix to store the tabulation values
	int** M = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		M[i] = new int[n + 1];
	}

	// Initialize the matrix for the base conditions in which if either of
	// the string is of size 0, then there is no common subsequence
	for (int i = 0; i < m + 1; i++) {
		M[i][0] = 0;
	}
	for (int i = 0; i < n + 1; i++) {
		M[0][i] = 0;
	}

	// Start filling out the matrix
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {

			// If characters are same, add 1 to the value when 
			// character is removed from both strings
			if (c[i - 1] == d[j - 1]) {
				M[i][j] = 1 + M[i - 1][j - 1];
			}
			
			// If characters are not the same, then take maximum
			// after removing from one string or second string
			else {
				M[i][j] = std::max(M[i - 1][j], M[i][j - 1]);
			}
		}
	}
	return M[m][n];
}

/**
* Function that calculates longest palindromic subsequence for a string
* @params {cstring} c - Input string
* @params {int} m - Size of the string
* @return {int} Longest palindromic subsequence for the string
*/
int longestPalindromicSubsequence(char* c, int m) {

	int n = m;
	char* d = new char[n];
	for (int i = 0; i < n; i++) {
		d[i] = c[n - i - 1];
	}
	return longestCommonSubsequence(c, d, m, n);
}

/**
* Starting point of the program
*/
int main() {

	char c[] = "BBABCBCAB";
	int m = strlen(c);
	assert(longestPalindromicSubsequence(c, m) == 7);

	char c2[] = "GEEKSFORGEEKS";
	int m2 = strlen(c2);
	assert(longestPalindromicSubsequence(c2, m2) == 5);

	char c3[] = "GEEKS FOR GEEKS";
	int m3 = strlen(c3);
	assert(longestPalindromicSubsequence(c3, m3) == 7);
}