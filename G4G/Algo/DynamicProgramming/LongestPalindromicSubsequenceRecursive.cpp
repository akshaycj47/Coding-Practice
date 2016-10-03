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

	// If one of the string is null, there is no common subsequence
	if (m == 0 || n == 0) {
		return 0;
	}
	
	// If the last character is same, then add 1 and compute for previous characters
	else if (c[m - 1] == d[n - 1]) {
		return 1 + longestCommonSubsequence(c, d, m - 1, n - 1);
	}

	// If last characters are not same, find lcs after removing one character from 
	// each strings in separate calculations, and return the maximum
	else {
		return std::max(longestCommonSubsequence(c, d, m - 1, n), longestCommonSubsequence(c, d, m, n - 1));
	}
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