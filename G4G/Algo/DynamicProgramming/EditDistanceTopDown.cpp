#include <iostream>
#include <cassert>
#include <algorithm>
#include <climits>

#define NIL -1

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
* Function that initializes the lookup table
* @params {2d array pointer} lookup - 2d array pointer to the lookup table
* @params {int} x, y - Dimensions of lookup table
*/
void initializeLookup(int** lookup, int x, int y) {

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i == 0 && j == 0) {
				lookup[i][j] = 0;
			}
			else if (i == 0 && j != 0) {
				lookup[i][j] = j;
			}
			else if (i != 0 && j == 0) {
				lookup[i][j] = i;
			}
			else {
				lookup[i][j] = NIL;
			}
		}
	}
}

/**
* Function that computes the minimum edit distance for two string
* We will perform all operations on the first string
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @params {2d array pointer} - Lookup table
* @return {int} minimum edit distance for a[0..m-1] & b[0..n-1]
*/
int editDistance(char* a, char* b, int m, int n, int** lookup) {

	// First check the lookup table
	if (lookup[m][n] != NIL) {
		return lookup[m][n];
	}

	int dist;
	// If last two characters of the string are same, we just move to the previous characters
	if (a[m - 1] == b[n - 1]) {
		dist =  editDistance(a, b, m - 1, n - 1, lookup);
	}

	// If last two characters of the string are not the same, just add / remove / replace the
	// character and find the minimum of them
	else {
		dist = 1 + minThree(editDistance(a, b, m, n - 1, lookup),		// insert
							editDistance(a, b, m - 1, n, lookup),		// delete
							editDistance(a, b, m - 1, n - 1, lookup)	// replace
							);
	}
	
	lookup[m][n] = dist;
	return lookup[m][n];
}

/**
* Wrapper function that computes the minimum edit distance for two string
* We will perform all operations on the first string
* @params {cstring} a - First string
* @params {cstring} b - Second string
* @params {int} m - Length of first string
* @params {int} n - Length of second string
* @return {int} minimum edit distance for a[0..m-1] & b[0..n-1]
*/
int editDistanceWrapper(char* a, char* b, int m, int n) {

	int** lookup = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		lookup[i] = new int[n + 1];
	}
	initializeLookup(lookup, m + 1, n + 1);
	return editDistance(a, b, m, n, lookup);
}

/**
* Starting point of the program
*/
int main() {

	char a[] = "saturday";
	char b[] = "sunday";
	int m = strlen(a);
	int n = strlen(b);
	assert(editDistanceWrapper(a, b, m, n) == 3);

	char c[] = "geek";
	char d[] = "gesek";
	int x = strlen(c);
	int y = strlen(d);
	assert(editDistanceWrapper(c, d, x, y) == 1);
}