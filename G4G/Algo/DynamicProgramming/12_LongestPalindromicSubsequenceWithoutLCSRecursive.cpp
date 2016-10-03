#include <cassert>
#include <cstring>
#include <algorithm>


/**
* Function that calculates longest palindromic subsequence for a string
* @params {cstring} c - Input string
* @params {int} m - First character of the string
* @params {int} n - Last character of the string
* @return {int} Longest palindromic subsequence for the string
*/
int longestPalindromicSubsequence(char* c, int m, int n) {

	// Means we have performed crossover / invalid string
	if (m > n) {
		return 0;
	}

	// Only one element left, so that is the palindromic subsequence
	else if (m == n) {
		return 1;
	}

	// If the first and last element are same, then both get included in the
	// palindromic subsequence, add both to the result and remove those characters
	else if (c[m] == c[n]) {
		return 2 + longestPalindromicSubsequence(c, m + 1, n - 1);
	}

	// If the first and last element are not the same, then find the max result by
	// removing first element and second element individually
	else {
		return std::max(longestPalindromicSubsequence(c, m + 1, n),     // Remove first element
						longestPalindromicSubsequence(c, m, n - 1)		// Remove last element
						);
	}
}

/**
* Starting point of the program
*/
int main() {

	char c[] = "BBABCBCAB";
	int m = strlen(c);
	assert(longestPalindromicSubsequence(c, 0, m - 1) == 7);

	char c2[] = "GEEKSFORGEEKS";
	int m2 = strlen(c2);
	assert(longestPalindromicSubsequence(c2, 0, m2 - 1) == 5);

	char c3[] = "GEEKS FOR GEEKS";
	int m3 = strlen(c3);
	assert(longestPalindromicSubsequence(c3, 0, m3 - 1) == 7);
}