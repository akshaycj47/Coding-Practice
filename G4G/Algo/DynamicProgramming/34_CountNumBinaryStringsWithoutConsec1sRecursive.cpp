#include <cassert>

/**
* Utility function that counts number of binary strings without
* consecutive 1s, given size of the string
* @params {int} N - Length of the string
* @params {bool} lastChar - Last character; if true, last character
* is 1; if false, last character is 0
* @return {int} Number of binary strings without consecutive 1s
*/
int numBinaryStringsWithoutConsecOnesUtil(int N, bool lastChar) {

	// Base condition
	if (N == 1) {
		return 1;
	}

	// If last character is 0, then we can either have 0 or 1 as 
	// current character
	if (lastChar == false) {
		return numBinaryStringsWithoutConsecOnesUtil(N - 1, true) + 
			   numBinaryStringsWithoutConsecOnesUtil(N - 1, false);
	}

	// If last character is 1, then we can only have 0 as current character
	if (lastChar == true) {
		return numBinaryStringsWithoutConsecOnesUtil(N - 1, false);
	}
}

/**
* Function that counts number of binary strings without 
* consecutive 1s, given size of the string
* @params {int} N - Length of the string
* @return {int} Number of binary strings without consecutive 1s
*/
int numBinaryStringsWithoutConsecOnes(int N) {

	// Last character can be 0 or 1, try for both and return the sum
	return numBinaryStringsWithoutConsecOnesUtil(N, true) + 
		   numBinaryStringsWithoutConsecOnesUtil(N, false);
}

/**
* Starting point of the program
*/
int main() {

	assert(numBinaryStringsWithoutConsecOnes(2) == 3);
	assert(numBinaryStringsWithoutConsecOnes(3) == 5);
}