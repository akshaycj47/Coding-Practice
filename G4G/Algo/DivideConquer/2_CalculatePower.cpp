#include <cassert>

/**
* Function which calculates x to the power n
* @params {int} x - Given number
* @params {int} n - Power
* @return {int} x to the power n
*/
int power(int x, int n) {

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
		return power(x, n / 2) * power(x, n / 2);
	}

	// Not divisible by 2
	else if (n % 2 != 0) {
		return power(x, n / 2 + 1) * power(x, n / 2);
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
}