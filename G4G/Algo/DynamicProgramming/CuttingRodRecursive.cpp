#include <cassert>
#include <algorithm>

/**
* Function that calculates maximum obtainable value after cutting the rod
* @params {array} l - Array of lengths (1..n)
* @params {array} p - Array of prices
* @params {int} n - Size of array
* @params {int} L - Maximum length of the rod
* @return {int} Maximum obtainable value after cutting the rod
*/
int cutRodMaxValue(int* l, int* p, int n, int L) {

	// If there are no lengths present, return 0
	if (n <= 0) {
		return 0;
	}

	// If current length is less than maximum length, we cannot use this length
	else if (l[n - 1] > L) {
		return cutRodMaxValue(l, p, n - 1, L);
	}

	// Otherwise we have to either select this length, or not select it
	// Find the maximum and return it
	else {
		return std::max(p[n - 1] + cutRodMaxValue(l, p, n, L - l[n - 1]),			// Select this length
						cutRodMaxValue(l, p, n - 1, L)								// Don't select this length
						);
	}
}

/**
* Function that calculates maximum obtainable value after cutting the rod
* This time, we attempt to do it without passing the length array
* @params {array} p - Array of prices
* @params {int} n - Size of array / Current length
* @params {int} L - Maximum length of the rod
* @return {int} Maximum obtainable value after cutting the rod
*/
int cutRodMaxValue2(int* p, int n, int L) {

	// If the current length is less than or equal to 0, return 0
	if (n <= 0) {
		return 0;
	}

	// If current length exceeds maximum length of the rod, we need to discard this length
	else if (n > L) {
		return cutRodMaxValue2(p, n - 1, L);
	}

	// If current length is less than maximum length of the rod, we can either
	// include that length in the solution or not
	// Try both, and return max
	else {
		return std::max(p[n - 1] + cutRodMaxValue2(p, n, L - n),		// Select this length
						cutRodMaxValue2(p, n - 1, L)					// Don't select this length
						);
	}
}

/**
* Starting point of the program
*/
int main() {

	int l[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int p[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = sizeof(p) / sizeof(p[0]);
	assert(cutRodMaxValue(l, p, n, 8) == 22);

	int l2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int p2[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n2 = sizeof(p2) / sizeof(p2[0]);
	assert(cutRodMaxValue(l2, p2, n2, 8) == 24);

	int p3[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n3 = sizeof(p3) / sizeof(p3[0]);
	assert(cutRodMaxValue2(p3, n3, 8) == 22);

	int p4[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n4 = sizeof(p4) / sizeof(p4[0]);
	assert(cutRodMaxValue2(p4, n4, 8) == 24);

	int p5[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n5 = sizeof(p5) / sizeof(p5[0]);
	assert(cutRodMaxValue2(p5, n5, -5) == 0);
}