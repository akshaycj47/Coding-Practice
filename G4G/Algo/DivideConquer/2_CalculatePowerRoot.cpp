#include <cassert>
#include <iostream>

/**
* Function which calculates x to the power n
* @params {int} x - Given number
* @params {int} n - Power
* @return {int} x to the power n
*/
int powerUtil(int x, int n) {

	// 0 to the power anything is 0
	if (x == 0) {
		return 0;
	}

	// Anything to the power 1 is anything
	if (n == 1) {
		return x;
	}

	// Else, perform divide and conquer
	// Divisible by 2
	if (n % 2 == 0) {
		return powerUtil(x, n / 2) * powerUtil(x, n / 2);
	}

	// Not divisible by 2
	else if (n % 2 != 0) {
		return powerUtil(x, n / 2 + 1) * powerUtil(x, n / 2);
	}
}

/**
* Function which calculates x to the power n.
* This function works for negative x and n too
* @params {int} x - Given number
* @params {int} n - Power
* @return {float} x to the power n
*/
float power(int x, int n) {

	if (n >= 0) {
		return powerUtil(x, n);
	}
	else {
		return 1.0 / powerUtil(x, -1 * n);
	}
}

/**
* Starting point of the program
*/
int main() {

	assert(power(2, 4) == 16);
	assert(power(3, 3) == 27);
	assert(power(15, 5) == 759375);
	assert(power(7, 9) == 40353607);
	assert(power(-2, 3) == -8);
	assert(power(2, -3) == 0.125);
	assert(power(4, -4) == 0.00390625);
}