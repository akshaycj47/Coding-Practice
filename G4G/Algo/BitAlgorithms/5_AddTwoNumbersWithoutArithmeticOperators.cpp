#include <cassert>

/**
* Function that adds two numbers without using arithmetic operators 
* like +, ++, -, --, etc.
* It must be noted that sum of two bits can be obtained using XOR (^) 
* and carry can be obtained using AND (&).
* @params {int} x - First number
* @params {int} y - Second number
* @return {int} Addition of two numbers
*/
int addWithoutArithmetic(int x, int y) {
	
	// Iterate till there is no carry
	while (y != 0) {
		// Carry now contains common set bits of x and y
		int carry = x & y;

		// Sums of bits of x and y, where at least one bit is not set
		x = x ^ y;

		// Carry is shifted by one
		y = carry << 1;
	}
	return x;
}

/**
* Function that adds two numbers without using arithmetic operators
* like +, ++, -, --, etc. in a recursive manner.
* It must be noted that sum of two bits can be obtained using XOR (^)
* and carry can be obtained using AND (&).
* @params {int} x - First number
* @params {int} y - Second number
* @return {int} Addition of two numbers
*/
int addWithoutArithmeticRecursive(int x, int y) {

	if (y == 0) {
		return x;
	}
	else {
		return addWithoutArithmeticRecursive(x ^ y, (x & y) << 1);
	}
}

/**
* Starting point of the program
*/
int main() {

	assert(addWithoutArithmetic(5, 7) == 12);
	assert(addWithoutArithmetic(13, 56) == 69);
	assert(addWithoutArithmetic(0, 4) == 4);
	assert(addWithoutArithmetic(0, 0) == 0);

	assert(addWithoutArithmeticRecursive(5, 7) == 12);
	assert(addWithoutArithmeticRecursive(13, 56) == 69);
	assert(addWithoutArithmeticRecursive(0, 4) == 4);
	assert(addWithoutArithmeticRecursive(0, 0) == 0);
}