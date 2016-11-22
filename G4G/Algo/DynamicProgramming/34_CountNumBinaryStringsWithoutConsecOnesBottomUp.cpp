#include <cassert>

/**
* Function that counts number of binary strings without
* consecutive 1s, given size of the string
* @params {int} N - Length of the string
* @return {int} Number of binary strings without consecutive 1s
*/
int numBinaryStringsWithoutConsecOnes(int N) {

	// Create two arrays to store the DP values
	// Let a[i] be the number of binary strings of length i which do not contain
	// any consecutive 1s and which ends in 0. Similarly, let b[i] be the number
	// of such strings which end in 1
	int* a = new int[N + 1];
	int* b = new int[N + 1];
	
	// Initalization. If N == 0, no strings can be formed
	// If N == 0, only one string can be formed
	a[0] = 0;
	b[0] = 0;
	a[1] = 1;
	b[1] = 1;

	// Start computing using DP. We can either append 0 or 1 to a string ending
	// in 0, but we can only append 0 to a string ending in 1
	for (int i = 2; i <= N; i++) {
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1];
	}

	return a[N] + b[N];
}

/**
* Starting point of the program
*/
int main() {

	assert(numBinaryStringsWithoutConsecOnes(2) == 3);
	assert(numBinaryStringsWithoutConsecOnes(3) == 5);
}