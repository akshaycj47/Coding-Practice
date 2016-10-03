#include <iostream>
#include <cassert>
#include <algorithm>

/**
* Function that finds the minimum of the three integers
* @params {int} a - First number
* @params {int} b - Second number
* @params {int} c - Third number
*/
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

	// If the first string length is 0, we have to insert all the characters of 
	// second string into the first string, so we return the length of second string
	if (m == 0) {
		return n;
	}
	// If the second string length is 0, we have to remove all the characters of 
	// first string, so we return the length of first string
	if (n == 0) {
		return m;
	}

	// If last two characters of the string are same, we just move to the previous characters
	if (a[m - 1] == b[n - 1]) {
		return editDistance(a, b, m - 1, n - 1);
	}

	// If last two characters of the string are not the same, just add / remove / replace the
	// character and find the minimum of them
	return 1 + minThree(editDistance(a, b, m, n - 1),		// insert
						editDistance(a, b, m - 1, n),		// delete
						editDistance(a, b, m - 1, n - 1)	// replace
						);
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